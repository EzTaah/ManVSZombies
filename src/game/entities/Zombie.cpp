#include "Zombie.hpp"
#include <cmath>


Zombie::Zombie(const Vector2& position)
    : _position(position),
      _positionInViewSpace(position),
      _potentialMovement({0.0f, 0.0f}),
      _speed({200.0f, 200.0f}),
      _size({30.0f, 30.0f})
{}


// === Utility functions ===
Vector2 DescisionMaking(const Rectangle& playerRectangle, const Rectangle& zombieRectangle);


// === Accessors ===
Vector2 Zombie::GetPosition() const {
    return _position;
}

Vector2 Zombie::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

Vector2 Zombie::GetPotentialMovement() const {
    return _potentialMovement;
}

Rectangle Zombie::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}

Vector2 Zombie::GetSpeed() const {
    return _speed;
}


// === Setters ===
void Zombie::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}

void Zombie::SetPositionInViewSpace(const Vector2& newPositionInViewSpace) {
    _positionInViewSpace = newPositionInViewSpace;
}


// === Movemement & Logic ===
void Zombie::CalculateNextMove(const Rectangle& playerRectangle)
{
    // Find the direction the zombie needs to go to reach the player
    Vector2 direction = DescisionMaking(playerRectangle, GetRectangle());

    // Calculate the delpacement the zombie will do
    _potentialMovement.x = direction.x * _speed.x;
    _potentialMovement.y = direction.y * _speed.y;
}

void Zombie::UpdateHorizontalPosition() {
    _position.x += _potentialMovement.x * GetFrameTime();
}

void Zombie::UpdateVerticalPosition() {
    _position.y += _potentialMovement.y * GetFrameTime();
}


// === Collision Handling ===
void Zombie::RevertHorizontalPosition() {
    _position.x -= _potentialMovement.x * GetFrameTime();
}

void Zombie::RevertVerticalPosition() {
    _position.y -= _potentialMovement.y * GetFrameTime();
}


// === Rendering ===
void Zombie::Render() const {
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, RED);
}


// ==================
Vector2 DescisionMaking(const Rectangle& playerRectangle, const Rectangle& zombieRectangle)
{
    // Calculate the direction based on the position of the zombie and player
    Vector2 direction = {playerRectangle.x - zombieRectangle.x, playerRectangle.y - zombieRectangle.y };

    // Normalize the direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {  // Avoid division by zero
        direction.x /= length;
        direction.y /= length;
    }

    return direction;
}