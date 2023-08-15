#include "game_camera.hpp"


GameCamera::GameCamera() {}


void GameCamera::SetPosition(Vector2 position_) 
{
    position = position_;
}


Vector2 GameCamera::GetPosition()
{
    return position;
}