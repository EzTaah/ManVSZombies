#include "WallManager.hpp"
#include <array>


WallManager::WallManager(const std::vector<std::vector<int>>& grid) 
    : _wallsArray()
{
    for(unsigned int i{0} ; i < grid.size() ; ++i)
    {
        for(unsigned int n{0} ; n < grid[i].size() ; ++n)
        {
            if(grid[i][n] == 1)
            {
                ut::Vector2f wallPosition = {30.0f * n, 30.0f * i};
                _wallsArray.push_back(Wall(wallPosition));
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