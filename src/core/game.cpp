#include "game.hpp"
#include <raylib.hpp>
#include <iostream>


/// PUBLIC /////////////////
Game::Game() 
    : inputManager(), player(), bulletManager(), collisionManager(), isGameOver(false)
{
    zombieManager = ZombieManager(player.GetRectangle());
}


void Game::Update() {
    HandleInputs();
    UpdateEntities();
    HandleCollisions();
}


void Game::RenderScene()
{
    BeginDrawing();
    ClearBackground(BROWN);
    
    player.Draw();

    EndDrawing();
}


/// PRIVATE  /////////////////
void Game::HandleInputs()
{
    // Mouse management
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))     
        bulletManager.ShootNewBullet(player.GetRectangle());

    // Keys management
    Vector2 playerPotentialMovement{0.0f, 0.0f};
    float frameTime = GetFrameTime();

    if(IsKeyDown(KEY_W)) 
        playerPotentialMovement.y -= player.GetSpeed() * frameTime;
    if(IsKeyDown(KEY_S))
        playerPotentialMovement.y += player.GetSpeed() * frameTime; 
    if(IsKeyDown(KEY_A))
        playerPotentialMovement.x -= player.GetSpeed() * frameTime; 
    if(IsKeyDown(KEY_D))
        playerPotentialMovement.x += player.GetSpeed() * frameTime; 

    player.SetPotentialMovement(playerPotentialMovement);
}


void Game::UpdateEntities()
{
    player.MoveBy(player.GetPotentialMovement());
    zombieManager.Update();
    bulletManager.Update();
}


void Game::HandleCollisions()
{
    // Check for player boundary collision
    if(collisionManager.IsOutsideScreenX(player.GetRectangle())) 
       player.ResetPositionX();
    if(collisionManager.IsOutsideScreenY(player.GetRectangle())) 
        player.ResetPositionY();

    
    // Check for bullets boundary collision
    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        if(collisionManager.IsOutsideScreen(bulletManager.GetBulletsArray()[i].GetRectangle())) 
            bulletManager.RemoveBullet(i);
    }

    // Check for player-zombie collision
    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i)
    {
        if(collisionManager.AreColliding(player.GetRectangle(), zombieManager.GetZombiesArray()[i].GetRectangle()))
        {
            // Reset player movement
            player.ResetPositionX();
            player.ResetPositionY();

            // Reset zombie movement
            // ->
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
    for(unsigned int i{0} ; i < bulletsToRemove.size() ; ++i)
        bulletManager.RemoveBullet(i);

    // Kill zombie
    for(unsigned int n{0} ; n < bulletsToRemove.size() ; ++n)
        zombieManager.KillZombie(n);
}