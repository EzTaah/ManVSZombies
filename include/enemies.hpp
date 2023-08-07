#pragma once
#include "entity.hpp"
#include "library.hpp"
#include "enemy.hpp"
#include "raylib.h"
#include <vector>


class Enemies : public Entity
{
    public:
        Enemies();
        void Update(EntityAttributes playerAttributes);
        void Draw() const override;
        void SpawnNewEnemy();
        std::vector<Enemy> GetEnemiesArray();
        void RemoveElementEnemiesArray(int index);

    private:
        std::vector<Enemy> enemiesArray;
};