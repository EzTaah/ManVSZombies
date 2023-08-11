#pragma once
#include "entity.hpp"
#include "library.hpp"
#include <raylib.hpp>

class Bullet : public Entity
{
    public:
        Bullet(Vector2 _position, float _xSpeed, float _ySpeed);

        void Update() override;
        void Draw() const override;
        bool IsOutside();
        bool IsCollidingWithEnemy(EntityAttributes enemyAttributes);
        EntityAttributes GetAttributes();
        Rectangle GetRectangle();

    private:
        Vector2 position;
        float width;
        float height;
        float xSpeed;
        float ySpeed;
        Color bg;
};