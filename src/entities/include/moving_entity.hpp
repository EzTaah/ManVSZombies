#pragma once
#include "entity.hpp"
#include <raylib.hpp>


class MovingEntity : public Entity
{
public:
    MovingEntity(const Vector2& position, const Vector2& speed, const Vector2& size);     // To create an entity, you need to provide a position and a size

    // === Accessors ===
    Vector2 GetPotentialMovement() const;
    Vector2 GetSpeed() const;

    // === Setters ===
    void SetPotentialMovement(const Vector2& movement);

    // === Movemement & Logic ===
    virtual void CalculateNextMove() = 0;
    void UpdateHorizontalPosition();
    void UpdateVerticalPosition();

    // === Collision Handling ===
    void RevertHorizontalPosition();
    void RevertVerticalPosition();

protected:
    Vector2 _potentialMovement;
    Vector2 _speed;
};