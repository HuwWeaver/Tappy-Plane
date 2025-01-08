#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include "Structs.h"
#include "SmokePuff.h"

class Character
{
public:
    Character(Vector2 winSize);
    ~Character();
    bool OutOfBounds(int winHeight);
    void tick(float deltaTime, int winHeight);
    Circle GetCollisionCircle() {return collisionCircle;};
    void Reset();
    Vector2 GetPosition(){return pos;};

protected:
    Texture2D texture{}, smokePuffTexture{};
    Sound jumpSFX{};
    Rectangle spriteRect{};
    Vector2 pos{}, windowDimensions{};
    Circle collisionCircle{};

    int frame{0};
    int maxFrame{3};
    float updateTime{1.0/12.0};
    float runningTime{0.0};

    const int jumpVel{-500};
    int yVelocity{0};
    const int gravity{1000};

    SmokePuff smokePuffPool[5];
};

#endif