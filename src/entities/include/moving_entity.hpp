#pragma once
#include <raylib.hpp>


class MovingEntity
{
public:
    MovingEntity(const Vector2& position, const Vector2& size);     // To create an entity, you need to provide a position and a size

    // === Accessors ===
    Vector2 GetPosition() const;
    Vector2 GetPositionInViewSpace() const;
    Vector2 GetPotentialMovement() const;
    Vector2 GetSpeed() const;
    Rectangle GetRectangle() const;

    // === Setters ===
    void SetPosition(const Vector2& newPosition);
    void SetPositionInViewSpace(const Vector2& newPositionInViewSpace);
    void SetPotentialMovement(const Vector2& movement);

    // === Movemement & Logic ===
    virtual void CalculateNextMove() = 0;
    void UpdateHorizontalPosition();
    void UpdateVerticalPosition();

    // === Collision Handling ===
    void RevertHorizontalPosition();
    void RevertVerticalPosition();

    // === Rendering ===
    virtual void Render() const = 0;

protected:
    Vector2 _position;
    Vector2 _positionInViewSpace;
    Vector2 _potentialMovement;
    Vector2 _speed;
    Vector2 _size;
};