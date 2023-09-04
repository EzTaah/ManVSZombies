#include "WallManager.hpp"
#include <array>


WallManager::WallManager(std::vector<Entity *>* staticEntitiesArrayPtr, const std::vector<std::vector<int>>& grid) 
    : _staticEntitiesArrayPtr(staticEntitiesArrayPtr),
      _wallsArray()
{
    // Empeche le std::vector faire la réallocation de mémoire (ce qui rend tt les pointeurs invalide)
    _wallsArray.reserve(100);


    // Setup the wall array
    for(unsigned int i{0} ; i < grid.size() ; ++i)
    {
        for(unsigned int n{0} ; n < grid[i].size() ; ++n)
        {
            if(grid[i][n] == 1)
            {
                ut::Vector2f wallPosition = {30.0f * n, 30.0f * i};
                _wallsArray.push_back(Wall(wallPosition));

                // Add the adress of the bullet instance inside the movingentities array
                _staticEntitiesArrayPtr->push_back(&_wallsArray.back());  // Ajoute l'adresse de de la derniere instance du tableau (donc celle que l'on vient d'ajouter).
            }
        }
    }
}


// === Accessors ===
std::vector<Wall> WallManager::GetWallsArray() const {
    return _wallsArray;
}

std::vector<ut::Rectanglef> WallManager::GetWallsRectangle() const
{
    std::vector<ut::Rectanglef> wallsRectangleArray;
    for(const Wall& wall : _wallsArray)
        wallsRectangleArray.push_back(wall.GetRectangle());
    
    return wallsRectangleArray;
}


// === Mutators ===
void WallManager::SetPositionInViewSpaceWalls(const ut::Vector2f& cameraPosition)
{
    for (Wall& wall : _wallsArray)
    {
        ut::Vector2f wallPositionInViewSpace;
        wallPositionInViewSpace.x = wall.GetPosition().x - cameraPosition.x;
        wallPositionInViewSpace.y = wall.GetPosition().y - cameraPosition.y;
        wall.SetPositionInViewSpace(wallPositionInViewSpace);
    }
}