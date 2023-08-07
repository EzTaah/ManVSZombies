#include "../include/player.hpp"
#include "../include/bullet.hpp"
#include "../include/library.hpp"
#include "../include/raylib.h"
#include <cassert>
#include <cmath>
#include <iostream>


Player::Player() : Entity()
{
    position = {GetScreenWidth() - 70.0f, GetScreenHeight() / 2.0f};
    width = 30.0;
    height = 30.0;
    speed = 600;
    bg = GREEN;
    // - bulletsId = 0;
}

void Player::Update()
{
    // do nothing
}


void Player::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, bg);
}


bool Player::isColliding()
{
    return (position.x < 0) || (position.x > GetScreenWidth() - width) || (position.y < 0) || (position.y > GetScreenHeight() - height);   
}


EntityAttributes Player::GetAttributes() {
    return {position.x, position.y, width, height};
}

Rectangle Player::GetRectangle()
{
    return {position.x, position.y, width, height};
}


void Player::SetxPosition(float _xPosition) { position.x = _xPosition; }
void Player::SetyPosition(float _yPosition) { position.y = _yPosition; }
int Player::GetSpeed() { return speed; }