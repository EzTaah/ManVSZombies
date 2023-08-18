#pragma once
#include "moving_entity.hpp"
#include <raylib.hpp>


class Bullet : public MovingEntity
{
public:
    Bullet(const Vector2& position, const Vector2& speed);

    // === Accessors ===
    bool IsActive() const;

    // === Setters ===
    void Activate();
    void Desactivate();

    // === Logic ===
    void CalculateNextMove() override;

    // === Rendering ===
    void Render() const override;

private:
    bool _isActive;
};