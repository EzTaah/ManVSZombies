#pragma once
#include "player.hpp"
#include "enemies.hpp"
#include "bullets.hpp"
#include "library.hpp"


class Game
{
    public:
        Game();
        void Draw();
        void Update();
        void CheckCollisionBallEnemy();
        void CheckCollisionPlayerEnemy();

    private:
        void HandleInputs();
        void Shoot();

        Player player;
        Enemies enemies;
        Bullets bullets;
};