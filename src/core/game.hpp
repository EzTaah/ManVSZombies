#pragma once
#include "entity.hpp"
#include "moving_entity.hpp"
#include "grid_manager.hpp"
#include "player.hpp"
#include "bullet_manager.hpp"
#include "zombie_manager.hpp"
#include "wall_manager.hpp"
#include "collision_manager.hpp"
#include "renderer.hpp"

#include <memory>


class Game
{
public:
    Game();
    void Update();
    void Render();

private:
    void _HandleInputs();
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

    std::vector<std::shared_ptr<Entity>> _entitiesArray;
    std::vector<std::shared_ptr<MovingEntity>> _movingEntitiesArray;
};