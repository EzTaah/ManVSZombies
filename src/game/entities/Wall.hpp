#pragma once 
#include "Entity.hpp"
#include <raylib.hpp>


class Wall : public Entity
{
public:
    Wall(const Vector2& position);

    // === Rendering ===
    void Render() const override;
};