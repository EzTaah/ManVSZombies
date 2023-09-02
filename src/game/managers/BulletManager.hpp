#pragma once
#include "Bullet.hpp"
#include "utils.hpp"
#include <vector>


class BulletManager
{
public:
    BulletManager();

    // === Accessors ===
    std::vector<Bullet> GetBulletsArray() const;
    std::vector<ut::Rectanglef> GetBulletsRectangle() const;

    // === Mutators ===
    void ShootNewBullet(const ut::Rectanglef& playerRectangle, const ut::Rectanglef& playerRectangleInViewSpace);
    void RemoveBullet(int index);
    void SetPositionInViewSpaceBullets(const ut::Vector2f& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveBullets();
    void UpdateHorizontalPositionBullets();
    void UpdateVerticalPositionBullets();

private:
    std::vector<Bullet> _bulletsArray;
    float _bulletSpeed;
};