#include "bullet.hpp"


Bullet::Bullet(const Vector2& position, const Vector2& speed)
    : MovingEntity(position, {7.0f, 7.0f}),      // {7.0f, 7.0f} is the size of the bullet
      _isActive(false)
{
    _speed = speed;     // When we create an entity, its speed is set to zero. Here, we modify the speed value.
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
void Bullet::Render() const
{
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, GREEN);
}