#pragma once 
#include "static_entity.hpp"
#include <raylib.hpp>


class Wall : public StaticEntity
{
public:
    Wall(const Vector2& position);

    // === Rendering ===
    void Render() const override;
};