#include "BulletManager.hpp"
#include "Bullet.hpp"
#include <cmath>
#include <vector>
#include "SFML/Graphics.hpp"


BulletManager::BulletManager(std::vector<MovingEntity*>* movingEntitiesArrayPtr)
    : _bulletsArray(),
      _bulletSpeed(1500.0f),
      _movingEntitiesArrayPtr(movingEntitiesArrayPtr)
{
    // Empeche le std::vector faire la réallocation de mémoire (ce qui rend tt les pointeurs invalide)
    _bulletsArray.reserve(100);
}


// === Utility functions ===
ut::Vector2f CalculateBulletDirection(const ut::Rectanglef& playerRectangle, float bulletSpeed, sf::RenderWindow* windowPtr);


// === Accessors ===
std::vector<Bullet> BulletManager::GetBulletsArray() const {
    return _bulletsArray;
}

std::vector<ut::Rectanglef> BulletManager::GetBulletsRectangle() const
{
    std::vector<ut::Rectanglef> bulletsRectangleArray;
    for(const Bullet& bullet : _bulletsArray)
        bulletsRectangleArray.push_back(bullet.GetRectangle());
    
    return bulletsRectangleArray;
}


// === Mutators ===
void BulletManager::ShootNewBullet(sf::RenderWindow* windowPtr, const ut::Rectanglef& playerRectangle, const ut::Rectanglef& playerRectangleInViewSpace)
{
    // Calculate the bullet direction
    const ut::Vector2f bulletDirection = CalculateBulletDirection(playerRectangleInViewSpace, _bulletSpeed, windowPtr);

    // Add the bullet to the array
    _bulletsArray.push_back(Bullet({playerRectangle.x, playerRectangle.y}, {bulletDirection.x, bulletDirection.y}));

    // Add the adress of the bullet instance inside the movingentities array
    _movingEntitiesArrayPtr->push_back(&_bulletsArray.back());  // Ajoute l'adresse de de la derniere instance du tableau (donc celle que l'on vient d'ajouter).
}

void BulletManager::RemoveBullet(int index) 
{
    // Get the address of the bullet instance you want to remove
    Bullet* bulletToRemove = &_bulletsArray[index];

    // Find and remove the corresponding pointer in _movingEntitiesArrayPtr
    for (size_t i{0}; i < _movingEntitiesArrayPtr->size(); ++i) 
    {
        if ((*_movingEntitiesArrayPtr)[i] == bulletToRemove)    // bulletToRemove est un pointeur, et (*_movingEntitiesArrayPtr)[i] retourne un pointeur.
        {
            // Supprimer le pointeur correspondant du tableau _movingEntitiesArrayPtr
            _movingEntitiesArrayPtr->erase(_movingEntitiesArrayPtr->begin() + i);
            break;
        }
    }

    // remove the bullet instance from the array
    _bulletsArray.erase(_bulletsArray.begin() + index);
}

void BulletManager::SetPositionInViewSpaceBullets(const ut::Vector2f& cameraPosition)
{
    for (Bullet& bullet : _bulletsArray)
    {
        ut::Vector2f bulletPositionInViewSpace;
        bulletPositionInViewSpace.x = bullet.GetPosition().x - cameraPosition.x;
        bulletPositionInViewSpace.y = bullet.GetPosition().y - cameraPosition.y;
        bullet.SetPositionInViewSpace(bulletPositionInViewSpace);
    }
}


// === Movemement & Logic ===
void BulletManager::CalculateNextMoveBullets()
{
    for (Bullet& bullet : _bulletsArray)
        bullet.CalculateNextMove();
}


// ==================
ut::Vector2f CalculateBulletDirection(const ut::Rectanglef& playerRectangle, float bulletSpeed, sf::RenderWindow* windowPtr)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*windowPtr);     // get a vector containing the mouse position

    // Calculate the direction from the player to the mouse
    ut::Vector2f direction = { mousePosition.x - playerRectangle.x, mousePosition.y - playerRectangle.y };

    // Normalize the direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {  // Avoid division by zero
        direction.x /= length;
        direction.y /= length;
    }

    // Scale by bullet speed
    direction.x *= bulletSpeed;
    direction.y *= bulletSpeed;

    return direction;
}