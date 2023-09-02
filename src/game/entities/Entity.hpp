#pragma once
#include "utils.hpp"


class Entity
{
public:
    Entity(const ut::Vector2f& position, const ut::Vector2f& size);

    // === Accessors ===
    ut::Vector2fGetPosition() const;
    ut::Vector2fGetPositionInViewSpace() const;
    ut::Rectanglef GetRectangle() const;

    // === Setters ===
    void SetPosition(const ut::Vector2f& newPosition);
    void SetPositionInViewSpace(const ut::Vector2f& newPositionInViewSpace);

    // === Rendering ===
    virtual void Render() const = 0;

protected:
    ut::Vector2f_position;
    ut::Vector2f_positionInViewSpace;
    ut::Vector2f_size;
};