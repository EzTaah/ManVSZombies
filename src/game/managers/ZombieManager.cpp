#include "ZombieManager.hpp"
#include <cmath>
#include <vector>
#include <memory>


ZombieManager::ZombieManager(std::vector<MovingEntity*>* movingEntitiesArrayPtr)
    : _movingEntitiesArrayPtr(movingEntitiesArrayPtr),
      _zombiesArray(),
      _lastUpdateTimeEvent1(0.0f)
{

    // Empeche le std::vector faire la réallocation de mémoire (ce qui rend tt les pointeurs invalide)
    _zombiesArray.reserve(100);
}


// === Accessors ===
std::vector<Zombie> ZombieManager::GetZombiesArray() const {
    return _zombiesArray;
}

std::vector<ut::Rectanglef> ZombieManager::GetZombiesRectangle() const
{
    std::vector<ut::Rectanglef> zombiesRectangleArray;
    for(const Zombie& zombie : _zombiesArray)
        zombiesRectangleArray.push_back(zombie.GetRectangle());
    
    return zombiesRectangleArray;
}


// === Mutators ===
void ZombieManager::SpawnNewZombie(const std::vector<std::vector<int>>& grid, const ut::Vector2f& numberOfTilesGrid)
{
    ut::Vector2f spawnLocationTile;
    // which side
    switch (ut::GetRandomNumber(0, 3))     // Choose a random side of the screen
    {
        case 0:     
            spawnLocationTile.x = 0;    // Spawn on the left
            do {
                spawnLocationTile.y = ut::GetRandomNumber(0, numberOfTilesGrid.y - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;

        case 1:
            spawnLocationTile.x = numberOfTilesGrid.x - 1;    // Spawn on the right
            do {
                spawnLocationTile.y = ut::GetRandomNumber(0, numberOfTilesGrid.y - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;

        case 2:     
            spawnLocationTile.y = 0;    // Spawn on the top
            do {
                spawnLocationTile.x = ut::GetRandomNumber(0, numberOfTilesGrid.x - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;    

        case 3:     
            spawnLocationTile.y = numberOfTilesGrid.y - 1;      // Spawn on the bottom
            do {
                spawnLocationTile.x = ut::GetRandomNumber(0, numberOfTilesGrid.x - 1); 
            } while (grid[spawnLocationTile.y][spawnLocationTile.x] == 1);   // Repeat until the location is available
            break;
    }

    // Add the zombie to the array
    _zombiesArray.push_back(Zombie({30.0f * spawnLocationTile.x, 30.0f * spawnLocationTile.y}));

    // Add the adress of the zombie instance inside the movingentities array
    _movingEntitiesArrayPtr->push_back(&_zombiesArray.back());  // Ajoute l'adresse de de la derniere instance du tableau (donc celle que l'on vient d'ajouter).
}

void ZombieManager::RemoveZombie(int index) 
{
    // Get the address of the zombie instance you want to remove
    Zombie* zombieToRemove = &_zombiesArray[index];

    // Find and remove the corresponding pointer in _movingEntitiesArrayPtr
    for (size_t i{0}; i < _movingEntitiesArrayPtr->size(); ++i) 
    {
        if ((*_movingEntitiesArrayPtr)[i] == zombieToRemove)    // zombieToRemove est un pointeur, et (*_movingEntitiesArrayPtr)[i] retourne un pointeur.
        {
            // Supprimer le pointeur correspondant du tableau _movingEntitiesArrayPtr
            _movingEntitiesArrayPtr->erase(_movingEntitiesArrayPtr->begin() + i);
            break;
        }
    }

    // remove the bullet instance from the array
    _zombiesArray.erase(_zombiesArray.begin() + index);
}

void ZombieManager::SetPositionInViewSpaceZombies(const ut::Vector2f& cameraPosition)
{
    for (Zombie& zombie : _zombiesArray)
    {
        ut::Vector2f zombiePositionInViewSpace;
        zombiePositionInViewSpace.x = zombie.GetPosition().x - cameraPosition.x;
        zombiePositionInViewSpace.y = zombie.GetPosition().y - cameraPosition.y;
        zombie.SetPositionInViewSpace(zombiePositionInViewSpace);
    }
}


// === Movemement & Logic ===
void ZombieManager::CalculateNextMoveZombies(const ut::Rectanglef& playerRectangle)
{
    for (Zombie& zombie : _zombiesArray)
        zombie.CalculateNextMove(playerRectangle);
}


// === Collision Handling ===
void ZombieManager::RevertHorizontalPositionZombie(int index) {
    _zombiesArray[index].RevertHorizontalPosition();
}

void ZombieManager::RevertVerticalPositionZombie(int index) {
    _zombiesArray[index].RevertVerticalPosition();
}