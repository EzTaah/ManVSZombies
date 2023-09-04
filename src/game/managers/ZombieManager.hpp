#pragma once
#include "Zombie.hpp"
#include "utils.hpp"
#include <vector>
#include <memory>


class ZombieManager
{
public:
    ZombieManager(std::vector<MovingEntity*>* movingEntitiesArrayPtr);

    // === Accessors ===
    std::vector<Zombie> GetZombiesArray() const;
    std::vector<ut::Rectanglef> GetZombiesRectangle() const;

    // === Mutators ===
    void SpawnNewZombie(const std::vector<std::vector<int>>& grid, const ut::Vector2f& numberOfTilesGrid);
    void RemoveZombie(int index);
    void SetPositionInViewSpaceZombies(const ut::Vector2f& cameraPosition);

    // === Movemement & Logic ===
    void CalculateNextMoveZombies(const ut::Rectanglef& playerRectangle);

    // === Collision Handling ===
    void RevertHorizontalPositionZombie(int index);
    void RevertVerticalPositionZombie(int index);

private:
    std::vector<MovingEntity*>* _movingEntitiesArrayPtr;
    std::vector<Zombie> _zombiesArray;
    double _lastUpdateTimeEvent1;
};