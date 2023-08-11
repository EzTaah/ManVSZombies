#pragma once
#include <raylib.hpp>

class Entity
{
    public:
        Entity();
        virtual void Update();
        virtual void Draw() const;
};