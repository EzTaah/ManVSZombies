#include "game.hpp"
#include <raylib.hpp>
#include <iostream>

/// @brief ////////
double lastUpdateTime1 {0.0};
double lastUpdateTime2 {0.0};
/////////////////////


// By directly initializing members, you avoid default construction followed by assignment, which can be less efficient.
Game::Game() 
    : inputManager(), player(), bulletManager(), collisionManager()
{
    zombieManager = ZombieManager(player.GetRectangle());
}


void Game::Update()
{
    HandleInputs();

    bulletManager.Update();




    CheckCollisionBallEnemy();




    enemies.Update(player.GetAttributes());
    if (EventTriggered(1, lastUpdateTime1)) 
        enemies.SpawnNewEnemy();
}

void Game::Draw()
{
    player.Draw();
    enemies.Draw();
    bullets.Draw();
}

void Game::Shoot()
{
    if (EventTriggered(0.3, lastUpdateTime2))
        bullets.ShootNewBullet(player.GetAttributes());
}



void Game::HandleInputs()
{
    // Mouse management
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))     
        bulletManager.ShootNewBullet(player.GetRectangle());

    // Keys management
    Vector2 potentialMovement{0.0f, 0.0f};
    float frameTime = GetFrameTime();

    if(IsKeyDown(KEY_W)) 
        potentialMovement.y -= player.GetSpeed() * frameTime;
    if(IsKeyDown(KEY_S))
        potentialMovement.y += player.GetSpeed() * frameTime; 
    if(IsKeyDown(KEY_A))
        potentialMovement.x -= player.GetSpeed() * frameTime; 
    if(IsKeyDown(KEY_D))
        potentialMovement.x += player.GetSpeed() * frameTime; 

    // Check for boundary
    if(collisionManager.IsOutsideScreenX(player, potentialMovement.x)) 
        potentialMovement.x = 0.0f;
    if(collisionManager.IsOutsideScreenY(player, potentialMovement.y)) 
        potentialMovement.y = 0.0f;

    // Check for wall
    // -> manage wall collision

    // Check for zombie collision
    if(zombieManager.ZombiesAreCollidingWithPlayer(player, potentialMovement.x))
    {
        collisionManager.ManageZombieCollision();
        potentialMovement = {0.0f, 0.0f};
    }

    // Move the player
    player.MoveBy(potentialMovement);
}










void Game::CheckCollisionBallEnemy()
{
    bool leave{false};
    for (signed int e{static_cast<signed int>(enemies.GetEnemiesArray().size()-1)} ; e >= 0 ; e--)
    {
        for (signed int b{static_cast<signed int>(bullets.GetBulletsArray().size()-1)} ; b >= 0 ; b--)
        {
            std::cout << 'e' << e << std::endl;
            std::cout << 'b' << e << std::endl;
            if (CheckCollisionRecs(bullets.GetBulletsArray()[b].GetRectangle(), enemies.GetEnemiesArray()[e].GetRectangle()))
            {
                leave = true;
                bullets.RemoveElementBulletsArray(b);
                enemies.RemoveElementEnemiesArray(e);
                break;
            }
        }
        if (leave) {
            leave = false;
            break;
        }
    }
}



// void Game::CheckCollisionPlayerEnemy()
// {
//     for (signed int e{static_cast<signed int>(enemies.GetEnemiesArray().size()-1)} ; e >= 0 ; e--)
//     {
//         if (CheckCollisionRecs(player.GetRectangle(), enemies.GetEnemiesArray()[e].GetRectangle()))
//         {
//             bullets.RemoveElementBulletsArray(b);
//             enemies.RemoveElementEnemiesArray(e);
//             break;
//         }
//     }
// }
