#include "Game.hpp"
// #include <utility>
// #include <algorithm>
#include "SFML/Graphics.hpp"


///////////////// PUBLIC /////////////////
Game::Game(sf::RenderWindow* windowPtr) 
    : _lastUpdateTimeEvent1(0.0),
      _lastUpdateTimeEvent2(0.0),
      _windowPtr(windowPtr),
      _staticEntitiesArray(),
      _movingEntitiesArray(),
      _grid(),
      _player({500.0f, 600.0f}),
      _bulletManager(&_movingEntitiesArray),
      _zombieManager(&_movingEntitiesArray),
      _wallManager(&_staticEntitiesArray, _grid.GetGrid()),     // Init all the walls
      _collisionManager(),
      _renderer(_player.GetRectangle())     // Setup camera
{
    // Add the player to the entity array
    _movingEntitiesArray.push_back(&_player);   // On ajoute au tableau l'adresse de l'instance _player
}


void Game::Update() {
    // === Manage zombies spawn ===
    if (ut::EventTriggered(0.5, _lastUpdateTimeEvent2)) 
        _zombieManager.SpawnNewZombie(_grid.GetGrid(), _grid.GetNumberOfTiles());

    // === Handle inputs ===
    _HandleInputs();

    // === Calculate next move entities ===
    _zombieManager.CalculateNextMoveZombies(_player.GetRectangle());
    _bulletManager.CalculateNextMoveBullets();

    // === Manage horizontal deplacement ===
    for(MovingEntity* movingEntity : _movingEntitiesArray)
        movingEntity->UpdateHorizontalPosition();

    _HandleCollisions('x');

    // === Manage vertical deplacement ===
    for(MovingEntity* movingEntity : _movingEntitiesArray)
        movingEntity->UpdateVerticalPosition();

    _HandleCollisions('y');
}


void Game::Render()
{
    _renderer.UpdateCameraPosition(_player.GetRectangle());
    _renderer.UpdatePositionInViewSpaceEntities(_grid, _player, _bulletManager, _zombieManager, _wallManager);

    _renderer.Render(_windowPtr, &_movingEntitiesArray, &_staticEntitiesArray, _grid);
}



///////////////// PRIVATE /////////////////
void Game::_HandleInputs()
{
    // Mouse management
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (ut::EventTriggered(0.1, _lastUpdateTimeEvent1)) 
            _bulletManager.ShootNewBullet(_windowPtr, _player.GetRectangle(), _player.GetRectangleInViewSpace());
    }

    // Keys management
    ut::Vector2f playerPotentialMovement{0.0f, 0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        playerPotentialMovement.y -= _player.GetSpeed().y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        playerPotentialMovement.y += _player.GetSpeed().y; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        playerPotentialMovement.x -= _player.GetSpeed().x; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        playerPotentialMovement.x += _player.GetSpeed().x; 

    _player.SetPotentialMovement(playerPotentialMovement);
}



void Game::_HandleCollisions(char mode)
{
    // === Check for player-boundary collision ===
    if(_collisionManager.IsOutsideBoundaryX(_player.GetRectangle(), _grid.GetGridDimensions().x)) 
        _player.RevertHorizontalPosition();
    if(_collisionManager.IsOutsideBoundaryY(_player.GetRectangle(), _grid.GetGridDimensions().y))
        _player.RevertVerticalPosition();

    // === Check for bullet-boundary collision ===
    for(unsigned int i{0} ; i < _bulletManager.GetBulletsArray().size() ; ++i)
    {
        bool isOutsideBoundaryX = _collisionManager.IsOutsideBoundaryX(_bulletManager.GetBulletsArray()[i].GetRectangle(), _grid.GetGridDimensions().x);
        bool isOutsideBoundaryY = _collisionManager.IsOutsideBoundaryY(_bulletManager.GetBulletsArray()[i].GetRectangle(), _grid.GetGridDimensions().y);
        if(isOutsideBoundaryX || isOutsideBoundaryY) 
            _bulletManager.RemoveBullet(i);
    }

    // === Check for player-zombie collision ===
    for(unsigned int i{0} ; i < _zombieManager.GetZombiesArray().size() ; ++i)
    {
        Zombie& zombie = _zombieManager.GetZombiesArray()[i];
        if(_collisionManager.AreColliding(_player.GetRectangle(), zombie.GetRectangle()))
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

            if(_collisionManager.AreColliding(zombie1.GetRectangle(), zombie2.GetRectangle()))
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
                        ut::Rectanglef oldZombie1Rectangle = {oldZombie1PositionX, zombie1.GetRectangle().y, zombie1.GetRectangle().width, zombie1.GetRectangle().width};

                        if(_collisionManager.AreColliding(oldZombie1Rectangle, zombie2.GetRectangle()))     // If it is true, the zombie2 is behind
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
                        ut::Rectanglef oldZombie1Rectangle = {zombie1.GetRectangle().x, oldZombie1PositionY, zombie1.GetRectangle().width, zombie1.GetRectangle().width};

                        if(_collisionManager.AreColliding(oldZombie1Rectangle, zombie2.GetRectangle()))     // If it is true, the zombie2 is behind
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
        if(_collisionManager.AreColliding(_player.GetRectangle(), wall.GetRectangle()))
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