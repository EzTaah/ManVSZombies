#pragma once 
#include "entity.hpp"
#include <raylib.hpp>


class Player : public Entity
{
public:
    Player();

    // Update
    void SetPosition(Vector2 position_);
    void SetPotentialMovement(Vector2 movement_);
    void MoveBy(Vector2 movement_);
    void ResetPositionX();
    void ResetPositionY();
    void SetPositionInViewSpace(const Vector2& position_);

    // Informations
    Vector2 GetPosition();
    Vector2 GetPotentialMovement();
    Rectangle GetRectangle();
    Rectangle GetRectangleInViewSpace();
    float GetSpeed();
    Vector2 GetPositionInViewSpace();

    // Draw
    void Draw() const override;


private:
    Vector2 position;
    Vector2 potentialMovement;
    float speed;
    Vector2 size;
    Color bg;
    Vector2 positionInViewSpace;
};