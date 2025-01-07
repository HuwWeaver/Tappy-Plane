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
        particle.Spawn(pos, 50, GetRandomValue(-300, 50));
    }
}

void CollectionEffectEmitter::tick()
{
    for (auto& particle : particlePool)
    {
        particle.tick();
    }
    
    DrawCircle(pos.x, pos.y, 5, RED);
}