#include "moving_entity.hpp"


MovingEntity::MovingEntity(const Vector2& position, const Vector2& speed, const Vector2& size)
    : Entity(position, size),
      _potentialMovement({0.0f, 0.0f}),
      _speed(speed)
{}


// === Accessors ===
Vector2 MovingEntity::GetPotentialMovement() const {
    return _potentialMovement;
}

Vector2 MovingEntity::GetSpeed() const {
    return _speed;
}


// === Setters ===
void MovingEntity::SetPotentialMovement(const Vector2& movement) {
    _potentialMovement = movement;
}


// === Movemement & Logic ===
void MovingEntity::UpdateHorizontalPosition() {
    _position.x += _potentialMovement.x * GetFrameTime();
}

void MovingEntity::UpdateVerticalPosition()
{
    _position.y += _potentialMovement.y * GetFrameTime();
}


// === Collision Handling ===
void MovingEntity::RevertHorizontalPosition() {
    _position.x -= _potentialMovement.x * GetFrameTime();
}

void MovingEntity::RevertVerticalPosition() {
    _position.y -= _potentialMovement.y * GetFrameTime();
}
