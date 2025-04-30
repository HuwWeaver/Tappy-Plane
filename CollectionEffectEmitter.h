#ifndef COLLECTION_EFFECT_EMITTER_H
#define COLLECTION_EFFECT_EMITTER_H

#include "raylib.h"
#include "CollectionEffectParticle.h"
 
class CollectionEffectEmitter
{
public:
    CollectionEffectEmitter(const Texture2D& sprite);
    void SpawnParticles(const Vector2& pos);
    void tick(const float& deltaTime);
    void Reset();

private:
    CollectionEffectParticle particlePool[5];
};

#endif