#pragma once
#include "grid_manager.hpp"
#include "input_manager.hpp"
#include "player.hpp"
#include "bullet_manager.hpp"
#include "zombie_manager.hpp"
#include "wall_manager.hpp"
#include "collision_manager.hpp"
#include "renderer.hpp"
#include <vector>


class Game
{
public:
    Game();
    void Update();
    void RenderScene();


private:
    void HandleInputs();
    void SetPotentialMovementEntities();

    void UpdateEntitiesX();
    void HandleCollisionsX();

    void UpdateEntitiesY();
    void HandleCollisionsY();


    bool isGameOver;
    double lastUpdateTimeEvent1;
    std::vector<std::vector<int>> grid;

    GridManager gridManager;
    InputManager inputManager;
    Player player;
    BulletManager bulletManager;
    ZombieManager zombieManager;
    WallManager wallManager;
    CollisionManager collisionManager;
    Renderer renderer;
       
};