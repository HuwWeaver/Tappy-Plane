#include "Collectible.h"

Collectible::Collectible(){}

void Collectible::Init(Texture2D sprite, Sound sfx, Vector2 winSize)
{
    texture = sprite;
    collisionCircle = {{pos.x + texture.width/2.0f, pos.y + texture.height/2.0f}, 18};
    collectionSFX = sfx;
    
    windowDimensions = winSize;

    //Set Initial Position
    pos = {windowDimensions.x + 50 , windowDimensions.y/2.0f + GetRandomValue(-100, 100)};
}

void Collectible::Activate()
{
    pos = {windowDimensions.x + 50 , windowDimensions.y/2.0f + GetRandomValue(-100, 100)};
    active = true;
}

void Collectible::Collect()
{
    SetSoundPitch(collectionSFX, GetRandomValue(9, 11)/10.0f);
    PlaySound(collectionSFX);
    active = false;
}

void Collectible::Reset()
{
    active = false;
    pos = {windowDimensions.x + 50 , windowDimensions.y/2.0f + GetRandomValue(-100, 100)};
}

void Collectible::tick(float deltaTime)
{
    if(active)
    {
        pos.x -= speed * deltaTime;
        if(pos.x <= -50) Reset();

        collisionCircle.pos = pos;

        rotation += rotationSpeed * deltaTime;
        if (rotation >= 360) rotation = 0; 

        DrawTexturePro(texture, 
            {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)}, 
            {pos.x, pos.y, static_cast<float>(texture.width), static_cast<float>(texture.height)}, 
            {texture.width/2.0f, texture.height/2.0f},
            rotation,
            WHITE);

        //Debug Circle
        //DrawCircleLines(collisionCircle.pos.x, collisionCircle.pos.y, collisionCircle.radius, RED);
    }
}