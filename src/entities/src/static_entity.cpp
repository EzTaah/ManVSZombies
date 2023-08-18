#include "static_entity.hpp"


StaticEntity::StaticEntity(const Vector2& position, const Vector2& size)
    : _position(position),
      _positionInViewSpace(position),
      _size(size)
{}


// === Accessors ===
Vector2 StaticEntity::GetPosition() const {
    return _position;
}

Vector2 StaticEntity::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

Rectangle StaticEntity::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Setters ===
void StaticEntity::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}

void StaticEntity::SetPositionInViewSpace(const Vector2& newPositionInViewSpace) {
    _positionInViewSpace = newPositionInViewSpace;
}