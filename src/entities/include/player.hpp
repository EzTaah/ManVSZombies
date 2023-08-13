#pragma once 
#include "entity.hpp"
#include <raylib.hpp>


class Player : public Entity
{
public:
    Player();
    void Update() override;
    void Draw() const override;

    Rectangle GetRectangle();
    void SetxPosition(float _xPosition);
    void SetyPosition(float _yPosition);
    int GetSpeed();

private:
    Vector2 position;
    float speed;
    Vector2 size;
    Color bg;
};


/*
bool isColliding();


*/
