#include "bullet.hpp"


Bullet::Bullet(Vector2 position_, Vector2 speed_, Vector2 size_)
    : Entity(),
      position(position_),
      speed(speed_), 
      size(size_),
      bg(PURPLE)
{}


void Bullet::SetupPotentialMovement()
{
    potentialMovement.x = speed.x;
    potentialMovement.y = speed.y; 
}


void Bullet::UpdateX()
{
    position.x += potentialMovement.x * GetFrameTime();
}


void Bullet::UpdateY()
{
    position.y += potentialMovement.y * GetFrameTime();
}


void Bullet::SetPositionInViewSpace(const Vector2& position_)
{
    positionInViewSpace = position_;
}


void Bullet::Draw() const
{
    DrawRectangle(positionInViewSpace.x, positionInViewSpace.y, size.x, size.y, bg);
}


Rectangle Bullet::GetRectangle()
{
    return {position.x, position.y, size.x, size.y};
}


Vector2 Bullet::GetPositionInViewSpace()
{
    return positionInViewSpace;
}


Vector2 Bullet::GetPosition()
{
    return position;
}





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
