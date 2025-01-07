#include "CollectionEffectParticle.h"
#include "raymath.h"
#include <raymath.h>

void CollectionEffectParticle::Init(Texture2D sprite)
{
    texture = sprite;
}

void CollectionEffectParticle::Spawn(Vector2 startPos)
{
    active = true;
    lifetime = GetRandomValue(5, 8)/10.0f;
    pos = startPos;
    xVelocity = GetRandomValue(-100, 100);
    yVelocity = GetRandomValue(-300, 50);
    rotation = GetRandomValue(0, 360);
    scale = GetRandomValue(2, 4)/10.0f;
}

void CollectionEffectParticle::tick()
{
    float dt = GetFrameTime();
    lifetime -= dt;

    if(lifetime > 0 && active)
    {
        yVelocity += gravity * dt;

        pos.y += yVelocity * dt;
        pos.x += xVelocity * dt;

        DrawTexturePro(texture, 
        {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)}, 
        {pos.x, pos.y, texture.width * scale, texture.height * scale},  
        {(texture.width * scale)/2.0f, (texture.height * scale)/2.0f},
        rotation,
        WHITE);
    }
    else
    {
        active = false;
    }
}