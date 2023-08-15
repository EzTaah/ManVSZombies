#include "player.hpp"


Player::Player() 
    : Entity(), 
      position({1600.0f, 70.0f}), 
      speed(600.0f), 
      size({30.0f, 30.0f}),
      bg(GREEN),
      potentialMovement({0.0f, 0.0f})
{}


void Player::SetPosition(Vector2 position_) 
{
    position = position_;
}


void Player::SetPotentialMovement(Vector2 movement_)
{
    potentialMovement = movement_;
}


void Player::MoveBy(Vector2 movement_)
{
    position.x += movement_.x;
    position.y += movement_.y;
}


void Player::ResetPositionX()
{
    position.x -= potentialMovement.x;
}


void Player::ResetPositionY()
{
    position.y -= potentialMovement.y;
}


void Player::SetPositionInViewSpace(const Vector2& position_)
{
    positionInViewSpace = position_;
}


Vector2 Player::GetPosition()
{
    return position;
}


Vector2 Player::GetPotentialMovement()
{
    return potentialMovement;
}


Rectangle Player::GetRectangle()
{
    return {position.x, position.y, size.x, size.y};
}


Rectangle Player::GetRectangleInViewSpace()
{
    return {positionInViewSpace.x, positionInViewSpace.y, size.x, size.y};
}



float Player::GetSpeed() 
{
    return speed;
}


Vector2 Player::GetPositionInViewSpace()
{
    return positionInViewSpace;
}


void Player::Draw() const
{
    DrawRectangle(positionInViewSpace.x, positionInViewSpace.y, size.x, size.y, bg);
}