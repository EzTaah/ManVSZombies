#include "CollisionManager.hpp"


CollisionManager::CollisionManager() {}


// === Collisions detections methods ===
bool CollisionManager::AreColliding(const ut::Rectanglef& entityRectangle1, const ut::Rectanglef& entityRectangle2) 
{
    // Vérifie si l'un des rectangles est à gauche de l'autre
    if (entityRectangle1.x + entityRectangle1.width < entityRectangle2.x || 
        entityRectangle2.x + entityRectangle2.width < entityRectangle1.x) {
        return false;
    }

    // Vérifie si l'un des rectangles est au-dessus de l'autre
    if (entityRectangle1.y + entityRectangle1.height < entityRectangle2.y || 
        entityRectangle2.y + entityRectangle2.height < entityRectangle1.y) {
        return false;
    }

    // Si aucun des cas ci-dessus n'est vrai, alors les rectangles se chevauchent
    return true;

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