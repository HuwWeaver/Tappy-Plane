#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "Structs.h"

class Obstacle
{
public:
    Obstacle();
    void Init(Texture2D sprite, Vector2 winSize);
    virtual void tick(float deltaTime);
    Line GetCollisionLine() {return collisionLine;};
    bool GetActive() {return active;};
    void Activate();
    void Reset();
    bool hasPassedChar(float charXPos);
    virtual void ResetPosition();

protected:
    Texture2D texture{};
    Vector2 pos{}, windowDimensions{};
    Line collisionLine{};

    int speed{200};
    bool active{false}, scoreAdded{false};
};

#endif