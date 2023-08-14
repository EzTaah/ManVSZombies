#pragma once
#include "input_manager.hpp"
#include "player.hpp"
#include "bullet_manager.hpp"
#include "zombie_manager.hpp"
#include "collision_manager.hpp"


class Game
{
public:
    Game();
    void Update();
    void RenderScene();


private:
    void HandleInputs();
    void UpdateEntities();
    void HandleCollisions();

    bool isGameOver;

    InputManager inputManager;
    Player player;
    BulletManager bulletManager;
    ZombieManager zombieManager;
    CollisionManager collisionManager;
};