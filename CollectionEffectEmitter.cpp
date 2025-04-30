#include "CollectionEffectEmitter.h"

CollectionEffectEmitter::CollectionEffectEmitter(const Texture2D& sprite)
{
    for (auto& particle : particlePool)
    {
        particle.Init(sprite);
    }
};

void CollectionEffectEmitter::SpawnParticles(const Vector2& pos)
{
    for (auto& particle : particlePool)
    {
        particle.Spawn(pos);
    }
}

void CollectionEffectEmitter::tick(const float& deltaTime)
{
    for (auto& particle : particlePool)
    {
        particle.tick(deltaTime);
    }
    
    //DEBUG CIRCLE
    //DrawCircle(pos.x, pos.y, 5, RED);
}

void CollectionEffectEmitter::Reset()
{
    for (auto& particle : particlePool)
    {
        particle.Reset();
    }
}