#pragma once
#include <raylib.hpp>
#include <array>
#include <vector>


class CollisionManager
{
public:
    CollisionManager();
    bool IsOutsideScreenX(const Rectangle& entityRectangle_);
    bool IsOutsideScreenY(const Rectangle& entityRectangle_);
    bool IsOutsideScreen(const Rectangle& entityRectangle_);
    bool AreColliding(const Rectangle& entityRectangle1_, const Rectangle& entityRectangle2_);
};