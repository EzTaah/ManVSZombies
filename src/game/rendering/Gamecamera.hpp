#pragma once 
#include <raylib.hpp>


class GameCamera
{
public:
    GameCamera();

    // === Accessors ===
    Vector2 GetPosition();

    // === Setters ===
    void SetPosition(const Vector2& newPosition);

private:
    Vector2 _position;
};