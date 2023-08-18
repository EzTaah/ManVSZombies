#include "zombie.hpp"
#include <cmath>


Zombie::Zombie(const Vector2& position)
    : MovingEntity(position, {30.0f, 30.0f})     // {30.0f, 30.0f} is the size of the zombie
{}


// === Utility functions ===
Vector2 DescisionMaking(const Rectangle& playerRectangle, const Rectangle& zombieRectangle);


// === Logic ===
void Zombie::CalculateNextMove() {}

void Zombie::CalculateNextMove(const Rectangle& playerRectangle_)
{
    // Find the direction the zombie needs to go to reach the player
    Vector2 direction = DescisionMaking(playerRectangle_, GetRectangle());

    // Calculate the delpacement the zombie will do
    _potentialMovement.x = direction.x * _speed.x;
    _potentialMovement.y = direction.y * _speed.y;
}


// === Render ===
void Zombie::Render() const {
    DrawRectangle(_positionInViewSpace.x, _positionInViewSpace.y, _size.x, _size.y, RED);
}





// ==================
Vector2 DescisionMaking(const Rectangle& playerRectangle, const Rectangle& zombieRectangle)
{
    // Calculate the direction based on the position of the zombie and player
    Vector2 direction = {playerRectangle.x - zombieRectangle.x, playerRectangle.y - zombieRectangle.y };

    // Normalize the direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {  // Avoid division by zero
        direction.x /= length;
        direction.y /= length;
    }

    return direction;
}
