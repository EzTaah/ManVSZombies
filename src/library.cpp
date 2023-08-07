#include "../include/library.hpp"
#include <cmath>
#include <cstdlib>
#include "../include/raylib.h"
#include <iostream>
#include <random>


bool EventTriggered(double interval, double& lastUpdateTime)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


float myUtils::random(int begin, int end)
{
    // Providing a seed value (using time() so each time it's different)
	srand((unsigned) time(NULL));
	// Get a random number
	int randomNumber = rand();

    return begin + randomNumber % (end-begin+1);
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