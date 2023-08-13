#pragma once
#include "bullet.hpp"
#include <raylib.hpp>
#include <vector>


class BulletManager
{
public:
    // Initialization and Cleanup
    BulletManager();      // constructor
    void Clear();    // To remove all bullets and reset the manager.

    // Bullet Creation
    void ShootNewBullet(Rectangle playerRectangle_);

    // Update
    void Update();

    // Bullet Management
    void RemoveBullet(int index_);
    void RemoveBulletsOutsideScreen();

    // Information
    int GetActiveBulletsCount();
    std::vector<Bullet> GetBulletsArray();   // Retrieve the array of all bullets currently managed by the BulletManager.


private:
    std::vector<Bullet> bulletsArray;
    float bulletSpeed;
    Vector2 bulletSize;
};