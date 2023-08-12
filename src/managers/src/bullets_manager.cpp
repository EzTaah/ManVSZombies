#include "bullets_manager.hpp"
#include "bullet.hpp"
#include <raylib.hpp>
#include <iostream>


BulletsManager::BulletsManager() 
{
    bulletSpeed = 10.0f;
    Bulletsize = {10.0f, 10.0f};
}


void BulletsManager::Clear()
{
    // To remove all bullets and reset the manager.
}

 
void BulletsManager::ShootNewBullet(Rectangle playerRectangle_)
{
    Vector2 bulletDirection = CalculateBulletDirection(playerRectangle_, bulletSpeed);
    bulletsArray.push_back(Bullet({playerAttributes.x, playerAttributes.y}, - bulletDirection.x, - bulletDirection.y));
}


void Bullets::Update()
{
    int n = 0;
    for (Bullet& elt : bulletsArray)
    {
        if (elt.IsOutside())
        {
            RemoveElementBulletsArray(n);
        } else {
            elt.Update();
        }
        n++;
    }
}


void Bullets::Draw() const
{
    for (const Bullet& elt : bulletsArray)
    {
        elt.Draw();
    }
}


std::vector<Bullet> Bullets::GetBulletsArray()
{
    return bulletsArray;
}


void Bullets::RemoveElementBulletsArray(int index)
{
    bulletsArray.erase(bulletsArray.begin() + index);
}


/// UTILITY FUNCTIONS //////////////////
Vector2 CalculateBulletDirection(Rectangle playerPosition, int bulletSpeed)
{
    Vector2 mousePosition = GetMousePosition();     // get a vector containing the mouse position

    float xDistancePlayerMouse = playerPosition.x - mousePosition.x;    // Calculate the x distance between the player and the mouse 
    float yDistancePlayerMouse = playerPosition.y - mousePosition.y;    // Calculate the y distance between the player and the mouse

    float coeff;
    if (xDistancePlayerMouse != 0) {
        coeff = std::abs(yDistancePlayerMouse / xDistancePlayerMouse);
    };


    // Getting the x and y speed of the bullet
    Vector2 bulletDirection;
    
    if (std::abs(xDistancePlayerMouse) > std::abs(yDistancePlayerMouse)) 
    {
        bulletDirection.x = (xDistancePlayerMouse / std::abs(xDistancePlayerMouse)) * bulletSpeed;
        bulletDirection.y = (yDistancePlayerMouse / std::abs(yDistancePlayerMouse)) * coeff * abs(bulletDirection.x);
    }
    else
    {
        bulletDirection.y = (yDistancePlayerMouse / std::abs(yDistancePlayerMouse)) * bulletSpeed;
        bulletDirection.x = (xDistancePlayerMouse / std::abs(xDistancePlayerMouse)) * 1/coeff * abs(bulletDirection.y);
    }
    return bulletDirection;
}

///////////////////