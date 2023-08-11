#pragma once 
#include "entity.hpp"
#include "library.hpp"
#include "raylib.h"
#include <random>

class Enemy : public Entity
{
    public:
        Enemy(Vector2 _position);
        void Update(EntityAttributes playerAttributes);
        void Draw() const override;
        bool isOutside();
        EntityAttributes GetAttributes();
        Rectangle GetRectangle();

        Vector2 DescisionMaking(EntityAttributes playerAttributes);

    private:
        Vector2 position;
        float width;
        float height;
        Color bg;
};

