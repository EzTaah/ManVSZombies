#include "Entity.hpp"


Entity::Entity(const Vector2& position, const Vector2& size)
    : _position(position),
      _positionInViewSpace(position),
      _size(size)
{}


// === Accessors ===
Vector2 Entity::GetPosition() const {
    return _position;
}

Vector2 Entity::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

Rectangle Entity::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Setters ===
void Entity::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}

void Entity::SetPositionInViewSpace(const Vector2& newPositionInViewSpace) {
    _positionInViewSpace = newPositionInViewSpace;
}