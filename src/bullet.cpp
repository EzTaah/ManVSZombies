#include "bullet.hpp"
#include <iostream>
#include "raylib.h"

Bullet::Bullet(Vector2 _position, float _xSpeed, float _ySpeed)
{
    position = _position;
    width = 10.0;
    height = 5.0;
    xSpeed = _xSpeed;
    ySpeed = _ySpeed;
    bg = BLACK;
}


void Bullet::Update()
{
    position.x += xSpeed;
    position.y += ySpeed;
}


void Bullet::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, bg);
}


bool Bullet::IsOutside()
{
    return (position.x < 0) || (position.x > GetScreenWidth() - width) || (position.y < 0) || (position.y > GetScreenHeight() - height); 
}


bool Bullet::IsCollidingWithEnemy(EntityAttributes enemyAttributes)
{
    return CheckCollisionRecs(Rectangle{position.x, position.y, width, height}, Rectangle{enemyAttributes.x, enemyAttributes.y, enemyAttributes.width, enemyAttributes.height});
}


EntityAttributes Bullet::GetAttributes() {
    return {position.x, position.y, width, height};
}


Rectangle Bullet::GetRectangle()
{
    return {position.x, position.y, width, height};
}