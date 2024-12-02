#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character
{
public:
    Character(int winWidth, int winHeight);
    ~Character();
    bool IsOnGround(int winHeight);
    void tick(float deltaTime, int winHeight);
    Rectangle GetCollisionRect() {return collisionRect;};

protected:
    Texture2D texture{};
    Rectangle spriteRect{}, collisionRect{};
    Vector2 pos{};

    int frame{0};
    int maxFrame{3};
    float updateTime{1.0/12.0};
    float runningTime{0.0};

    const int jumpVel{-600};
    int yVelocity{0};
    const int gravity{1000};
};

#endif