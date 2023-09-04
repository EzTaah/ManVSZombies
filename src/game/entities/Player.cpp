#include "Player.hpp"
#include "SFML/Graphics.hpp"


Player::Player(const ut::Vector2f& position)
    : MovingEntity(position, {400.0f, 400.0f}, {30.0f, 30.0f})    // {400.0f, 400.0f} is the speed of the player, {30.0f, 30.0f} is the size of the player
{
    _shape.setFillColor(sf::Color::Green);
}

// === Accessors ===
ut::Rectanglef Player::GetRectangleInViewSpace() const {
    return {_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y};
}


// === Logic ===
void Player::CalculateNextMove() {}


// === Rendering ===
void Player::Render(sf::RenderWindow* windowPtr) {
    _shape.setPosition(_position.x, _position.y);
    windowPtr->draw(_shape);
}