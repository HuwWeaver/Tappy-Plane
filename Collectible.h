#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "raylib.h"
#include "Structs.h"

class Collectible
{
public:
    Collectible();
    void Init(Texture2D sprite, Vector2 winSize);
    void tick(float deltaTime);
    Circle GetCollisionCircle() {return collisionCircle;};
    bool GetActive() {return active;};
    void Activate();
    void Reset();

protected:
    Texture2D texture{};
    Vector2 pos{}, windowDimensions{};
    Circle collisionCircle{};

    float speed{200};
    bool active{false};
};

#endif