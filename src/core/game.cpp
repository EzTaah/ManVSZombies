#include "game.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <iostream>
#include <utility>


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
    HandleCollisionsX();

    UpdateEntitiesY();
    HandleCollisionsY();
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
        zombieManager.SpawnNewZombie();

    zombieManager.SetupPotentialMovement(player.GetRectangle());

    bulletManager.SetupPotentialMovement();
}

void Game::UpdateEntitiesX()
{
    player.UpdateX();
    zombieManager.UpdateX();
    bulletManager.UpdateX();
}


void Game::HandleCollisionsX()
{

    if(collisionManager.IsOutsideBoundaryX(player.GetRectangle())) 
       player.ResetPositionX();
    
    
    // Check for bullets boundary collision
    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        if(collisionManager.IsOutsideBoundaryX(bulletManager.GetBulletsArray()[i].GetRectangle())) 
            bulletManager.RemoveBullet(i);
    }


    // Check for player-zombie collision
    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i)
    {
        if(CheckCollisionRecs(player.GetRectangle(), zombieManager.GetZombiesArray()[i].GetRectangle()))
        {
            player.ResetPositionX();
            zombieManager.GetZombiesArray()[i].ResetPositionX();
        }
    }


    // Check for ball-zombie collision
    std::vector<int> bulletsToRemove;
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
    // Remove bullet
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)
        bulletManager.RemoveBullet(bulletsToRemove[i]);

    // Kill zombie
    for(signed int n{zombiesToRemove.size()-1} ; n >= 0 ; --n)
        zombieManager.KillZombie(zombiesToRemove[n]);

}


void Game::UpdateEntitiesY()
{
    player.UpdateY();
    zombieManager.UpdateY();
    bulletManager.UpdateY();
}



void Game::HandleCollisionsY()
{
    if(collisionManager.IsOutsideBoundaryY(player.GetRectangle())) 
        player.ResetPositionY();

    
    // Check for bullets boundary collision
    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        if(collisionManager.IsOutsideBoundaryY(bulletManager.GetBulletsArray()[i].GetRectangle())) 
            bulletManager.RemoveBullet(i);
    }


    // Check for player-zombie collision
    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i)
    {
        if(CheckCollisionRecs(player.GetRectangle(), zombieManager.GetZombiesArray()[i].GetRectangle()))
        {
            player.ResetPositionY();
            zombieManager.GetZombiesArray()[i].ResetPositionY();
        }
    }


    //Check for ball-zombie collision
    std::vector<int> bulletsToRemove;
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
    // Remove bullet
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)
        bulletManager.RemoveBullet(bulletsToRemove[i]);

    // Kill zombie
    for(signed int n{zombiesToRemove.size()-1} ; n >= 0 ; --n)
        zombieManager.KillZombie(zombiesToRemove[n]);

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
