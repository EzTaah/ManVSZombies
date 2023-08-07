#pragma once
#include "entity.hpp"
#include "library.hpp"
#include "bullet.hpp"
#include "../include/raylib.h"
#include <vector>


class Bullets : public Entity
{
    public:
        Bullets();
        void ShootNewBullet(EntityAttributes playerAttributes);
        void Update();
        void Draw() const override;

        std::vector<Bullet> GetBulletsArray();
        void RemoveElementBulletsArray(int index);

    private:
        Vector2 playerPosition;
        Vector2 enemyPosition;

        std::vector<Bullet> bulletsArray;
        float bulletSpeed;
};