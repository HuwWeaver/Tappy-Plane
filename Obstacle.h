#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "raylib.h"
#include "Structs.h"

class Obstacle
{
public:
    Obstacle();
    void Init(Texture2D lowerSprite, Texture2D upperSprite, int winWidth, int winHeight);
    void SetStartPosition(int winWidth, int winHeight);
    virtual void tick(float deltaTime);
    Line GetCollisionLine() {return lowerCollisionLine;};
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};

protected:
    Texture2D lowerTexture{}, upperTexture{};
    Rectangle spriteRect{};
    float xPos{}, lowerSpritePosY{}, upperSpritePosY{};
    Line lowerCollisionLine{}, upperCollisionLine{};

    int speed{-200};
    float collisionPadding{10};
    bool  active{false};
};

#endif