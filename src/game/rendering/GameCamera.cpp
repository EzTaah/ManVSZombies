#include "GameCamera.hpp"


GameCamera::GameCamera() 
    : _position()
{}


// === Accessors ===
Vector2 GameCamera::GetPosition() {
    return _position;
}

void GameCamera::SetPosition(const Vector2& newPosition) {
    _position = newPosition;
}