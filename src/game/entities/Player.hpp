#pragma once 
#include "MovingEntity.hpp"
#include "utils.hpp"


class Player : public MovingEntity
{
public:
    Player(const ut::Vector2f& position);

    // === Accessors ===
    ut::Rectanglef GetRectangleInViewSpace() const;

    // === Logic ===
    void CalculateNextMove();

    // === Rendering ===
    void Render(sf::RenderWindow* windowPtr) override;
};