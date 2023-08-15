#pragma once
#include "zombie.hpp"
#include <raylib.hpp>
#include <vector>


class ZombieManager
{
public:
    // Initialization and Cleanup
    ZombieManager();
    void Clear();    // To remove all zombies and reset the manager.

    // Zombie Creation
    void SpawnNewZombie();

    // Update
    void Update(const Rectangle& playerRectangle_);

    // Zombies Management
    void KillZombie(int index_);

    // Information
    int GetActiveZombiesCount();
    std::vector<Zombie>& GetZombiesArray();   // Retrieve the array of all zombies currently managed by the ZombieManager.
    std::vector<Rectangle> GetZombiesRectangle();


private:
    void RemoveZombie(int index_);

    std::vector<Zombie> zombiesArray;
    Vector2 zombieSpeed;
    Vector2 zombieSize;
    double lastUpdateTimeEvent1;
};