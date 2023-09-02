#include "BulletManager.hpp"
#include "Bullet.hpp"
#include <cmath>
#include <vector>


BulletManager::BulletManager()
    : _bulletsArray(),
      _bulletSpeed(1500.0f)
{}


// === Utility functions ===
ut::Vector2f CalculateBulletDirection(const ut::Rectanglef& playerRectangle, float bulletSpeed);


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
void BulletManager::ShootNewBullet(const ut::Rectanglef& playerRectangle, const ut::Rectanglef& playerRectangleInViewSpace)
{
    const ut::Vector2f bulletDirection = CalculateBulletDirection(playerRectangleInViewSpace, _bulletSpeed);
    _bulletsArray.push_back(Bullet({playerRectangle.x, playerRectangle.y}, {bulletDirection.x, bulletDirection.y}));
}

void BulletManager::RemoveBullet(int index) {
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

void BulletManager::UpdateHorizontalPositionBullets()
{
    for (Bullet& bullet : _bulletsArray)
        bullet.UpdateHorizontalPosition();
}

void BulletManager::UpdateVerticalPositionBullets()
{
    for (Bullet& bullet : _bulletsArray)
        bullet.UpdateVerticalPosition();
}


// ==================
ut::Vector2f CalculateBulletDirection(const ut::Rectanglef& playerRectangle, float bulletSpeed)
{
    ut::Vector2f mousePosition = GetMousePosition();     // get a vector containing the mouse position

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