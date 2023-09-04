#pragma once
#include "utils.hpp"
#include "SFML/Graphics.hpp"


class Entity
{
public:
    Entity(const ut::Vector2f& position, const ut::Vector2f& size);

    // === Accessors ===
    ut::Vector2f GetPosition() const;
    ut::Vector2f GetPositionInViewSpace() const;
    ut::Rectanglef GetRectangle() const;

    // === Setters ===
    void SetPosition(const ut::Vector2f& newPosition);
    void SetPositionInViewSpace(const ut::Vector2f& newPositionInViewSpace);

    // === Rendering ===
    virtual void Render(sf::RenderWindow* windowPtr) = 0;

protected:
    ut::Vector2f _position;
    ut::Vector2f _positionInViewSpace;
    ut::Vector2f _size;
    sf::RectangleShape _shape;
};