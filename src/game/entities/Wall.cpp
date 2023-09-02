#include "Wall.hpp"
#include "SFML/Graphics.hpp"


Wall::Wall(const ut::Vector2f& position)
    : Entity(position, {30.0f, 30.0f})    // {30.0f, 30.0f} is the size of a wall square
{}


// === Rendering ===
void Wall::Render() const {
    // DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, BLACK);
}