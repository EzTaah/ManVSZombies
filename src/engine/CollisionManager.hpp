#pragma once
#include "utils.hpp"


class CollisionManager
{
public:
    CollisionManager();

    // === Collisions detections methods ===
    bool AreColliding(const ut::Rectanglef& entityRectangle1, const ut::Rectanglef& entityRectangle2);
    bool IsOutsideBoundaryX(const ut::Rectanglef& entityRectangle, const float gridDimensionX);
    bool IsOutsideBoundaryY(const ut::Rectanglef& entityRectangle, const float gridDimensionX);
    bool IsOutsideBoundary(const ut::Rectanglef& entityRectangle, const ut::Vector2f& gridDimension);
};

