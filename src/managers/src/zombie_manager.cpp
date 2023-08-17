#include "zombie_manager.hpp"
#include "zombie.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <cmath>
#include <vector>


ZombieManager::ZombieManager()
    : _zombiesArray(),
      _lastUpdateTimeEvent1(0.0f)
{}


// === Accessors ===
std::vector<Zombie> ZombieManager::GetZombiesArray() const {
    return _zombiesArray;
}

std::vector<Rectangle> ZombieManager::GetZombiesRectangle() const
{
    std::vector<Rectangle> zombiesRectangleArray;
    for(const Zombie& zombie : _zombiesArray)
        zombiesRectangleArray.push_back(zombie.GetRectangle());
    
    return zombiesRectangleArray;
}


// === Mutators ===
void ZombieManager::SpawnNewZombie(const Vector2& gridDimention)
{
    Vector2 spawnLocation;
    // which side
    switch (myUtils::GetRandomNumber(0, 3))     // Choose a random side of the screen
    {
        case 0:
            spawnLocation.x = -30;
            spawnLocation.y = myUtils::GetRandomNumber(0, gridDimention.y);   // Choose a random position on this side
            break;
        case 1:
            spawnLocation.x = gridDimention.x;
            spawnLocation.y = myUtils::GetRandomNumber(0, gridDimention.y);
            break;
        case 2:
            spawnLocation.x = myUtils::GetRandomNumber(0, gridDimention.x);
            spawnLocation.y = -30;
            break;
        case 3:
            spawnLocation.x = myUtils::GetRandomNumber(0, gridDimention.x);
            spawnLocation.y = gridDimention.y;
            break;
    }

    _zombiesArray.push_back(Zombie(spawnLocation));
}

void ZombieManager::RemoveZombie(int index) {
    _zombiesArray.erase(_zombiesArray.begin() + index);
}

void ZombieManager::SetPositionInViewSpaceZombies(const Vector2& cameraPosition)
{
    for (Zombie& zombie : _zombiesArray)
    {
        Vector2 zombiePositionInViewSpace;
        zombiePositionInViewSpace.x = zombie.GetPosition().x - cameraPosition.x;
        zombiePositionInViewSpace.y = zombie.GetPosition().y - cameraPosition.y;
        zombie.SetPositionInViewSpace(zombiePositionInViewSpace);
    }
}


// === Movemement & Logic ===
void ZombieManager::CalculateNextMoveZombies(const Rectangle& playerRectangle)
{
    for (Zombie& zombie : _zombiesArray)
        zombie.CalculateNextMove(playerRectangle);
}

void ZombieManager::UpdateHorizontalPositionZombies()
{
    for (Zombie& zombie : _zombiesArray)
        zombie.UpdateHorizontalPosition();
}

void ZombieManager::UpdateVerticalPositionZombies()
{
    for (Zombie& zombie : _zombiesArray)
        zombie.UpdateVerticalPosition();
}