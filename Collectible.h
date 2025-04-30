#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include "raylib.h"
#include "Structs.h"

class Collectible
{
public:
    Collectible();
    void Init(const Texture2D& sprite, const Sound& sfx, const Vector2& winSize);
    void tick(const float& deltaTime);
    Circle GetCollisionCircle() {return collisionCircle;};
    Vector2 GetPosition() {return pos;};
    bool GetActive() {return active;};
    void Activate();
    void Collect();
    void Reset();

protected:
    const Texture2D* texture{};
    const Sound* collectionSFX{};
    Vector2 pos{};
    const Vector2* windowDimensions{};
    Circle collisionCircle{};

    float speed{200}, rotation{0.0}, rotationSpeed{50};
    bool active{false};
};

#endif