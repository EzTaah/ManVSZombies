#include "zombie_manager.hpp"
#include "zombie.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


ZombieManager::ZombieManager() {}


ZombieManager::ZombieManager(Rectangle playerRectangle_)
    : zombieSpeed({10.0f, 10.0f}), zombieSize({10.0f, 10.0f}), playerRectangle(playerRectangle_)
{}


void ZombieManager::Clear()
{
    // To remove all bullets and reset the manager.
}


void ZombieManager::SpawnNewZombie()
{
    Vector2 spawnLocation;
    // which side
    switch (myUtils::GetRandomNumber(0, 3))     // Choose a random side of the screen
    {
        case 0:
            spawnLocation.x = -30;
            spawnLocation.y = myUtils::GetRandomNumber(0, GetScreenHeight());   // Choose a random position on this side
            break;

        case 1:
            spawnLocation.x = GetScreenWidth();
            spawnLocation.y = myUtils::GetRandomNumber(0, GetScreenHeight());
            break;

        case 2:
            spawnLocation.x = myUtils::GetRandomNumber(0, GetScreenWidth());
            spawnLocation.y = -30;
            break;

        case 3:
            spawnLocation.x = myUtils::GetRandomNumber(0, GetScreenWidth());
            spawnLocation.y = GetScreenHeight();
            break;
    }

    zombiesArray.push_back(Zombie(spawnLocation, zombieSpeed, zombieSize));
}


void ZombieManager::Update()
{
    // Update zombies
    for (Zombie& elt : zombiesArray)
    {
        elt.Update(playerRectangle);
    }
}


void ZombieManager::RemoveZombie(int index_)
{
    zombiesArray.erase(zombiesArray.begin() + index_);
}


int ZombieManager::GetActiveZombiesCount()
{
    // Get the number of bullet actually on the screen
}


std::vector<Zombie> ZombieManager::GetZombiesArray()
{
    return zombiesArray;
}