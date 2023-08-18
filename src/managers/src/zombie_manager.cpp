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
void ZombieManager::SpawnNewZombie(const std::vector<std::vector<int>>& grid, const Vector2& numberOfTilesGrid)
{
    Vector2 spawnLocationTile;
    // which side
    switch (myUtils::GetRandomNumber(0, 3))     // Choose a random side of the screen
    {
        case 0:     
            spawnLocationTile.x = 0;    // Spawn on the left
            do {
                spawnLocationTile.y = myUtils::GetRandomNumber(0, numberOfTilesGrid.y - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;

        case 1:
            spawnLocationTile.x = numberOfTilesGrid.x - 1;    // Spawn on the right
            do {
                spawnLocationTile.y = myUtils::GetRandomNumber(0, numberOfTilesGrid.y - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;

        case 2:     
            spawnLocationTile.y = 0;    // Spawn on the top
            do {
                spawnLocationTile.x = myUtils::GetRandomNumber(0, numberOfTilesGrid.x - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;    

        case 3:     
            spawnLocationTile.y = numberOfTilesGrid.y - 1;      // Spawn on the bottom
            do {
                spawnLocationTile.x = myUtils::GetRandomNumber(0, numberOfTilesGrid.x - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;
    }
    _zombiesArray.push_back(Zombie({30.0f * spawnLocationTile.x, 30.0f * spawnLocationTile.y}));
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


// === Collision Handling ===
void ZombieManager::RevertHorizontalPositionZombie(int index) {
    _zombiesArray[index].RevertHorizontalPosition();
}

void ZombieManager::RevertVerticalPositionZombie(int index) {
    _zombiesArray[index].RevertVerticalPosition();
}