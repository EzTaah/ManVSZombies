#pragma once
#include "bullet.hpp"
#include <raylib.hpp>
#include <vector>


class BulletManager
{
public:
    BulletManager();

    // Update
    void SetupPotentialMovement();
    void UpdateX();
    void UpdateY();

    // Bullet Creation
    void ShootNewBullet(const Rectangle& playerRectangle_, const Rectangle& playerRectangleInViewSpace_);

    // Update
    void Update();

    // Bullet Management
    void RemoveBullet(int index_);

    // Information
    int GetActiveBulletsCount();
    std::vector<Bullet>& GetBulletsArray();   // Retrieve the array of all bullets currently managed by the BulletManager.
    std::vector<Rectangle> GetBulletsRectangle();


private:
    std::vector<Bullet> bulletsArray;
    float bulletSpeed;
    Vector2 bulletSize;
};