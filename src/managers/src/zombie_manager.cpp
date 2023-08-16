#include "zombie_manager.hpp"
#include "zombie.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


ZombieManager::ZombieManager()
    : zombieSpeed(200.0f), 
      zombieSize({30.0f, 30.0f}),
      lastUpdateTimeEvent1(0.0f)
{}


void ZombieManager::SetupPotentialMovement(const Rectangle& playerRectangle_)
{
    // Update Zombies
    for (Zombie& elt : zombiesArray)
        elt.SetupPotentialMovement(playerRectangle_);
}

 
void ZombieManager::UpdateX()
{
    for (Zombie& elt : zombiesArray)
        elt.UpdateX();
}


void ZombieManager::UpdateY()
{
    for (Zombie& elt : zombiesArray)
        elt.UpdateY();
}



void ZombieManager::SpawnNewZombie(Vector2 gridDimention_)
{
    Vector2 spawnLocation;
    // which side
    switch (myUtils::GetRandomNumber(0, 3))     // Choose a random side of the screen
    {
        case 0:
            spawnLocation.x = -30;
            spawnLocation.y = myUtils::GetRandomNumber(0, gridDimention_.y);   // Choose a random position on this side
            break;

        case 1:
            spawnLocation.x = gridDimention_.x;
            spawnLocation.y = myUtils::GetRandomNumber(0, gridDimention_.y);
            break;

        case 2:
            spawnLocation.x = myUtils::GetRandomNumber(0, gridDimention_.x);
            spawnLocation.y = -30;
            break;

        case 3:
            spawnLocation.x = myUtils::GetRandomNumber(0, gridDimention_.x);
            spawnLocation.y = gridDimention_.y;
            break;
    }

    zombiesArray.push_back(Zombie(spawnLocation, zombieSpeed, zombieSize));
}





void ZombieManager::KillZombie(int index_)
{
    RemoveZombie(index_);
}


int ZombieManager::GetActiveZombiesCount()
{
    // Get the number of bullet actually on the screen
}


std::vector<Zombie>& ZombieManager::GetZombiesArray()
{
    return zombiesArray;
}


std::vector<Rectangle> ZombieManager::GetZombiesRectangle()
{
    std::vector<Rectangle> zombiesRectangleArray;
    for(Zombie& elt : zombiesArray)
        zombiesRectangleArray.push_back(elt.GetRectangle());
    
    return zombiesRectangleArray;
}



void ZombieManager::RemoveZombie(int index_)
{
    zombiesArray.erase(zombiesArray.begin() + index_);
}