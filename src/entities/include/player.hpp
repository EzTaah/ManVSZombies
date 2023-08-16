#pragma once 
#include "entity.hpp"
#include <raylib.hpp>


class Player : public Entity
{
public:
    Player();

    // Move
    void SetPosition(Vector2 position_);
    void SetPotentialMovement(Vector2 movement_);
    void UpdateX();
    void UpdateY();

    // Collisions
    void ResetPositionX();
    void ResetPositionY();

    // Informations
    Vector2 GetPosition();
    Vector2 GetPotentialMovement();
    Rectangle GetRectangle();
    Rectangle GetRectangleInViewSpace();
    float GetSpeed();
    Vector2 GetPositionInViewSpace();

    // Rendering
    void Draw() const override;
    void SetPositionInViewSpace(const Vector2& position_);


private:
    Vector2 position;
    Vector2 potentialMovement;
    float speed;
    Vector2 size;
    Color bg;
    Vector2 positionInViewSpace;
};