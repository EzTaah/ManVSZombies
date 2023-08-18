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
      _lastUpdateTimeEvent2(0.0)
{}

void Game::Update() {
    _HandleInputs();
    _CalculateNextMoveEntities();

    _UpdateHorizontalPositionEntities();
    _HandleCollisions('x');

    _UpdateVerticalPositionEntities();
    _HandleCollisions('y');
}

void Game::Render()
{
    _renderer.UpdateCameraPosition(_player.GetRectangle());
    _renderer.UpdatePositionInViewSpaceEntities(_gridManager, _player, _bulletManager, _zombieManager, _wallManager);
    _renderer.Render(_gridManager, _player, _bulletManager, _zombieManager, _wallManager);
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

void Game::_CalculateNextMoveEntities()
{
    // Spawn new zombies if needed
    if (EventTriggered(0.5, _lastUpdateTimeEvent2)) 
        _zombieManager.SpawnNewZombie(_gridManager.GetGrid(), _gridManager.GetNumberOfTiles());

    // Calculate and setup the nextMove for all zombies and bullets
    _zombieManager.CalculateNextMoveZombies(_player.GetRectangle());
    _bulletManager.CalculateNextMoveBullets();
}

void Game::_UpdateHorizontalPositionEntities()
{
    _player.UpdateHorizontalPosition();
    _zombieManager.UpdateHorizontalPositionZombies();
    _bulletManager.UpdateHorizontalPositionBullets();
}

void Game::_UpdateVerticalPositionEntities()
{
    _player.UpdateVerticalPosition();
    _zombieManager.UpdateVerticalPositionZombies();
    _bulletManager.UpdateVerticalPositionBullets();
}

void Game::_HandleCollisions(char mode)
{
    // === Check for player-boundary collision ===
    if(_collisionManager.IsOutsideBoundaryX(_player.GetRectangle(), _gridManager.GetGridDimensions().x)) 
        _player.RevertHorizontalPosition();
    if(_collisionManager.IsOutsideBoundaryY(_player.GetRectangle(), _gridManager.GetGridDimensions().y))
        _player.RevertVerticalPosition();

    // === Check for bullet-boundary collision ===
    for(unsigned int i{0} ; i < _bulletManager.GetBulletsArray().size() ; ++i)
    {
        bool isOutsideBoundaryX = _collisionManager.IsOutsideBoundaryX(_bulletManager.GetBulletsArray()[i].GetRectangle(), _gridManager.GetGridDimensions().x);
        bool isOutsideBoundaryY = _collisionManager.IsOutsideBoundaryY(_bulletManager.GetBulletsArray()[i].GetRectangle(), _gridManager.GetGridDimensions().y);
        if(isOutsideBoundaryX || isOutsideBoundaryY) 
            _bulletManager.RemoveBullet(i);
    }

    // === Check for player-zombie collision ===
    for(unsigned int i{0} ; i < _zombieManager.GetZombiesArray().size() ; ++i)
    {
        Zombie& zombie = _zombieManager.GetZombiesArray()[i];
        if(CheckCollisionRecs(_player.GetRectangle(), zombie.GetRectangle()))
        {
            if(mode == 'x') {
                _player.RevertHorizontalPosition();
                _zombieManager.RevertHorizontalPositionZombie(i);
            }
            else {
                _player.RevertVerticalPosition();
                _zombieManager.RevertVerticalPositionZombie(i); 
            }
        }
    }

    // === Check for zombie-zombie collision ===
    for(unsigned int i{0} ; i < _zombieManager.GetZombiesArray().size() ; ++i) {
        Zombie& zombie1 = _zombieManager.GetZombiesArray()[i];

        for(unsigned int k{i+1} ; k < _zombieManager.GetZombiesArray().size() ; ++k) {
            Zombie& zombie2 = _zombieManager.GetZombiesArray()[k];

            if(CheckCollisionRecs(zombie1.GetRectangle(), zombie2.GetRectangle()))
            {
                if(mode == 'x')
                {
                    if (zombie1.GetPotentialMovement().x * zombie2.GetPotentialMovement().x <= 0) {   // If the zombies go in opposite directions
                        _zombieManager.RevertHorizontalPositionZombie(i);
                        _zombieManager.RevertHorizontalPositionZombie(k);
                    }
                    else    // The zombies go in the same direction, but there is a collision
                    {
                        // === Calculate which zombie is behind ===
                        float oldZombie1PositionX{zombie1.GetPosition().x - zombie1.GetPotentialMovement().x}; // Simulate case where only zombie2 has moved
                        Rectangle oldZombie1Rectangle = {oldZombie1PositionX, zombie1.GetRectangle().y, zombie1.GetRectangle().width, zombie1.GetRectangle().width};

                        if(CheckCollisionRecs(oldZombie1Rectangle, zombie2.GetRectangle()))     // If it is true, the zombie2 is behind
                            _zombieManager.RevertHorizontalPositionZombie(k);    // As a result, only the zombie 2 will revert his position
                        else    // In this case, the zombie 1 is behind
                            _zombieManager.RevertHorizontalPositionZombie(i);     // As a result, only the zombie 1 will revert his position
                    }
                }
                else
                {
                    if (zombie1.GetPotentialMovement().y * zombie2.GetPotentialMovement().y <= 0) { // If the zombies go in opposite directions  
                        _zombieManager.RevertVerticalPositionZombie(i);
                        _zombieManager.RevertVerticalPositionZombie(k);
                    }
                    else    // The zombies go in the same direction, but there is a collision
                    {
                        // === Calculate which zombie is behind ===
                        float oldZombie1PositionY{zombie1.GetPosition().y - zombie1.GetPotentialMovement().y};  // Simulate case where only zombie2 has moved
                        Rectangle oldZombie1Rectangle = {zombie1.GetRectangle().x, oldZombie1PositionY, zombie1.GetRectangle().width, zombie1.GetRectangle().width};

                        if(CheckCollisionRecs(oldZombie1Rectangle, zombie2.GetRectangle()))     // If it is true, the zombie2 is behind
                             _zombieManager.RevertVerticalPositionZombie(k);   // As a result, only the zombie 2 will revert his position
                        else    // In this case, the zombie 1 is behind
                             _zombieManager.RevertVerticalPositionZombie(i);   // As a result, only the zombie 1 will revert his position
                    }
                }
            }
        }
    }

    // === Check for zombie-wall collsions ===
    for(unsigned int i{0} ; i < _zombieManager.GetZombiesArray().size() ; ++i) {
        Zombie& zombie = _zombieManager.GetZombiesArray()[i];

        for(unsigned int n{0} ; n < _wallManager.GetWallsArray().size() ; ++n) {
            Wall& wall = _wallManager.GetWallsArray()[n];

            if(_collisionManager.AreColliding(zombie.GetRectangle(), wall.GetRectangle()))
            {
                if(mode == 'x') {
                     _zombieManager.RevertHorizontalPositionZombie(i);
                }
                else
                     _zombieManager.RevertVerticalPositionZombie(i);
                break;  // Prevent the case where zombie is colliding with several walls
            }
        }
    }

    // === Check for player-wall collisions ===
    for(unsigned int i{0} ; i < _wallManager.GetWallsArray().size() ; ++i)
    {
        Wall& wall = _wallManager.GetWallsArray()[i];
        if(CheckCollisionRecs(_player.GetRectangle(), wall.GetRectangle()))
        {
            if(mode == 'x')
                _player.RevertHorizontalPosition();
            else
                _player.RevertVerticalPosition();
        }
    }

    // === Check bullet-wall collisions ===
    std::vector<int> bulletsToRemove;
    for(unsigned int i{0} ; i < _bulletManager.GetBulletsArray().size() ; ++i) {
        Bullet& bullet = _bulletManager.GetBulletsArray()[i];

        for(unsigned int n{0} ; n < _wallManager.GetWallsArray().size() ; ++n) {
            Wall& wall = _wallManager.GetWallsArray()[n];

            if(_collisionManager.AreColliding(bullet.GetRectangle(), wall.GetRectangle()))
                bulletsToRemove.push_back(i);   // The bullet will be removed
        }
    }
    bulletsToRemove.erase(std::unique(bulletsToRemove.begin(), bulletsToRemove.end()), bulletsToRemove.end());      // Removes duplicates
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)      // Remove bullet
        _bulletManager.RemoveBullet(bulletsToRemove[i]);

    // === Check for bullet-zombie collision ===
    bulletsToRemove.clear();
    std::vector<int> zombiesToRemove;

    for(unsigned int i{0} ; i < _bulletManager.GetBulletsArray().size() ; ++i) {
        Bullet& bullet = _bulletManager.GetBulletsArray()[i];

        for(unsigned int n{0} ; n < _zombieManager.GetZombiesArray().size() ; ++n) {
            Zombie& zombie = _zombieManager.GetZombiesArray()[n];

            if(_collisionManager.AreColliding(bullet.GetRectangle(), zombie.GetRectangle()))
            {
                bulletsToRemove.push_back(i);   // The bullet will be removed
                zombiesToRemove.push_back(n);   // The zombie will be killed
            }
        }
    }
    bulletsToRemove.erase(std::unique(bulletsToRemove.begin(), bulletsToRemove.end()), bulletsToRemove.end());  // Removes duplicates
    zombiesToRemove.erase(std::unique(zombiesToRemove.begin(), zombiesToRemove.end()), zombiesToRemove.end());  // Removes duplicates
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)  // Removes bullets
        _bulletManager.RemoveBullet(bulletsToRemove[i]);
    for(signed int n{zombiesToRemove.size()-1} ; n >= 0 ; --n)  // Removes zombies
        _zombieManager.RemoveZombie(zombiesToRemove[n]);
}