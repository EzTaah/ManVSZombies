#include "Zombie.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>


Zombie::Zombie(const ut::Vector2f& position)
    : MovingEntity(position, {200.0f, 200.0f}, {30.0f, 30.0f})     // {30.0f, 30.0f} is the size of the zombie
{
    _shape.setFillColor(sf::Color::Red);
}


// === Utility functions ===
ut::Vector2f DescisionMaking(const ut::Rectanglef& playerRectangle, const ut::Rectanglef& zombieRectangle);


// === Logic ===
void Zombie::CalculateNextMove() {}

void Zombie::CalculateNextMove(const ut::Rectanglef& playerRectangle_)
{
    // Find the direction the zombie needs to go to reach the player
    ut::Vector2f direction = DescisionMaking(playerRectangle_, GetRectangle());

    // Calculate the delpacement the zombie will do
    _potentialMovement.x = direction.x * _speed.x;
    _potentialMovement.y = direction.y * _speed.y;
}


// === Render ===
void Zombie::Render(sf::RenderWindow* windowPtr) {
    _shape.setPosition(_position.x, _position.y);
    windowPtr->draw(_shape);
}





// ==================
ut::Vector2f DescisionMaking(const ut::Rectanglef& playerRectangle, const ut::Rectanglef& zombieRectangle)
{
    // Calculate the direction based on the position of the zombie and player
    ut::Vector2f direction = {playerRectangle.x - zombieRectangle.x, playerRectangle.y - zombieRectangle.y };

    // Normalize the direction
    float length = sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0) {  // Avoid division by zero
        direction.x /= length;
        direction.y /= length;
    }

    return direction;
}
