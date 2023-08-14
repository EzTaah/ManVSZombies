#pragma once 
#include "entity.hpp"
#include <raylib.hpp>


class Player : public Entity
{
public:
    Player();

    void Draw() const override;

    // Update
    void SetPosition(Vector2 position_);
    void SetPotentialMovement(Vector2 movement_);
    void MoveBy(Vector2 movement_);
    void ResetPositionX();
    void ResetPositionY();

    // Informations
    Vector2 GetPotentialMovement();
    Rectangle GetRectangle();
    float GetSpeed();


private:
    Vector2 position;
    float speed;
    Vector2 size;
    Color bg;
    Vector2 potentialMovement;
};


/*
bool isColliding();



*/