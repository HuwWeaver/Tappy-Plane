#ifndef COLLECTION_EFFECT_PARTICLE_H
#define COLLECTION_EFFECT_PARTICLE_H

#include "raylib.h"

class CollectionEffectParticle
{
public:
    void Init(Texture2D sprite);
    void tick();
    void Spawn(Vector2 startPos);

private:
    Texture2D texture{};
    bool active{false};
    Vector2 pos{};
    float xVelocity{}, yVelocity{};
    const int gravity{500}, xDrag{300};
    float lifetime{3.0}, rotation{0}, scale{0.3};
};

#endif