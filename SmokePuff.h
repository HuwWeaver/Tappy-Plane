#ifndef SMOKE_PUFF_H
#define SMOKE_PUFF_H

#include "raylib.h"

class SmokePuff
{
public:
    SmokePuff();
    void Init(Texture2D sprite);
    void tick(float deltaTime);
    bool GetActive() {return active;};
    void Activate(Vector2 newPos);
    void Reset();

protected:
    Texture2D texture{};
    Vector2 pos{};
    float colorLerpFactor{1.0},  fadeSpeed{0.8};
    int xSpeed{-200}, ySpeed{-10};
    bool active{false};
};

#endif