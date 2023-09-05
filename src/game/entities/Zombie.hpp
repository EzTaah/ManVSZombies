#pragma once 
#include <raylib.hpp>


class Zombie
{
public:
    Zombie(const Vector2& position);

    // === Accessors ===
    Vector2 GetPosition() const;
    Vector2 GetPositionInViewSpace() const;
    Vector2 GetPotentialMovement() const;
    Rectangle GetRectangle() const;
    Vector2 GetSpeed() const;

    // === Setters ===
    void SetPosition(const Vector2& newPosition);
    void SetPositionInViewSpace(const Vector2& newPositionInViewSpace);

    // === Movemement & Logic ===
    void CalculateNextMove(const Rectangle& playerRectangle);
    void UpdateHorizontalPosition();
    void UpdateVerticalPosition();

    // === Collision Handling ===
    void RevertHorizontalPosition();
    void RevertVerticalPosition();

    // === Rendering ===
    void Render() const;

private:
    Vector2 _position;
    Vector2 _positionInViewSpace;
    Vector2 _potentialMovement;
    Vector2 _speed;
    Vector2 _size;
};