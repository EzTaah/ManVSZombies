#include <cmath>
#include <iostream>
#include <random>
#include <raylib.hpp>
#include "library.hpp"



bool EventTriggered(double interval_, double& lastUpdateTime_)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime_ >= interval_)
    {
        lastUpdateTime_ = currentTime;
        return true;
    }
    return false;
}


int myUtils::GetRandomNumber(int min, int max)
{
    // static is used to instantiate the random engine and distribution once only.
    // It then generates a new random number on subsequent calls.
    static std::random_device rd;
    static std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(min, max);

    return distr(eng);
}