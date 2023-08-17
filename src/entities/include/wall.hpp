#pragma once 
#include <raylib.hpp>
#include <array>


class Wall
{
public:
    Wall(const Vector2& position);

    // === Accessors ===
    Vector2 GetPosition() const;
    Vector2 GetPositionInViewSpace() const;
    Rectangle GetRectangle() const;

    // === Setters ===
    void SetPosition(const Vector2& newPosition);
    void SetPositionInViewSpace(const Vector2& newPositionInViewSpace);

    // === Rendering ===
    void Render() const;

private:
    Vector2 _position;
    Vector2 _positionInViewSpace;
    Vector2 _size;
};