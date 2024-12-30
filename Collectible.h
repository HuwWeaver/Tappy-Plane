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
    void SetActive(bool newActive) {active = newActive;};
    void SetPosition(Vector2 newPos) {pos = newPos;};
    void Reset();

    bool active{false};
    
protected:
    Texture2D texture{};
    Vector2 pos{}, windowSize{};
    Circle collisionCircle{};

    float speed{200};
};

#endif