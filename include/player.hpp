#pragma once 
#include "entity.hpp"
#include "bullet.hpp"
#include "library.hpp"
#include "raylib.h"
#include <vector>

class Player : public Entity
{
    public:
        Player();
        void Update() override;
        void Draw() const override;
        bool isColliding();

        EntityAttributes GetAttributes();
        void SetxPosition(float _xPosition);
        void SetyPosition(float _yPosition);
        int GetSpeed();

        Rectangle GetRectangle();

    private:
        Vector2 position;
        float width;
        float height;
        int speed;
        Color bg;
};
