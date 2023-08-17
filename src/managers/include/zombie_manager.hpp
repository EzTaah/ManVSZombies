#pragma once
#include "zombie.hpp"
#include <raylib.hpp>
#include <vector>


class ZombieManager
{
public:
    ZombieManager();

    // === Accessors ===
    std::vector<Zombie> GetZombiesArray() const;
    std::vector<Rectangle> GetZombiesRectangle() const;

    // === Mutators ===
    void SpawnNewZombie(const Vector2& gridDimention);
    void RemoveZombie(int index);
    void SetPositionInViewSpaceZombies(const Vector2& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveZombies(const Rectangle& playerRectangle);
    void UpdateHorizontalPositionZombies();
    void UpdateVerticalPositionZombies();

private:
    std::vector<Zombie> _zombiesArray;
    double _lastUpdateTimeEvent1;
};