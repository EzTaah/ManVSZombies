#include "collision_manager.hpp"
#include <raylib.hpp>
#include <array>
#include <vector>
#include <iostream>


CollisionManager::CollisionManager() {}


CollisionManager::CollisionManager(std::vector<std::vector<int>> grid_) 
    : grid(grid_)
{}


bool CollisionManager::IsOutsideBoundaryX(const Rectangle& entityRectangle_)
{
    bool left = entityRectangle_.x < 0;
    bool right = entityRectangle_.x + entityRectangle_.width > 30 * grid[0].size();

    return (left || right);
}


bool CollisionManager::IsOutsideBoundaryY(const Rectangle& entityRectangle_)
{
    bool top = entityRectangle_.y < 0;
    bool bottom = entityRectangle_.y + entityRectangle_.width> 30 * grid.size();

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


std::array<std::array<myUtils::Face, 2>, 2> CollisionManager::MyGame_CheckCollisionRecs(const Rectangle& Rec1, const Rectangle& Rec2) {
    // If no collision, return NONE for both rectangles
    if (!CheckCollisionRecs(Rec1, Rec2)) {
        return {{{myUtils::Face::NONE, myUtils::Face::NONE}, {myUtils::Face::NONE, myUtils::Face::NONE}}};
    }

    // Check colliding faces for r1
    std::array<myUtils::Face, 2> Rec1CollisionFaces{myUtils::Face::NONE, myUtils::Face::NONE};
    if (Rec1.y + Rec1.height > Rec2.y && Rec1.y + Rec1.height <= Rec2.y + Rec2.height) {
        Rec1CollisionFaces[0] = myUtils::Face::BOTTOM;
    }
    if (Rec1.y < Rec2.y + Rec2.height && Rec1.y >= Rec2.y) {
        Rec1CollisionFaces[0] = myUtils::Face::TOP;
    }
    if (Rec1.x + Rec1.width > Rec2.x && Rec1.x + Rec1.width <= Rec2.x + Rec2.width) {
        Rec1CollisionFaces[1] = myUtils::Face::RIGHT;
    }
    if (Rec1.x < Rec2.x + Rec2.width && Rec1.x >= Rec2.x) {
        Rec1CollisionFaces[1] = myUtils::Face::LEFT;
    }

    // Check colliding faces for r2
    std::array<myUtils::Face, 2> Rec2CollisionFaces{myUtils::Face::NONE, myUtils::Face::NONE};
    if (Rec2.y + Rec2.height > Rec1.y && Rec2.y + Rec2.height <= Rec1.y + Rec1.height) {
        Rec2CollisionFaces[0] = myUtils::Face::BOTTOM;
    }
    if (Rec2.y < Rec1.y + Rec1.height && Rec2.y >= Rec1.y) {
        Rec2CollisionFaces[0] = myUtils::Face::TOP;
    }
    if (Rec2.x + Rec2.width > Rec1.x && Rec2.x + Rec2.width <= Rec1.x + Rec1.width) {
        Rec2CollisionFaces[1] = myUtils::Face::RIGHT;
    }
    if (Rec2.x < Rec1.x + Rec1.width && Rec2.x >= Rec1.x) {
        Rec2CollisionFaces[1] = myUtils::Face::LEFT;
    }

    return {Rec1CollisionFaces, Rec2CollisionFaces};
}