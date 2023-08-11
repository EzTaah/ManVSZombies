#include "bullet.hpp"


Bullet::Bullet(Vector2 position_, Vector2 speed_, Vector2 size_)
    : position(position_), speed(speed_), size(size_)
{
    bg = BLACK;
}


void Bullet::Update()
{
    position.x += speed.x;
    position.y += speed.y;
}


void Bullet::Draw() const
{
    DrawRectangle(position.x, position.y, size.x, size.y, bg);
}


Rectangle Bullet::GetRectangle()
{
    return {position.x, position.y, size.x, size.y};
}






//////////////////////////
/*
bool Bullet::IsCollidingWithEnemy(EntityAttributes enemyAttributes_)
{
    return CheckCollisionRecs(Rectangle{position.x, position.y, width, height}, Rectangle{enemyAttributes_.x, enemyAttributes_.y, enemyAttributes_.width, enemyAttributes_.height});
}

bool Bullet::IsOutside()
{
    return (position.x < 0) || (position.x > GetScreenWidth() - width) || (position.y < 0) || (position.y > GetScreenHeight() - height); 
}
*/
