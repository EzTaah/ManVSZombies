#include "wall_manager.hpp"
#include "wall.hpp"
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
                Vector2 wallPosition = {30.0f * i, 30.0f * n};
                _wallsArray.push_back(Wall(wallPosition));
            }
        }
    }
}


// === Accessors ===
std::vector<Wall> WallManager::GetWallsArray() const {
    return _wallsArray;
}

std::vector<Rectangle> WallManager::GetWallsRectangle() const
{
    std::vector<Rectangle> wallsRectangleArray;
    for(const Wall& wall : _wallsArray)
        wallsRectangleArray.push_back(wall.GetRectangle());
    
    return wallsRectangleArray;
}


// === Mutators ===
void WallManager::SetPositionInViewSpaceWalls(const Vector2& cameraPosition)
{
    for (Wall& wall : _wallsArray)
    {
        Vector2 wallPositionInViewSpace;
        wallPositionInViewSpace.x = wall.GetPosition().x - cameraPosition.x;
        wallPositionInViewSpace.y = wall.GetPosition().y - cameraPosition.y;
        wall.SetPositionInViewSpace(wallPositionInViewSpace);
    }
}
