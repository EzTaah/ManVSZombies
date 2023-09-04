#include "Bullet.hpp"
#include "SFML/Graphics.hpp"


Bullet::Bullet(const ut::Vector2f& position, const ut::Vector2f& speed)
    :  MovingEntity(position, speed, {7.0f, 7.0f}),      // {7.0f, 7.0f} is the size of the bullet
      _isActive(false)
{
    _shape.setFillColor(sf::Color::Green);
}


// === Accessors ===
bool Bullet::IsActive() const {
    return _isActive;
}


// === Setters ===
void Bullet::Activate() {
    _isActive = true;
}

void Bullet::Desactivate() {
    _isActive = false;
}


// === Logic ===
void Bullet::CalculateNextMove()
{
    _potentialMovement.x = _speed.x;
    _potentialMovement.y = _speed.y; 
}


// === Rendering ===
void Bullet::Render(sf::RenderWindow* windowPtr)
{
    _shape.setPosition(_position.x, _position.y);
    windowPtr->draw(_shape);
}