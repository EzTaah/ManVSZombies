#include "collision_manager.hpp"
#include <raylib.hpp>


CollisionManager::CollisionManager() {}


// === Collisions detections methods ===
bool CollisionManager::AreColliding(const Rectangle& entityRectangle1, const Rectangle& entityRectangle2) {
    return CheckCollisionRecs(entityRectangle1, entityRectangle2);
}

bool CollisionManager::IsOutsideBoundaryX(const Rectangle& entityRectangle, const float gridDimensionX)
{
    bool left = entityRectangle.x < 0;
    bool right = entityRectangle.x + entityRectangle.width > gridDimensionX;

    return (left || right);
}

bool CollisionManager::IsOutsideBoundaryY(const Rectangle& entityRectangle, const float gridDimensionY)
{
    bool top = entityRectangle.y < 0;
    bool bottom = entityRectangle.y + entityRectangle.width > gridDimensionY;

    return (top || bottom);
}

bool CollisionManager::IsOutsideBoundary(const Rectangle& entityRectangle, const Vector2& gridDimension)
{
    return (IsOutsideBoundaryX(entityRectangle, gridDimension.x) || IsOutsideBoundaryY(entityRectangle, gridDimension.y));
}