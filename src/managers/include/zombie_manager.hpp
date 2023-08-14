#pragma once
#include "zombie.hpp"
#include <raylib.hpp>
#include <vector>


class ZombieManager
{
public:
    // Initialization and Cleanup
    ZombieManager();
    ZombieManager(const Rectangle& playerRectangle_);      // constructor
    void Clear();    // To remove all zombies and reset the manager.

    // Zombie Creation
    void SpawnNewZombie();

    // Update
    void Update();

    // Zombies Management
    void KillZombie(int index_);

    // Information
    int GetActiveZombiesCount();
    std::vector<Zombie> GetZombiesArray();   // Retrieve the array of all zombies currently managed by the ZombieManager.
    //std::vector<Rectangle> GetZombiesRectangles();


private:
    void RemoveZombie(int index_);

    std::vector<Zombie> zombiesArray;
    Vector2 zombieSpeed;
    Vector2 zombieSize;
    Rectangle playerRectangle;
    double lastUpdateTimeEvent1;
};