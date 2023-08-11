#pragma once

bool EventTriggered(double interval, double& lastUpdateTime);

typedef struct EntityAttributes {
    float x;
    float y;
    float width;
    float height;
} EntityAttributes;



namespace myUtils
{
    float random(int begin, int end);
    int GetRandomNumber(int min, int max);
}