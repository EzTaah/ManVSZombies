#include "wall.hpp"


Wall::Wall(const Vector2& position)
    : _position(position),
      _positionInViewSpace(position),
      _size({30.0f, 30.0f})
{}


// === Accessors ===
Vector2 Wall::GetPosition() const {
    return _position;
}

Vector2 Wall::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

Rectangle Wall::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Setters ===
void Wall::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}

void Wall::SetPositionInViewSpace(const Vector2& newPositionInViewSpace) {
    _positionInViewSpace = newPositionInViewSpace;
}


// === Rendering ===
void Wall::Render() const {
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, BLACK);
}