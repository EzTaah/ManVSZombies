#pragma once 
#include "entity.hpp"
#include <raylib.hpp>


class Zombie : public Entity
{
public:
    Zombie(Vector2 position_, Vector2 speed_, Vector2 size_);
    void Update(Rectangle playerRectangle_);
    void Draw() const override;

    Rectangle GetRectangle();
    Vector2 GetPositionInViewSpace();
    Vector2 GetPosition();
    void SetPositionInViewSpace(const Vector2& position_);

private:
    Vector2 position;
    Vector2 speed;
    Vector2 size;
    Color bg;
    Vector2 positionInViewSpace;
};