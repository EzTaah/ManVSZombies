#pragma once
#include <raylib.hpp>


class Bullet
{
public:
    Bullet(const Vector2& position, const Vector2& speed);

    // === Accessors ===
    Vector2 GetPosition() const;
    Vector2 GetPositionInViewSpace() const;
    Rectangle GetRectangle() const;

    // === Setters ===
    void SetPositionInViewSpace(const Vector2& position);

    // === Movemement & Logic ===
    void CalculateNextMove();
    void UpdateHorizontalPosition();
    void UpdateVerticalPosition();

    // === Rendering ===
    void Render() const;

private:
    Vector2 _position;
    Vector2 _positionInViewSpace;
    Vector2 _potentialMovement;
    Vector2 _speed;
    Vector2 _size;
};