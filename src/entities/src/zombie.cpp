#include "zombie.hpp"
#include <cmath>


/// UTILITY FUNCTIONS //////////////////
Vector2 DescisionMaking(Rectangle playerRectangle_, Rectangle zombieRectangle_)
{
    // Calculate the direction based on the position of the zombie and player
    Vector2 direction = {playerRectangle_.x - zombieRectangle_.x, playerRectangle_.y - zombieRectangle_.y };

    // Normalize the direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {  // Avoid division by zero
        direction.x /= length;
        direction.y /= length;
    }

    return direction;
}

////////////////////////////////////////


Zombie::Zombie(Vector2 position_, float speed_, Vector2 size_)
    : Entity(), 
      position(position_), 
      speed(speed_), 
      size(size_),
      bg(RED),
      potentialMovement({0.0f, 0.0f})
{}


// Update
void Zombie::SetupPotentialMovement(Rectangle playerRectangle_)
{
    // Find the direction the zombie needs to go to reach the player
    Vector2 direction = DescisionMaking(playerRectangle_, GetRectangle());

    // Calculate the delpacement the zombie will do
    potentialMovement.x = direction.x * speed;
    potentialMovement.y = direction.y * speed;
}


// Move
void Zombie::SetPosition(Vector2 position_) 
{
    position = position_;
}


void Zombie::UpdateX()
{
    position.x += potentialMovement.x * GetFrameTime();
}


void Zombie::UpdateY()
{
    position.y += potentialMovement.y * GetFrameTime();
}


// Collisions
void Zombie::ResetPositionX()
{
    position.x -= potentialMovement.x * GetFrameTime();
}


void Zombie::ResetPositionY()
{
    position.y -= potentialMovement.y * GetFrameTime();
}


// Informations
Vector2 Zombie::GetPosition()
{
    return position;
}


Vector2 Zombie::GetPotentialMovement()
{
    return potentialMovement;
}


Rectangle Zombie::GetRectangle()
{
    return {position.x, position.y, size.x, size.y};
}


float Zombie::GetSpeed() 
{
    return speed;
}


Vector2 Zombie::GetPositionInViewSpace()
{
    return positionInViewSpace;
}


// Draw
void Zombie::Draw() const
{
    DrawRectangle(positionInViewSpace.x, positionInViewSpace.y, size.x, size.y, bg);
}


void Zombie::SetPositionInViewSpace(const Vector2& position_)
{
    positionInViewSpace = position_;
}