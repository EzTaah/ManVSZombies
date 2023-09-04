 #pragma once 
#include "MovingEntity.hpp"
#include "utils.hpp"


class Zombie : public MovingEntity
{
public:
    Zombie(const ut::Vector2f& position);

    // === Logic ===
    void CalculateNextMove() override;
    void CalculateNextMove(const ut::Rectanglef& playerRectangle);

    // Rendering
    void Render(sf::RenderWindow* windowPtr) override;
};