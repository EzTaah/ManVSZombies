#pragma once
#include "Zombie.hpp"
#include "utils.hpp"
#include <vector>
#include <memory>


class ZombieManager
{
public:
    ZombieManager();

    // === Accessors ===
    std::vector<Zombie> GetZombiesArray() const;
    std::vector<ut::Rectanglef> GetZombiesRectangle() const;

    // === Mutators ===
    void SpawnNewZombie(const std::vector<std::vector<int>>& grid, const ut::Vector2f& numberOfTilesGrid, std::vector<std::unique_ptr<MovingEntity>>& movingEntitiesArray);
    void RemoveZombie(int index);
    void SetPositionInViewSpaceZombies(const ut::Vector2f& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveZombies(const ut::Rectanglef& playerRectangle);
    void UpdateHorizontalPositionZombies();
    void UpdateVerticalPositionZombies();

    // === Collision Handling ===
    void RevertHorizontalPositionZombie(int index);
    void RevertVerticalPositionZombie(int index);

private:
    std::vector<std::unique_ptr<Zombie>&> _zombiesArray;
    double _lastUpdateTimeEvent1;
};