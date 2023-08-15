#include "bullet_manager.hpp"
#include "bullet.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


/// UTILITY FUNCTIONS //////////////////
Vector2 CalculateBulletDirection(const Rectangle& playerRectangle_, float bulletSpeed_)
{
    Vector2 mousePosition = GetMousePosition();     // get a vector containing the mouse position

    // Calculate the direction from the player to the mouse
    Vector2 direction = { mousePosition.x - playerRectangle_.x, mousePosition.y - playerRectangle_.y };

    // Normalize the direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {  // Avoid division by zero
        direction.x /= length;
        direction.y /= length;
    }

    // Scale by bullet speed
    direction.x *= bulletSpeed_;
    direction.y *= bulletSpeed_;

    return direction;
}

///////////////////////////////////////


BulletManager::BulletManager()
    : bulletSpeed(1500.0f), bulletSize({7.0f, 7.0f})
{}


void BulletManager::Clear()
{
    // To remove all bullets and reset the manager.
}

 
void BulletManager::ShootNewBullet(const Rectangle& playerRectangle_, const Rectangle& playerRectangleInViewSpace_)
{
    Vector2 bulletDirection = CalculateBulletDirection(playerRectangleInViewSpace_, bulletSpeed);
    bulletsArray.push_back(Bullet({playerRectangle_.x, playerRectangle_.y}, {bulletDirection.x, bulletDirection.y}, bulletSize));
}


void BulletManager::Update()
{
    // Update the bullets
    for (Bullet& elt : bulletsArray)
    {
        elt.Update();
    }
}


void BulletManager::RemoveBullet(int index_)
{
    bulletsArray.erase(bulletsArray.begin() + index_);
}


int BulletManager::GetActiveBulletsCount()
{
    // Get the number of bullet actually on the screen
}


std::vector<Bullet>& BulletManager::GetBulletsArray()
{
    return bulletsArray;
}


std::vector<Rectangle> BulletManager::GetBulletsRectangle()
{
    std::vector<Rectangle> bulletsRectangleArray;
    for(Bullet& elt : bulletsArray)
        bulletsRectangleArray.push_back(elt.GetRectangle());
    
    return bulletsRectangleArray;
}