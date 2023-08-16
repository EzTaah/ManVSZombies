#pragma once
#include "entity.hpp"
#include <raylib.hpp>


class Bullet : public Entity
{
public:
    Bullet(Vector2 position_, Vector2 speed_, Vector2 size_);

    // Update
    void SetupPotentialMovement();

    // Move
    void UpdateX();
    void UpdateY();


    // Information
    Rectangle GetRectangle();
    Vector2 GetPositionInViewSpace();
    Vector2 GetPosition();

    // Rendering
    void Draw() const override;
    void SetPositionInViewSpace(const Vector2& position_);


private:
    Vector2 position;
    Vector2 potentialMovement;
    Vector2 speed;
    Vector2 size;
    Color bg;
    Vector2 positionInViewSpace;
};




/*
bool IsOutside();

bool IsCollidingWithEnemy(EntityAttributes enemyAttributes_);


*/