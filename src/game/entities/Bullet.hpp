#pragma once
#include "MovingEntity.hpp"
#include "utils.hpp"


class Bullet : public MovingEntity
{
public:
    Bullet(const ut::Vector2f& position, const ut::Vector2f& speed);

    // === Accessors ===
    bool IsActive() const;

    // === Setters ===
    void Activate();
    void Desactivate();

    // === Logic ===
    void CalculateNextMove() override;

    // === Rendering ===
    void Render(sf::RenderWindow* windowPtr) override;

private:
    bool _isActive;
};