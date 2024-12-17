#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "Structs.h"

class Obstacle
{
public:
    Obstacle();
    ~Obstacle();
    void Init(const char *textureFilePath, int winWidth, int winHeight);
    virtual void SetStartPosition(int winWidth, int winHeight);
    virtual void tick(float deltaTime);
    Line GetCollisionLine() {return collisionLine;};
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};
    void Reset(int winWidth, int winHeight);

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