#pragma once
#include "entity.hpp"
#include <raylib.hpp>


class Bullet : public Entity
{
public:
    Bullet(Vector2 position_, Vector2 speed_, Vector2 size_);
    void Update() override;
    void Draw() const override;

    Rectangle GetRectangle();

private:
    Vector2 position;
    Vector2 speed;
    Vector2 size;
    Color bg;
};




///////////////////////////
/*
bool IsOutside();
bool IsCollidingWithEnemy(EntityAttributes enemyAttributes_);



*/