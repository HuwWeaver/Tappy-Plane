#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "Structs.h"

class Obstacle
{
public:
    Obstacle();
    void Init(const Texture2D& sprite, const Vector2& winSize);
    virtual void tick(const float& deltaTime);
    Line GetCollisionLine() {return collisionLine;};
    bool GetActive() {return active;};
    void Activate();
    void Reset();
    bool hasPassedChar(const float& charXPos);
    virtual void ResetPosition();

protected:
    const Texture2D* texture{};
    Vector2 pos{};
    const Vector2* windowDimensions;
    Line collisionLine{};

    int speed{200};
    bool active{false}, scoreAdded{false};
};

#endif