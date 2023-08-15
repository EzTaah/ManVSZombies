#include "zombie.hpp"


/// UTILITY FUNCTIONS //////////////////
Vector2 DescisionMaking(Rectangle playerRectangle_, Rectangle zombieRectangle_)
{
    Vector2 direction;

    if (playerRectangle_.x - zombieRectangle_.x < 0) {
        direction.x = -1;
    } 
    else if(playerRectangle_.x - zombieRectangle_.x == 0) {
        direction.x = 0;
    }
    else {
        direction.x = 1;
    }

    if (playerRectangle_.y - zombieRectangle_.y < 0) {
        direction.y = -1;
    } 
    else if(playerRectangle_.y - zombieRectangle_.y == 0) {
        direction.y = 0;
    }
    else {
        direction.y = 1;
    }

    return direction;
}

////////////////////////////////////////


Zombie::Zombie(Vector2 position_, Vector2 speed_, Vector2 size_)
    : Entity(), 
      position(position_), 
      speed(speed_), 
      size(size_),
      bg(RED)
{}


void Zombie::Update(Rectangle playerRectangle_)
{
    Vector2 direction = DescisionMaking(playerRectangle_, GetRectangle());      // Return the direction the zombie needs to go to reach the player

    position.x += direction.x;
    position.y += direction.y;
}


Rectangle Zombie::GetRectangle()
{
    return {position.x, position.y, size.x, size.y};
}


void Zombie::Draw() const
{
    DrawRectangle(positionInViewSpace.x, positionInViewSpace.y, size.x, size.y, bg);
}


void Zombie::SetPositionInViewSpace(const Vector2& position_)
{
    positionInViewSpace = position_;
}


Vector2 Zombie::GetPositionInViewSpace()
{
    return positionInViewSpace;
}


Vector2 Zombie::GetPosition()
{
    return position;
}
