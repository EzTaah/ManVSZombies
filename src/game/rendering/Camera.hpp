#pragma once 
#include <utils.hpp>


class Camera
{
public:
    Camera();

    // === Accessors ===
    ut::Vector2f GetPosition();

    // === Setters ===
    void SetPosition(const ut::Vector2f& newPosition);

private:
    ut::Vector2f _position;
};