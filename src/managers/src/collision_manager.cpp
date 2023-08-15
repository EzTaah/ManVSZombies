#include "collision_manager.hpp"
#include <raylib.hpp>
#include <vector>


CollisionManager::CollisionManager() {}


bool CollisionManager::IsOutsideBoundaryX(const Rectangle& entityRectangle_)
{
    bool left = entityRectangle_.x < 0;
    bool right = entityRectangle_.x > GetScreenWidth() - entityRectangle_.width;

    return (left || right);
}


bool CollisionManager::IsOutsideBoundaryY(const Rectangle& entityRectangle_)
{
    bool top = entityRectangle_.y < 0;
    bool bottom = entityRectangle_.y > GetScreenHeight() - entityRectangle_.height;

    return (top || bottom);
}


bool CollisionManager::IsOutsideBoundary(const Rectangle& entityRectangle_)
{
    return (IsOutsideBoundaryX(entityRectangle_) || IsOutsideBoundaryY(entityRectangle_));
}


bool CollisionManager::AreColliding(const Rectangle& entityRectangle1_, const Rectangle& entityRectangle2_)
{
    return CheckCollisionRecs(entityRectangle1_, entityRectangle2_);
}