#pragma once
#include "grid_manager.hpp"
#include "player.hpp"
#include "bullet_manager.hpp"
#include "zombie_manager.hpp"
#include "wall_manager.hpp"
#include "collision_manager.hpp"
#include "renderer.hpp"


class Game
{
public:
    Game();
    void Update();
    void Render();

private:
    void _HandleInputs();
    void _CalculateNextMoveEntities();
    void _UpdateHorizontalPositionEntities();
    void _UpdateVerticalPositionEntities();
    void _HandleCollisions(char mode); 

    double _lastUpdateTimeEvent1;
    double _lastUpdateTimeEvent2;

    GridManager _gridManager;
    Player _player;
    BulletManager _bulletManager;
    ZombieManager _zombieManager;
    WallManager _wallManager;
    CollisionManager _collisionManager;
    Renderer _renderer; 
};