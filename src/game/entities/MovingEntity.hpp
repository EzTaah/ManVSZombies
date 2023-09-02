#pragma once
#include "Entity.hpp"


class MovingEntity : public Entity
{
public:
    MovingEntity(const ut::Vector2f& position, const ut::Vector2f& speed, const ut::Vector2f& size);     // To create an entity, you need to provide a position and a size

    // === Accessors ===
    ut::Vector2f GetPotentialMovement() const;
    ut::Vector2f GetSpeed() const;

    // === Setters ===
    void SetPotentialMovement(const ut::Vector2f& movement);

    // === Movemement & Logic ===
    virtual void CalculateNextMove() = 0;
    void UpdateHorizontalPosition();
    void UpdateVerticalPosition();

    // === Collision Handling ===
    void RevertHorizontalPosition();
    void RevertVerticalPosition();

protected:
    ut::Vector2f _potentialMovement;
    ut::Vector2f _speed;
};