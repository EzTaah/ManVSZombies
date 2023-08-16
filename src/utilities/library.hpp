#pragma once
#include <utility>

// Utils
bool EventTriggered(double interval_, double& lastUpdateTime_);


namespace myUtils
{
    // Face class
    enum class Face {
        TOP,
        BOTTOM,
        LEFT,
        RIGHT,
        NONE
    };

    // GetRandomNumber function
    int GetRandomNumber(int min, int max);


}