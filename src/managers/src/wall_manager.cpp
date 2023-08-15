#include "wall_manager.hpp"
#include "wall.hpp"
#include <array>


WallManager::WallManager() {}


void WallManager::InitWalls(const std::vector<std::vector<int>>& grid_)
{
    for(unsigned int i{0} ; i < grid_.size() ; ++i)
    {
        for(unsigned int n{0} ; n < grid_[i].size() ; ++n)
        {
            if(grid_[i][n] == 1)
            {
                std::array<int, 2> gridPosition = {i, n};
                wallsArray.push_back(Wall(gridPosition));
            }
        }
    }
}


std::vector<Wall>& WallManager::GetWallsArray()
{
    return wallsArray;
}


std::vector<Rectangle> WallManager::GetWallsRectangle()
{
    std::vector<Rectangle> wallsRectangleArray;
    for(Wall& elt : wallsArray)
        wallsRectangleArray.push_back(elt.GetRectangle());
    
    return wallsRectangleArray;
}