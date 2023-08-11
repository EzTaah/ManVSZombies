#pragma once
#include "raylib.h"

class Entity
{
    public:
        Entity();
        virtual void Update();
        virtual void Draw() const;
};