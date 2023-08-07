#include "game.hpp"
#include "raylib.h"
#include <iostream>

/// @brief ////////
double lastUpdateTime1 {0.0};
double lastUpdateTime2 {0.0};
/////////////////////



Game::Game() 
    : player(), 
      enemies(), // By directly initializing members, you avoid default construction followed by assignment, which can be less efficient.
      bullets()
{}


void Game::HandleInputs()
{
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {    
        Shoot();
    }
    if (IsKeyDown(KEY_W)) {
        float deplacementValue = player.GetSpeed() * GetFrameTime();
        player.SetyPosition(player.GetAttributes().y - deplacementValue);
        if (player.isColliding()) {
            player.SetyPosition(player.GetAttributes().y + deplacementValue); 
        }
    }
    if (IsKeyDown(KEY_D)) {
        float deplacementValue = player.GetSpeed() * GetFrameTime();
        player.SetxPosition(player.GetAttributes().x + deplacementValue);
        if (player.isColliding()) {
            player.SetxPosition(player.GetAttributes().x - deplacementValue);
        }
    }
    if (IsKeyDown(KEY_S)) {
        float deplacementValue = player.GetSpeed() * GetFrameTime();
        player.SetyPosition(player.GetAttributes().y + deplacementValue);
        if (player.isColliding()) {
            player.SetyPosition(player.GetAttributes().y - deplacementValue);
        }
    }
    if (IsKeyDown(KEY_A)) {
        float deplacementValue = player.GetSpeed() * GetFrameTime();
        player.SetxPosition(player.GetAttributes().x - deplacementValue);
        if (player.isColliding()) {
            player.SetxPosition(player.GetAttributes().x + deplacementValue);
        }
    };
}


void Game::Update()
{
    HandleInputs();

    CheckCollisionBallEnemy();

    player.Update();
    bullets.Update();

    enemies.Update(player.GetAttributes());
    if (EventTriggered(1, lastUpdateTime1)) {
        enemies.SpawnNewEnemy();
    }
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
    {
        bullets.ShootNewBullet(player.GetAttributes());
    } 
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
