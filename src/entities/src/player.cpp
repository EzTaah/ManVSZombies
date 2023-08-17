#include "player.hpp"


Player::Player(const Vector2& position) 
    : _position(position),
      _positionInViewSpace(position),
      _potentialMovement({0.0f, 0.0f}),
      _speed({0.0f, 0.0f}),
      _size({30.0f, 30.0f})
{}


// === Accessors ===
Vector2 Player::GetPosition() const {
    return _position;
}

Vector2 Player::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

Vector2 Player::GetPotentialMovement() const {
    return _potentialMovement;
}

Rectangle Player::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}

Rectangle Player::GetRectangleInViewSpace() const {
    return {_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y};
}

Vector2 Player::GetSpeed() const {
    return _speed;
}


// === Setters ===
void Player::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}

void Player::SetPositionInViewSpace(const Vector2& newPositionInViewSpace) {
    _positionInViewSpace = newPositionInViewSpace;
}

void Player::SetPotentialMovement(const Vector2& movement)
{
    _potentialMovement = movement;
}


// === Movemement & Logic ===
void Player::UpdateHorizontalPosition() {
    _position.x += _potentialMovement.x * GetFrameTime();
}

void Player::UpdateVerticalPosition() {
    _position.y += _potentialMovement.y * GetFrameTime();
}


// === Collision Handling ===
void Player::RevertHorizontalPosition() {
    _position.x -= _potentialMovement.x * GetFrameTime();
}

void Player::RevertVerticalPosition() {
    _position.y -= _potentialMovement.y * GetFrameTime();
}


// === Rendering ===
void Player::Render() const {
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, GREEN);
}