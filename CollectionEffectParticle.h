#ifndef COLLECTION_EFFECT_PARTICLE_H
#define COLLECTION_EFFECT_PARTICLE_H

#include "raylib.h"

class CollectionEffectParticle
{
public:
    void Init(Texture2D sprite);
    void tick();
    void Spawn(Vector2 startPos, float startXVelocity, float startYVelocity);

private:
    Texture2D texture{};
    Vector2 pos{};
    float xVelocity{}, yVelocity{};
    const int gravity{1000}, xDrag{300};
    float lifetime{3.0}, rotation{0}, scale{0.3};
};

#endif