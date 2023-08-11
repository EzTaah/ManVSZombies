#pragma once
#include "bullet.hpp"
#include <raylib.hpp>
#include <vector>


class BulletsManager
{
public:

    // Initialization and Cleanup
    Initialize();   // To set up any initial configurations for the bullet manager.
    void Clear();    // To remove all bullets and reset the manager.

    // Bullet Creation
    void ShootNewBullet(Rectangle playerRectangle);

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
    Vector2 bulletSpeed;
    Vector2 Bulletsize;     // 10, 5
};