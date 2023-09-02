#pragma once 
#include "Entity.hpp"
#include "utils.hpp"


class Wall : public Entity
{
public:
    Wall(const ut::Vector2f& position);

    // === Rendering ===
    void Render() const override;
};