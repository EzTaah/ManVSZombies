#include "bullet.hpp"


Bullet::Bullet(const Vector2& position, const Vector2& speed)
    : _position(position),
      _positionInViewSpace(position),
      _potentialMovement({0.0f, 0.0f}),
      _speed(speed),
      _size({7.0f, 7.0f})
{}


// === Accessors ===
Vector2 Bullet::GetPosition() const {
    return _position;
}

Vector2 Bullet::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

Rectangle Bullet::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Setters ===
void Bullet::SetPositionInViewSpace(const Vector2& newPositionInViewSpace){
    _positionInViewSpace = newPositionInViewSpace;
}


// === Movemement & Logic ===
void Bullet::CalculateNextMove(){
    _potentialMovement.x = _speed.x;
    _potentialMovement.y = _speed.y; 
}

void Bullet::UpdateHorizontalPosition() {
    _position.x += _potentialMovement.x * GetFrameTime();
}

void Bullet::UpdateVerticalPosition() {
    _position.y += _potentialMovement.y * GetFrameTime();
}


// === Rendering ===
void Bullet::Render() const
{
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, GREEN);
}