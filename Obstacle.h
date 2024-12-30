#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "Structs.h"

class Obstacle
{
public:
    Obstacle();
    void Init(Texture2D sprite, int winWidth, int winHeight);
    virtual void SetStartPosition(int winWidth, int winHeight);
    virtual void tick(float deltaTime);
    Line GetCollisionLine() {return collisionLine;};
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};
    void Reset(int winWidth, int winHeight);
    bool hasPassedChar(float charXPos);

protected:
    Texture2D texture{};
    Vector2 pos{};
    Line collisionLine{};

    int speed{200};
    bool active{false}, scoreAdded{false};
};

#endif