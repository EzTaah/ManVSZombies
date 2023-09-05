#pragma once
#include "Wall.hpp"
#include <raylib.hpp>
#include <vector>


class WallManager
{
public:
    WallManager(const std::vector<std::vector<int>>& grid);

    // === Accessors ===
    std::vector<Wall> GetWallsArray() const;
    std::vector<Rectangle> GetWallsRectangle() const;

    // === Mutators ===
    void SetPositionInViewSpaceWalls(const Vector2& cameraPosition);


private:
    std::vector<Wall> _wallsArray;
};