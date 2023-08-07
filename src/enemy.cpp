#include "../include/library.hpp"
#include "../include/enemy.hpp"
#include "../include/player.hpp"
#include <raylib.h>
#include <cassert>


Enemy::Enemy(Vector2 _position)
{
    position.x = _position.x;
    position.y = _position.y;
    width = 30;
    height = 30;
    bg = RED;
}



void Enemy::Update(EntityAttributes playerAttributes)
{
    Vector2 descision = DescisionMaking(playerAttributes);

    position.x += descision.x;
    position.y += descision.y;
}

void Enemy::Draw() const
{
    DrawRectangle(position.x, position.y, width, height, bg);
}


bool Enemy::isOutside()
{
    return (position.x < 0) || (position.x > GetScreenWidth() - width) || (position.y < 0) || (position.y > GetScreenHeight() - height);   
}



Vector2 Enemy::DescisionMaking(EntityAttributes playerAttributes)
{
    Vector2 result;

    if (playerAttributes.x - position.x < 0) {
        result.x = -1;
    } else {
        result.x = 1;
    }

    if (playerAttributes.y - position.y < 0) {
        result.y = -1;
    } else {
        result.y = 1;
    }

    return result;
}


EntityAttributes Enemy::GetAttributes() {
    return {position.x, position.y, width, height};
}


Rectangle Enemy::GetRectangle()
{
    return {position.x, position.y, width, height};
}