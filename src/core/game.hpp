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
    void Draw();

    void CheckCollisionBallEnemy();
    void CheckCollisionPlayerEnemy();

private:
    void HandleInputs();
    void Shoot();

    InputManager inputManager;
    Player player;
    BulletManager bulletManager;
    ZombieManager zombieManager;
    CollisionManager collisionManager;
};