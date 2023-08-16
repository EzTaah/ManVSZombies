#pragma once
#include "library.hpp"
#include <raylib.hpp>
#include <array>
#include <vector>
#include <utility>


class CollisionManager
{
public:
    CollisionManager();
    CollisionManager(std::vector<std::vector<int>> grid_);
    bool IsOutsideBoundaryX(const Rectangle& entityRectangle_);
    bool IsOutsideBoundaryY(const Rectangle& entityRectangle_);
    bool IsOutsideBoundary(const Rectangle& entityRectangle_);
    bool AreColliding(const Rectangle& entityRectangle1_, const Rectangle& entityRectangle2_);

    // CheckCollisionRecs
    std::array<std::array<myUtils::Face, 2>, 2> MyGame_CheckCollisionRecs(const Rectangle& Rec1, const Rectangle& Rec2);

private:
    std::vector<std::vector<int>> grid;
};

