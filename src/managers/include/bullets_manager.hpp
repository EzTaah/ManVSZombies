#pragma once
#include "bullet.hpp"
#include <raylib.hpp>
#include <vector>


class BulletsManager
{
public:
    // Initialization and Cleanup
    BulletsManager();      // constructor
    void Clear();    // To remove all bullets and reset the manager.

    // Bullet Creation
    void ShootNewBullet(Rectangle playerRectangle_);

    // Update and Draw
    void Update();
    void Draw();

    // Bullet Management
    std::vector<Bullet> GetBullets();   // Retrieve the array of all bullets currently managed by the BulletManager.
    void RemoveBullet(Bullet bullet);
    void RemoveBulletsOutsideScreen();

    // Configuration
    void SetBulletSpeed(Vector2 speed);

    // Information
    int GetActiveBulletCount();


private:
    std::vector<Bullet> bulletsArray;
    float bulletSpeed;
    Vector2 Bulletsize;
};