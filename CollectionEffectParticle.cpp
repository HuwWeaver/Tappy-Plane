#include "CollectionEffectParticle.h"

void CollectionEffectParticle::Init(Texture2D sprite)
{
    texture = sprite;
}

void CollectionEffectParticle::Spawn(Vector2 startPos, float startXVelocity, float startYVelocity)
{
    pos = startPos;
    //xVelocity = startXVelocity;
    yVelocity = startYVelocity;
    //rotation = GetRandomValue(0, 360);
    scale = GetRandomValue(2, 5)/10.0f;
    //lifetime = 
}

void CollectionEffectParticle::tick()
{
    float dt = GetFrameTime();
    
    //CONTINUE ADDING LIFETIME
    lifetime -= dt;

    yVelocity += gravity * dt;
    //xVelocity += xDrag * dt;

    pos.y += yVelocity * dt;
    //pos.x += xVelocity * dt;

    DrawTexturePro(texture, 
    {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)}, 
    {pos.x, pos.y, texture.width * scale, texture.height * scale},  
    {(texture.width * scale)/2.0f, (texture.height * scale)/2.0f},
    rotation,
    WHITE);
}