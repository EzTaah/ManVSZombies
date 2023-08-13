#include "player.hpp"


Player::Player() 
    : Entity(), 
      position({GetScreenWidth() - 70.0f, GetScreenHeight() / 2.0f}), 
      speed(600.0f), 
      size({30.0f, 30.0f}),
      bg(GREEN)
{}


void Player::SetPosition(Vector2 position_) 
{
    position = position_;
}


void Player::MoveBy(Vector2 movement_)
{
    position.x += movement_.x;
    position.y += movement_.y;
}


Rectangle Player::GetRectangle()
{
    return {position.x, position.y, size.x, size.y};
}


float Player::GetSpeed() 
{
    return speed;
}






/*
bool Player::isColliding()
{
    return (position.x < 0) || (position.x > GetScreenWidth() - width) || (position.y < 0) || (position.y > GetScreenHeight() - height);   
}


void Player::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, bg);
}
*/