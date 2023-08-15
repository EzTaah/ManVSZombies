#pragma once
#include <raylib.hpp>
#include <array>
#include <vector>


class CollisionManager
{
public:
    CollisionManager();
    bool IsOutsideBoundaryX(const Rectangle& entityRectangle_);
    bool IsOutsideBoundaryY(const Rectangle& entityRectangle_);
    bool IsOutsideBoundary(const Rectangle& entityRectangle_);
    bool AreColliding(const Rectangle& entityRectangle1_, const Rectangle& entityRectangle2_);
};