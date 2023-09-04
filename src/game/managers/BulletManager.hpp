#pragma once
#include "Bullet.hpp"
#include "utils.hpp"
#include <vector>


class BulletManager
{
public:
    BulletManager(std::vector<MovingEntity*>* movingEntitiesArrayPtr);

    // === Accessors ===
    std::vector<Bullet> GetBulletsArray() const;
    std::vector<ut::Rectanglef> GetBulletsRectangle() const;

    // === Mutators ===
    void ShootNewBullet(sf::RenderWindow* windowPtr, const ut::Rectanglef& playerRectangle, const ut::Rectanglef& playerRectangleInViewSpace);
    void RemoveBullet(int index);
    void SetPositionInViewSpaceBullets(const ut::Vector2f& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveBullets();

private:
    std::vector<MovingEntity*>* _movingEntitiesArrayPtr;
    std::vector<Bullet> _bulletsArray;
    float _bulletSpeed;
};