#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"

class Obstacle
{
public:
    Obstacle(Texture2D sprite);
    void SetInitialPosition(int winWidth, int winHeight);
    virtual void tick(float deltaTime);
    Rectangle GetCollisionRect() {return collisionRect;};
    Vector2 GetPos() {return pos;};
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};

protected:
    Texture2D texture{};
    Rectangle spriteRect{};
    Vector2 pos{};

    int speed{-200};
    float pad{50};
    Rectangle collisionRect{};
    bool  active{false};
};

#endif