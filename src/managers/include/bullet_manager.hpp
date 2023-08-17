#pragma once
#include "bullet.hpp"
#include <raylib.hpp>
#include <vector>


class BulletManager
{
public:
    BulletManager();

    // === Accessors ===
    std::vector<Bullet> GetBulletsArray() const;
    std::vector<Rectangle> GetBulletsRectangle() const;

    // === Mutators ===
    void ShootNewBullet(const Rectangle& playerRectangle, const Rectangle& playerRectangleInViewSpace);
    void RemoveBullet(int index);
    void SetPositionInViewSpaceBullets(const Vector2& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveBullets();
    void UpdateHorizontalPositionBullets();
    void UpdateVerticalPositionBullets();

private:
    std::vector<Bullet> _bulletsArray;
    float _bulletSpeed;
};