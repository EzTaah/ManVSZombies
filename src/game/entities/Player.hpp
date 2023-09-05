#pragma once 
#include "MovingEntity.hpp"
#include <raylib.hpp>


class Player : public MovingEntity
{
public:
    Player(const Vector2& position);

    // === Accessors ===
    Rectangle GetRectangleInViewSpace() const;

    // === Logic === 
    void CalculateNextMove();

    // === Rendering ===
    void Render() const override;
};