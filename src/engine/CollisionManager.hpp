#pragma once
#include <raylib.hpp>


class CollisionManager
{
public:
    CollisionManager();

    // === Collisions detections methods ===
    bool AreColliding(const Rectangle& entityRectangle1, const Rectangle& entityRectangle2);
    bool IsOutsideBoundaryX(const Rectangle& entityRectangle, const float gridDimensionX);
    bool IsOutsideBoundaryY(const Rectangle& entityRectangle, const float gridDimensionX);
    bool IsOutsideBoundary(const Rectangle& entityRectangle, const Vector2& gridDimension);
};

