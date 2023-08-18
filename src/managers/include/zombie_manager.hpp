#pragma once
#include "zombie.hpp"
#include <raylib.hpp>
#include <vector>
#include <memory>


class ZombieManager
{
public:
    ZombieManager();

    // === Accessors ===
    std::vector<Zombie> GetZombiesArray() const;
    std::vector<Rectangle> GetZombiesRectangle() const;

    // === Mutators ===
    void SpawnNewZombie(const std::vector<std::vector<int>>& grid, const Vector2& numberOfTilesGrid, std::vector<std::unique_ptr<MovingEntity>>& movingEntitiesArray);
    void RemoveZombie(int index);
    void SetPositionInViewSpaceZombies(const Vector2& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveZombies(const Rectangle& playerRectangle);
    void UpdateHorizontalPositionZombies();
    void UpdateVerticalPositionZombies();

    // === Collision Handling ===
    void RevertHorizontalPositionZombie(int index);
    void RevertVerticalPositionZombie(int index);

private:
    std::vector<std::unique_ptr<Zombie>&> _zombiesArray;
    double _lastUpdateTimeEvent1;
};