#include "game.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <iostream>
#include <utility>
#include <algorithm>


///////////////// PUBLIC /////////////////
Game::Game() 
    : _gridManager(),
      _player({500.0f, 600.0f}),
      _bulletManager(),
      _zombieManager(),
      _wallManager(_gridManager.GetGrid()),     // Init all the walls
      _collisionManager(),
      _renderer(_player.GetRectangle()),     // Setup camera
      _lastUpdateTimeEvent1(0.0),
      _lastUpdateTimeEvent2(0.0),

      _entitiesArray(),
      _movingEntitiesArray()
{}



void Game::Update() {
    // === Manage zombies spawn ===
    if (EventTriggered(0.5, _lastUpdateTimeEvent2)) 
        _zombieManager.SpawnNewZombie(_gridManager.GetGrid(), _gridManager.GetNumberOfTiles(), _movingEntitiesArray);


    // === Handle inputs ===
    _HandleInputs();


    // === Calculate next move entities ===
    for(std::shared_ptr<MovingEntity>& movingEntity : _movingEntitiesArray)
        movingEntity->CalculateNextMove(); // Se rappeler que pour calculateNextMoveZombie, il faut playerRectangle


    // === Manage horzontal deplacement
    for(std::shared_ptr<MovingEntity>& movingEntity : _movingEntitiesArray)
        movingEntity->UpdateHorizontalPosition();
    _HandleCollisions('x');


    // === Manage vertical deplacement
    for(std::shared_ptr<MovingEntity>& movingEntity : _movingEntitiesArray)
        movingEntity->UpdateVerticalPosition();
    _HandleCollisions('y');
}



void Game::Render()
{
    _renderer.UpdateCameraPosition(_player.GetRectangle());
    _renderer.UpdatePositionInViewSpaceEntities(_gridManager, _player, _bulletManager, _zombieManager, _wallManager);

    for(const std::shared_ptr<Entity>& entity : _entitiesArray)
        entity->Render();   // Je peux dire que l'entity est constante car j'ai affirmé que la methode render etait une methode cste 
}


///////////////// PRIVATE /////////////////
void Game::_HandleInputs()
{
    // Mouse management
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        if (EventTriggered(0.1, _lastUpdateTimeEvent1)) 
            _bulletManager.ShootNewBullet(_player.GetRectangle(), _player.GetRectangleInViewSpace());
    }

    // Keys management
    Vector2 playerPotentialMovement{0.0f, 0.0f};
    if(IsKeyDown(KEY_W)) 
        playerPotentialMovement.y -= _player.GetSpeed().y;
    if(IsKeyDown(KEY_S))
        playerPotentialMovement.y += _player.GetSpeed().y; 
    if(IsKeyDown(KEY_A))
        playerPotentialMovement.x -= _player.GetSpeed().x; 
    if(IsKeyDown(KEY_D))
        playerPotentialMovement.x += _player.GetSpeed().x; 
    _player.SetPotentialMovement(playerPotentialMovement);
}

void Game::_HandleCollisions(char mode)
{
    // Nouvelle gestion de collisions à venir
}