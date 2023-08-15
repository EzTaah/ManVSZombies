#pragma once 
#include "entity.hpp"
#include <raylib.hpp>
#include <array>


class Wall : public Entity
{
public:
    Wall(std::array<int, 2> gridPosition_);
    void Draw() const override;

    Rectangle GetRectangle();
    Vector2 GetPositionInViewSpace();
    Vector2 GetPosition();
    void SetPositionInViewSpace(const Vector2& position_);

private:
    Vector2 position;
    Color bg;
    Vector2 positionInViewSpace;
};