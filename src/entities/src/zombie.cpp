#include "zombie.hpp"


/// UTILITY FUNCTIONS //////////////////
Vector2 DescisionMaking(Rectangle playerRectangle_, Rectangle zombieRectangle_)
{
    Vector2 direction;

    if (playerRectangle_.x - zombieRectangle_.x < 0) {
        direction.x = -1;
    } else {
        direction.x = 1;
    }

    if (playerRectangle_.y - zombieRectangle_.y < 0) {
        direction.y = -1;
    } else {
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




/*

void Zombie::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, bg);
}



bool Zombie::isOutside()
{
    return (position.x < 0) || (position.x > GetScreenWidth() - width) || (position.y < 0) || (position.y > GetScreenHeight() - height);   
}

*/