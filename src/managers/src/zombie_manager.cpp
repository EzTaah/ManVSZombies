#include "zombie_manager.hpp"
#include "zombie.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


ZombieManager::ZombieManager() {}


ZombieManager::ZombieManager(const Rectangle& playerRectangle_)
    : zombieSpeed({10.0f, 10.0f}), zombieSize({10.0f, 10.0f}), playerRectangle(playerRectangle_), lastUpdateTimeEvent1(0.0f)
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
    // Spawn new zombies
    if (EventTriggered(1, lastUpdateTimeEvent1)) 
        SpawnNewZombie();

    // Update Zombies
    for (Zombie& elt : zombiesArray)
        elt.Update(playerRectangle);
}


void ZombieManager::KillZombie(int index_)
{
    RemoveZombie(index_);
}


int ZombieManager::GetActiveZombiesCount()
{
    // Get the number of bullet actually on the screen
}


std::vector<Zombie> ZombieManager::GetZombiesArray()
{
    return zombiesArray;
}



void ZombieManager::RemoveZombie(int index_)
{
    zombiesArray.erase(zombiesArray.begin() + index_);
}





// std::vector<Rectangle> ZombieManager::GetZombiesRectangles()
// {
//     std::vector<Rectangle> rectangleArray;
//     for(Zombie elt : zombiesArray)
//         rectangleArray.push_back(elt.GetRectangle());
// }