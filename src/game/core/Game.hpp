#pragma once
#include "Entity.hpp"
#include "MovingEntity.hpp"
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
    Game(sf::RenderWindow* windowPtr);
    void Update();
    void Render();

private:
    void _HandleInputs();
    void _HandleCollisions(char mode); 

    double _lastUpdateTimeEvent1;
    double _lastUpdateTimeEvent2;

    sf::RenderWindow* _windowPtr;

    std::vector<Entity*> _staticEntitiesArray;
    std::vector<MovingEntity*> _movingEntitiesArray;

    Grid _grid;
    Player _player;
    BulletManager _bulletManager;
    ZombieManager _zombieManager;
    WallManager _wallManager;
    CollisionManager _collisionManager;
    Renderer _renderer;
};