#include "bullet_manager.hpp"
#include "bullet.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


BulletManager::BulletManager()
    : _bulletsArray(),
      _bulletSpeed(1500.0f)
{}


// === Utility functions ===
Vector2 CalculateBulletDirection(const Rectangle& playerRectangle, float bulletSpeed);


// === Accessors ===
std::vector<Bullet> BulletManager::GetBulletsArray() const {
    return _bulletsArray;
}

std::vector<Rectangle> BulletManager::GetBulletsRectangle() const
{
    std::vector<Rectangle> bulletsRectangleArray;
    for(const Bullet& bullet : _bulletsArray)
        bulletsRectangleArray.push_back(bullet.GetRectangle());
    
    return bulletsRectangleArray;
}


// === Mutators ===
void BulletManager::ShootNewBullet(const Rectangle& playerRectangle, const Rectangle& playerRectangleInViewSpace)
{
    const Vector2 bulletDirection = CalculateBulletDirection(playerRectangleInViewSpace, _bulletSpeed);
    _bulletsArray.push_back(Bullet({playerRectangle.x, playerRectangle.y}, {bulletDirection.x, bulletDirection.y}));
}

void BulletManager::RemoveBullet(int index) {
    _bulletsArray.erase(_bulletsArray.begin() + index);
}

void BulletManager::SetPositionInViewSpaceBullets(const Vector2& cameraPosition)
{
    for (Bullet& bullet : _bulletsArray)
    {
        Vector2 bulletPositionInViewSpace;
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
Vector2 CalculateBulletDirection(const Rectangle& playerRectangle, float bulletSpeed)
{
    Vector2 mousePosition = GetMousePosition();     // get a vector containing the mouse position

    // Calculate the direction from the player to the mouse
    Vector2 direction = { mousePosition.x - playerRectangle.x, mousePosition.y - playerRectangle.y };

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