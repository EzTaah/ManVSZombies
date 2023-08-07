#pragma once
#include "../include/raylib.h"

class Entity
{
    public:
        Entity();
        virtual void Update();
        virtual void Draw() const;
};