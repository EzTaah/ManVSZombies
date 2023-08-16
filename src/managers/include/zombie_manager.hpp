#pragma once
#include "zombie.hpp"
#include <raylib.hpp>
#include <vector>


class ZombieManager
{
public:
    ZombieManager();

    // Update
    void SetupPotentialMovement(const Rectangle& playerRectangle_);
    void UpdateX();
    void UpdateY();

    // Zombie Creation
    void SpawnNewZombie(Vector2 gridDimention_);


 
    // Zombies Management
    void KillZombie(int index_);

    // Information
    int GetActiveZombiesCount();
    std::vector<Zombie>& GetZombiesArray();   // Retrieve the array of all zombies currently managed by the ZombieManager.
    std::vector<Rectangle> GetZombiesRectangle();


private:
    void RemoveZombie(int index_);

    std::vector<Zombie> zombiesArray;
    float zombieSpeed;
    Vector2 zombieSize;
    double lastUpdateTimeEvent1;
};