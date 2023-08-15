#include "game.hpp"
#include "library.hpp"
#include <raylib.hpp>
#include <iostream>


/// PUBLIC /////////////////
Game::Game() 
    : gridManager(),
      inputManager(),
      player(),
      bulletManager(),
      zombieManager(),
      wallManager(),
      collisionManager(),
      isGameOver(false)
{
    // Setup grid
    gridManager.InitGrid();
    grid = gridManager.GetGrid();

    // Setup walls
    wallManager.InitWalls(grid);

    // Setup camera
    renderer = Renderer(player.GetRectangle());

}


void Game::Update() {
    HandleInputs();
    UpdateEntities();
    HandleCollisions();
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
    zombieManager.Update(player.GetRectangle());
    bulletManager.Update();
}


void Game::HandleCollisions()
{
    // Check for player boundary collision
    //if(collisionManager.IsOutsideBoundaryX(player.GetRectangle())) 
    if(false)
       player.ResetPositionX();
    // if(collisionManager.IsOutsideBoundaryY(player.GetRectangle())) 
    if(false)
        player.ResetPositionY();

    
    // Check for bullets boundary collision
    for(unsigned int i{0} ; i < bulletManager.GetBulletsArray().size() ; ++i)
    {
        //if(collisionManager.IsOutsideBoundary(bulletManager.GetBulletsArray()[i].GetRectangle())) 
        if(false)
            bulletManager.RemoveBullet(i);
    }

    // Check for player-zombie collision
    for(unsigned int i{0} ; i < zombieManager.GetZombiesArray().size() ; ++i)
    {
        if(collisionManager.AreColliding(player.GetRectangle(), zombieManager.GetZombiesArray()[i].GetRectangle()))
        {
            // Reset player movement
            //player.ResetPositionX();
            //player.ResetPositionY();

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
    for(signed int i{bulletsToRemove.size()-1} ; i >= 0 ; --i)
        bulletManager.RemoveBullet(bulletsToRemove[i]);

    // Kill zombie
    for(signed int n{zombiesToRemove.size()-1} ; n >= 0 ; --n)
        zombieManager.KillZombie(zombiesToRemove[n]);
}