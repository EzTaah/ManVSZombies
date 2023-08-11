#include "enemies.hpp"
#include <iostream>
#include "raylib.h"


Enemies::Enemies() {}


void Enemies::Update(EntityAttributes playerAttributes)
{
    int n = 0;
    for (Enemy& elt : enemiesArray)
    {
        elt.Update(playerAttributes);
        n++;
    }
}


void Enemies::Draw() const
{
    for (const Enemy& elt : enemiesArray)
    {
        elt.Draw();
    }
}


void Enemies::SpawnNewEnemy()
{
    Vector2 enemyPosition;

    // which side
    switch (myUtils::GetRandomNumber(0, 3))
    {
        case 0:
            std::cout << "0" << std::endl;
            enemyPosition.x = -30;
            enemyPosition.y = myUtils::GetRandomNumber(0, GetScreenHeight());
            break;

        case 1:
            std::cout << "1" << std::endl;
            enemyPosition.x = GetScreenWidth();
            enemyPosition.y = myUtils::GetRandomNumber(0, GetScreenHeight());
            break;

        case 2:
            std::cout << "2" << std::endl;
            enemyPosition.x = myUtils::GetRandomNumber(0, GetScreenWidth());
            enemyPosition.y = -30;
            break;

        case 3:
            std::cout << "3" << std::endl;
            enemyPosition.x = myUtils::GetRandomNumber(0, GetScreenWidth());
            enemyPosition.y = GetScreenHeight();
            break;
    }

    enemiesArray.push_back(Enemy(enemyPosition));
}


std::vector<Enemy> Enemies::GetEnemiesArray()
{
    return enemiesArray;
}



void Enemies::RemoveElementEnemiesArray(int index)
{
    enemiesArray.erase(enemiesArray.begin() + index);
}