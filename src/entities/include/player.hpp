#pragma once 
#include "moving_entity.hpp"
#include <raylib.hpp>


class Player : public MovingEntity
{
public:
    Player(const Vector2& position);

    // === Rendering ===
    void Render() const override;
};