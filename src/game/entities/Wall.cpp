#include "Wall.hpp"
#include "SFML/Graphics.hpp"


Wall::Wall(const ut::Vector2f& position)
    : Entity(position, {30.0f, 30.0f})    // {30.0f, 30.0f} is the size of a wall square
{
    _shape.setFillColor(sf::Color::Black);
    _shape.setPosition(_position.x, _position.y);
}


// === Rendering ===
void Wall::Render(sf::RenderWindow* windowPtr) {
    windowPtr->draw(_shape);
}