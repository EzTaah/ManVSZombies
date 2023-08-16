#include "game.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <iostream>
#include <utility>
#include <algorithm>


/// PUBLIC /////////////////
Game::Game() 
    : gridManager(),
      inputManager(),
      player(),
      bulletManager(),
      zombieManager(),
      wallManager(),
      isGameOver(false)
{
    // Setup grid
    gridManager.InitGrid();
    grid = gridManager.GetGrid();

    // Setup camera
    renderer = Renderer(player.GetRectangle());

    // Setup walls
    wallManager.InitWalls(grid);

    // Setup collisionManager
    collisionManager = CollisionManager(grid);
}


void Game::Update() {
    HandleInputs();
    SetPotentialMovementEntities();

    UpdateEntitiesX();
    HandleCollisions('x');

    UpdateEntitiesY();
    HandleCollisions('y');
}


/// PRIVATE  /////////////////
void Game::HandleInputs()
{
    // Mouse management
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        if (EventTriggered(0.5, lastUpdateTimeEvent1)) 
            bulletManager.ShootNewBullet(player.GetRectangle(), player.GetRectangleInViewSpace());
    }

    // Keys management
    Vector2 playerPotentialMovement{0.0f, 0.0f};

    if(IsKeyDown(KEY_W)) 
        playerPotentialMovement.y -= player.GetSpeed();
    if(IsKeyDown(KEY_S))
        playerPotentialMovement.y += player.GetSpeed(); 
    if(IsKeyDown(KEY_A))
        playerPotentialMovement.x -= player.GetSpeed(); 
    if(IsKeyDown(KEY_D))
        playerPotentialMovement.x += player.GetSpeed(); 

    player.SetPotentialMovement(playerPotentialMovement);
}


void Game::SetPotentialMovementEntities()
{
    // Spawn new zombies if needed
    if (EventTriggered(10, lastUpdateTimeEvent1)) 
        zombieManager.SpawnNewZombie(gridManager.GetGridDimensions());

    zombieManager.SetupPotentialMovement(player.GetRectangle());

    bulletManager.SetupPotentialMovement();
}

void Game::UpdateEntitiesX()
{
    player.UpdateX();
    zombieManager.UpdateX();
    bulletManager.UpdateX();
}


void Game::UpdateEntitiesY()
{
    player.UpdateY();
    zombieManager.UpdateY();
    bulletManager.UpdateY();
}



void Game::HandleCollisions(char mode_)
{
    // Check for boundary collision
    if(collisionManager.IsOutsideBoundaryX(player.GetRectangle())) 
        player.ResetPositionX();
    if(collisionManager.IsOutsideBoundaryY(player.GetRectangle())) 
        player.ResetPositionY();

    
    // Check for player-zombie collision
    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i)
    {
        if(CheckCollisionRecs(player.GetRectangle(), zombieManager.GetZombiesArray()[i].GetRectangle()))
        {
            if(mode_ == 'x')
            {
                player.ResetPositionX();
                zombieManager.GetZombiesArray()[i].ResetPositionX();
            }
            else
            {
                player.ResetPositionY();
                zombieManager.GetZombiesArray()[i].ResetPositionY(); 
            }

        }
    }

    // Check for zombie-zombie collision
    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i) {
        Zombie& zombie1 = zombieManager.GetZombiesArray()[i];

        for(unsigned int k{i+1} ; k < zombieManager.GetZombiesArray().size() ; ++k) {
            Zombie& zombie2 = zombieManager.GetZombiesArray()[k];

            if(CheckCollisionRecs(zombie1.GetRectangle(), zombie2.GetRectangle()))
            {
                if(mode_ == 'x')
                {
                    if (zombie1.GetPotentialMovement().x * zombie2.GetPotentialMovement().x <= 0)
                    {   
                        // Si les 2 zombies vont dans des directions oppposées
                        zombie1.ResetPositionX();
                        zombie2.ResetPositionX();
                    }
                    else 
                    {
                        // Calculate which zombie is behind

                        // case where only zombie2 has moved
                        float oldZombie1PositionX{zombie1.GetPosition().x - zombie1.GetPotentialMovement().x};  

                        Rectangle oldZombie1Rectangle = {oldZombie1PositionX, zombie1.GetRectangle().y, zombie1.GetRectangle().width, zombie1.GetRectangle().width};

                        if(CheckCollisionRecs(oldZombie1Rectangle, zombie2.GetRectangle()))
                        {
                            // Zombie2 is behind
                            zombie2.ResetPositionX();
                        }
                        else
                        {
                            // zombie1 is behing
                            zombie1.ResetPositionX();
                        }
                    }
                }
                else
                {
                    if (zombie1.GetPotentialMovement().y * zombie2.GetPotentialMovement().y <= 0)
                    {   
                        // Si les 2 zombies vont dans des directions oppposées
                        zombie1.ResetPositionY();
                        zombie2.ResetPositionY();

                        // Est il en collision mtn ?

                    }
                    else 
                    {
                        // Calculate which zombie is behind

                        // case where only zombie2 has moved
                        float oldZombie1PositionY{zombie1.GetPosition().y - zombie1.GetPotentialMovement().y};  
                        Rectangle oldZombie1Rectangle = {zombie1.GetRectangle().x, oldZombie1PositionY, zombie1.GetRectangle().width, zombie1.GetRectangle().width};
                        if(CheckCollisionRecs(oldZombie1Rectangle, zombie2.GetRectangle()))
                        {
                            // Zombie2 is behind
                            zombie2.ResetPositionY();
                        }
                        else
                        {
                            // zombie1 is behing
                            zombie1.ResetPositionY();
                        }
                    }
                }
            }
        }
    }


    // Check for zombie-wall collsions

    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i)
    {
        for(unsigned int n{0} ; n < wallManager.GetWallsArray().size() ; ++n)
        {
            if(collisionManager.AreColliding(zombieManager.GetZombiesArray()[i].GetRectangle(), wallManager.GetWallsArray()[n].GetRectangle()))
            {
                if(mode_ == 'x')
                {
                    zombieManager.GetZombiesArray()[i].ResetPositionX();
                }
                else
                {
                    zombieManager.GetZombiesArray()[i].ResetPositionY();
                }
            }
        }
    }


    // Check for player-wall collisions
    for(unsigned int i{0} ; i < wallManager.GetWallsArray().size() ; ++i)
    {
        if(CheckCollisionRecs(player.GetRectangle(), wallManager.GetWallsArray()[i].GetRectangle()))
        {
            if(mode_ == 'x')
            {
                player.ResetPositionX();
            }
            else
            {
                player.ResetPositionY();
            }

        }
    }


    // Check bullet-wall collisions
    std::vector<int> bulletsToRemove;

    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        for(unsigned int n{0} ; n < wallManager.GetWallsArray().size() ; ++n)
        {
            if(collisionManager.AreColliding(bulletManager.GetBulletsArray()[i].GetRectangle(), wallManager.GetWallsArray()[n].GetRectangle()))
            {
                bulletsToRemove.push_back(i);   // The bullet will be removed
            }
        }
    }
    // Surpprime les doublons
    bulletsToRemove.erase(std::unique(bulletsToRemove.begin(), bulletsToRemove.end()), bulletsToRemove.end());

    // Remove bullet
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)
        bulletManager.RemoveBullet(bulletsToRemove[i]);



    //Check for bullet-zombie collision
    bulletsToRemove.clear();
    std::vector<int> zombiesToRemove;

    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        for(unsigned int n{0} ; n < zombieManager.GetZombiesArray().size() ; ++n)
        {
            if(collisionManager.AreColliding(bulletManager.GetBulletsArray()[i].GetRectangle(), zombieManager.GetZombiesArray()[n].GetRectangle()))
            {
                bulletsToRemove.push_back(i);   // The bullet will be removed
                zombiesToRemove.push_back(n);   // The zombie will be killed
            }
        }
    }
    // Surpprime les doublons
    bulletsToRemove.erase(std::unique(bulletsToRemove.begin(), bulletsToRemove.end()), bulletsToRemove.end());
    zombiesToRemove.erase(std::unique(zombiesToRemove.begin(), zombiesToRemove.end()), zombiesToRemove.end());

    // Remove bullet
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)
        bulletManager.RemoveBullet(bulletsToRemove[i]);

    // Kill zombie
    for(signed int n{zombiesToRemove.size()-1} ; n >= 0 ; --n)
        zombieManager.KillZombie(zombiesToRemove[n]);



    // Check for bullets boundary collision
    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        if(collisionManager.IsOutsideBoundaryY(bulletManager.GetBulletsArray()[i].GetRectangle())) 
            bulletManager.RemoveBullet(i);
    }

}







void Game::RenderScene()
{
    // std::cout << "----------------------------------------------" << std::endl;
    // std::cout << "X Camera position : " << renderer.camera.GetPosition().x << std::endl;
    // std::cout << "Y Camera position : " << renderer.camera.GetPosition().y << std::endl;

    // std::cout << "X lLayer position : " << player.GetPosition().x << std::endl;
    // std::cout << "Y Player position : " << player.GetPosition().y << std::endl;

    // std::cout << "X Player positionInViewSpace : " << player.GetPositionInViewSpace().x << std::endl;
    // std::cout << "Y Player positionInViewSpace : " << player.GetPositionInViewSpace().y << std::endl;
    // std::cout << "----------------------------------------------" << std::endl;


    renderer.UpdateCamera(player.GetRectangle());
    renderer.UpdateAllEntitiesPositionInViewSpace(gridManager, player, bulletManager.GetBulletsArray(), zombieManager.GetZombiesArray(), wallManager.GetWallsArray());
    renderer.Draw(gridManager, player, bulletManager.GetBulletsArray(), zombieManager.GetZombiesArray(), wallManager.GetWallsArray());
}
