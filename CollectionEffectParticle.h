#ifndef COLLECTION_EFFECT_PARTICLE_H
#define COLLECTION_EFFECT_PARTICLE_H

#include "raylib.h"

class CollectionEffectParticle
{
public:
    void Init(const Texture2D& sprite);
    void tick(const float& deltaTime);
    void Spawn(const Vector2& startPos);
    void Reset() {active = false;};

private:
    const Texture2D* texture{};
    bool active{false};
    Vector2 pos{};
    float xVelocity{}, yVelocity{};
    const int gravity{500};
    float lifetime{3.0}, rotation{0}, scale{0.3};
};

#endif