#include "MovingEntity.hpp"


MovingEntity::MovingEntity(const ut::Vector2f& position, const ut::Vector2f& speed, const ut::Vector2f& size)
    : Entity(position, size),
      _potentialMovement({0.0f, 0.0f}),
      _speed(speed)
{}


// === Accessors ===
ut::Vector2f MovingEntity::GetPotentialMovement() const {
    return _potentialMovement;
}

ut::Vector2f MovingEntity::GetSpeed() const {
    return _speed;
}


// === Setters ===
void MovingEntity::SetPotentialMovement(const ut::Vector2f& movement) {
    _potentialMovement = movement;
}


// === Movemement & Logic ===
void MovingEntity::UpdateHorizontalPosition() {
    _position.x += _potentialMovement.x * 0.030;
}

void MovingEntity::UpdateVerticalPosition()
{
    _position.y += _potentialMovement.y * 0.030;
}


// === Collision Handling ===
void MovingEntity::RevertHorizontalPosition() {
    _position.x -= _potentialMovement.x * 0.030;
}

void MovingEntity::RevertVerticalPosition() {
    _position.y -= _potentialMovement.y * 0.010;
}
