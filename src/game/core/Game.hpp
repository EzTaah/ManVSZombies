#pragma once
#include "Grid.hpp"
#include "Player.hpp"
#include "BulletManager.hpp"
#include "ZombieManager.hpp"
#include "WallManager.hpp"
#include "CollisionManager.hpp"
#include "Renderer.hpp"


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

    Grid _grid;
    Player _player;
    BulletManager _bulletManager;
    ZombieManager _zombieManager;
    WallManager _wallManager;
    CollisionManager _collisionManager;
    Renderer _renderer; 
};