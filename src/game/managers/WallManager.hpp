#pragma once
#include "Wall.hpp"
#include "utils.hpp"
#include <vector>


class WallManager
{
public:
    WallManager(const std::vector<std::vector<int>>& grid);

    // === Accessors ===
    std::vector<Wall> GetWallsArray() const;
    std::vector<ut::Rectanglef> GetWallsRectangle() const;

    // === Mutators ===
    void SetPositionInViewSpaceWalls(const ut::ut::Vector2f& cameraPosition);


private:
    std::vector<Wall> _wallsArray;
};