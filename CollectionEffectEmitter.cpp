#include "CollectionEffectEmitter.h"

CollectionEffectEmitter::CollectionEffectEmitter(Texture2D sprite)
{
    for (auto& particle : particlePool)
    {
        particle.Init(sprite);
    }
};

void CollectionEffectEmitter::SpawnParticles(Vector2 newPos)
{
    pos = newPos;

    for (auto& particle : particlePool)
    {
        particle.Spawn(pos);
    }
}

void CollectionEffectEmitter::tick()
{
    for (auto& particle : particlePool)
    {
        particle.tick();
    }
    
    //DEBUG CIRCLE
    //DrawCircle(pos.x, pos.y, 5, RED);
}