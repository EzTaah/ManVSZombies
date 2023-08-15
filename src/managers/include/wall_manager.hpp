#pragma once
#include "wall.hpp"
#include <raylib.hpp>
#include <vector>


class WallManager
{
public:
    WallManager();

    void InitWalls(const std::vector<std::vector<int>>& grid_);

    std::vector<Wall>& GetWallsArray();
    std::vector<Rectangle> GetWallsRectangle();


private:
    std::vector<Wall> wallsArray;
};