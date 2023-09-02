#pragma once 
#include "MovingEntity.hpp"
#include "utils.hpp"


class Player : public MovingEntity
{
public:
    Player(const ut::Vector2f& position);

    // === Rendering ===
    void Render() const override;
};