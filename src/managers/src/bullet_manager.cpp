#include "bullet_manager.hpp"
#include "bullet.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


/// UTILITY FUNCTIONS //////////////////
Vector2 CalculateBulletDirection(Rectangle PlayerRectangle_, float bulletSpeed_)
{
    Vector2 mousePosition = GetMousePosition();     // get a vector containing the mouse position

    float xDistancePlayerMouse = PlayerRectangle_.x - mousePosition.x;    // Calculate the x distance between the player and the mouse 
    float yDistancePlayerMouse = PlayerRectangle_.y - mousePosition.y;    // Calculate the y distance between the player and the mouse

    float coeff;
    if (xDistancePlayerMouse != 0) {
        coeff = abs(yDistancePlayerMouse / xDistancePlayerMouse);
    };


    // Getting the x and y speed of the bullet
    Vector2 bulletDirection;
    
    if (abs(xDistancePlayerMouse) > abs(yDistancePlayerMouse)) 
    {
        bulletDirection.x = (xDistancePlayerMouse / abs(xDistancePlayerMouse)) * bulletSpeed_;
        bulletDirection.y = (yDistancePlayerMouse / abs(yDistancePlayerMouse)) * coeff * abs(bulletDirection.x);
    }
    else
    {
        bulletDirection.y = (yDistancePlayerMouse / abs(yDistancePlayerMouse)) * bulletSpeed_;
        bulletDirection.x = (xDistancePlayerMouse / abs(xDistancePlayerMouse)) * 1/coeff * abs(bulletDirection.y);
    }
    return bulletDirection;
}

///////////////////////////////////////


BulletManager::BulletManager()
    : bulletSpeed(10.0f), bulletSize({10.0f, 10.0f})
{}


void BulletManager::Clear()
{
    // To remove all bullets and reset the manager.
}

 
void BulletManager::ShootNewBullet(const Rectangle& playerRectangle_)
{
    Vector2 bulletDirection = CalculateBulletDirection(playerRectangle_, bulletSpeed);
    bulletsArray.push_back(Bullet({playerRectangle_.x, playerRectangle_.y}, {- bulletDirection.x, - bulletDirection.y}, bulletSize));
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


std::vector<Bullet> BulletManager::GetBulletsArray()
{
    return bulletsArray;
}









/*
void Bullets::Draw() const
{
    for (const Bullet& elt : bulletsArray)
    {
        elt.Draw();
    }
}



std::vector<Bullet> Bullets::GetbulletsArray()
{
    return bulletsArray;
}



void Bullets::RemoveElementbulletsArray(int index)
{
    bulletsArray.erase(bulletsArray.begin() + index);
}
*/