#pragma once 
#include "entity.hpp"
#include <raylib.hpp>


class Player : public Entity
{
public:
    Player();

    // Update
    void SetPosition(Vector2 position_);
    void MoveBy(Vector2 movement_);

    // Informations
    Rectangle GetRectangle();
    float GetSpeed();


private:
    Vector2 position;
    float speed;
    Vector2 size;
    Color bg;
};


/*
bool isColliding();

void Draw() const override;

*/