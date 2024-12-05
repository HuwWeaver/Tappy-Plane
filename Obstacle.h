#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "Structs.h"

class Obstacle
{
public:
    Obstacle(Texture2D sprite);
    void SetInitialPosition(int winWidth, int winHeight);
    virtual void tick(float deltaTime);
    Line GetCollisionLine() {return collisionLine;};
    Vector2 GetPos() {return pos;};
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};

protected:
    Texture2D texture{};
    Rectangle spriteRect{};
    Vector2 pos{};
    Line collisionLine{};

    int speed{-200};
    float collisionPadding{10};
    bool  active{false};
};

#endif