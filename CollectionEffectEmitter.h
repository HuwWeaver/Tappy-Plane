#ifndef COLLECTION_EFFECT_EMITTER_H
#define COLLECTION_EFFECT_EMITTER_H

#include "raylib.h"
#include "CollectionEffectParticle.h"
 
class CollectionEffectEmitter
{
public:
    CollectionEffectEmitter(Texture2D sprite);
    void SpawnParticles(Vector2 newPos);
    void tick();

private:
    CollectionEffectParticle particlePool[5]; 
    Vector2 pos{};
};

#endif