#include "Camera.hpp"


Camera::Camera() 
    : _position()
{}


// === Accessors ===
ut::Vector2f Camera::GetPosition() {
    return _position;
}

void Camera::SetPosition(const ut::Vector2f& newPosition) {
    _position = newPosition;
}