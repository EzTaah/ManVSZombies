 #pragma once 
#include "moving_entity.hpp"
#include <raylib.hpp>


class Zombie : public MovingEntity
{
public:
    Zombie(const Vector2& position);

    // === Logic ===
    void CalculateNextMove() override;
    void CalculateNextMove(const Rectangle& playerRectangle);

    // Rendering
    void Render() const override;
};