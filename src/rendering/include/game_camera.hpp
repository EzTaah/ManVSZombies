#pragma once 
#include <raylib.hpp>


class GameCamera
{
public:
    GameCamera();

    // Update
    void SetPosition(Vector2 position_);

    // Informations
    Vector2 GetPosition();


private:
    Vector2 position;
};