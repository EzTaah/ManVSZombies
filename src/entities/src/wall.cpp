#include "wall.hpp"


Wall::Wall(const Vector2& position)
    : StaticEntity(position, {30.0f, 30.0f})    // {30.0f, 30.0f} is the size of a wall square
{}


// === Rendering ===
void Wall::Render() const
{
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, BLACK);
}