#include "Entity.hpp"


Entity::Entity(const ut::Vector2f& position, const ut::Vector2f& size)
    : _position(position),
      _positionInViewSpace(position),
      _size(size)
{}


// === Accessors ===
ut::Vector2f Entity::GetPosition() const {
    return _position;
}

ut::Vector2f Entity::GetPositionInViewSpace() const {
    return _positionInViewSpace;
}

ut::Rectanglef Entity::GetRectangle() const {
    return {_position.x, _position.y, _size.x, _size.y};
}


// === Setters ===
void Entity::SetPosition(const ut::Vector2f& newPosition) {
    _position = newPosition;
}

void Entity::SetPositionInViewSpace(const ut::Vector2f& newPositionInViewSpace) {
    _positionInViewSpace = newPositionInViewSpace;
}