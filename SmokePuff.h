#ifndef SMOKE_PUFF_H
#define SMOKE_PUFF_H

#include "raylib.h"

class SmokePuff
{
public:
    SmokePuff();
    ~SmokePuff();
    void Init(const char *textureFilePath, Vector2 startPos);
    void tick(float deltaTime);
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};
    void SetPosition(Vector2 newPos) {pos = newPos;};
    void Reset();

protected:
    Texture2D texture{};
    Vector2 pos{};
    float opacity{255.0};
    int xSpeed{-200}, ySpeed{-10}, fadeSpeed{100};
    bool active{false};
};

#endif