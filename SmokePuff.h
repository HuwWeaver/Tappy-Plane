#ifndef SMOKE_PUFF_H
#define SMOKE_PUFF_H

#include "raylib.h"

class SmokePuff
{
public:
    SmokePuff();
    void Init(const Texture2D& sprite);
    void tick(const float& deltaTime);
    bool GetActive() {return active;};
    void Activate(const Vector2& newPos);
    void Reset();

protected:
    const Texture2D* texture{};
    Vector2 pos{};
    float colorLerpFactor{1.0},  fadeSpeed{0.8};
    int xSpeed{-200}, ySpeed{-10};
    bool active{false};
};

#endif