#include "wall.hpp"


Wall::Wall(std::array<int, 2> gridPosition_)
    : Entity(), 
      position({30.0f * gridPosition_[1], 30.0f * gridPosition_[0]})
{}


void Wall::Draw() const
{
    DrawRectangle(positionInViewSpace.x, positionInViewSpace.y, 30.0f, 30.0f, BLACK);
}


Rectangle Wall::GetRectangle()
{
    return {position.x, position.y, 30.0f, 30.0f};
}


void Wall::SetPositionInViewSpace(const Vector2& position_)
{
    positionInViewSpace = position_;
}


Vector2 Wall::GetPositionInViewSpace()
{
    return positionInViewSpace;
}


Vector2 Wall::GetPosition()
{
    return position;
}

