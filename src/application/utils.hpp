#pragma once


namespace ut
{

// =========================== MATH ===========================
int GetRandomNumber(int min, int max);

// ============================================================




// =========================== OTHER ===========================
struct Vector2f {
    float x,
    float y
}

struct Rectanglef {
    float width,
    float height,
    float x,
    float y
}


bool EventTriggered(double interval, double& lastUpdateTime);

// ============================================================

}