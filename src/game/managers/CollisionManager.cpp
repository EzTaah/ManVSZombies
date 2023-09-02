#include "collision_manager.hpp"
#include <raylib.hpp>


CollisionManager::CollisionManager() {}


// === Collisions detections methods ===
bool CollisionManager::AreColliding(const ut::Rectanglef& entityRectangle1, const ut::Rectanglef& entityRectangle2) 
{

    // Create my own CheckCollisions

    return false;
}

bool CollisionManager::IsOutsideBoundaryX(const ut::Rectanglef& entityRectangle, const float gridDimensionX)
{
    bool left = entityRectangle.x < 0;
    bool right = entityRectangle.x + entityRectangle.width > gridDimensionX;

    return (left || right);
}

bool CollisionManager::IsOutsideBoundaryY(const ut::Rectanglef& entityRectangle, const float gridDimensionY)
{
    bool top = entityRectangle.y < 0;
    bool bottom = entityRectangle.y + entityRectangle.width > gridDimensionY;

    return (top || bottom);
}

bool CollisionManager::IsOutsideBoundary(const ut::Rectanglef& entityRectangle, const ut::Vector2f& gridDimension)
{
    return (IsOutsideBoundaryX(entityRectangle, gridDimension.x) || IsOutsideBoundaryY(entityRectangle, gridDimension.y));
}