#include "bullets_manager.hpp"
#include "bullet.hpp"
#include <raylib.hpp>
#include <iostream>



/////////////////////
Vector2 CalculateBulletDirection(EntityAttributes position, int bulletSpeed)
{
    Vector2 mousePosition = GetMousePosition();

    // Getting the angle
    float xDistancePlayerMouse = position.x - mousePosition.x;
    float yDistancePlayerMouse = position.y - mousePosition.y; 

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



Bullets::Bullets() 
{
    bulletSpeed = 10.0;
}

void Bullets::ShootNewBullet(EntityAttributes playerAttributes)
{
    Vector2 bulletDirection = CalculateBulletDirection(playerAttributes, bulletSpeed);
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