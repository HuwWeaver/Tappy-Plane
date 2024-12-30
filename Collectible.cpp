#include "Collectible.h"

Collectible::Collectible(){}

void Collectible::Init(Texture2D sprite, Vector2 winSize)
{
    texture = sprite;
    collisionCircle = {{pos.x + texture.width/2.0f, pos.y + texture.height/2.0f}, 18};
    
    windowDimensions = winSize;

    //Set Initial Position
    pos = {windowDimensions.x + 50 , windowDimensions.y/2.0f + GetRandomValue(-100, 100)};
}

void Collectible::Activate()
{
    pos = {windowDimensions.x + 50 , windowDimensions.y/2.0f + GetRandomValue(-100, 100)};
    active = true;
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

        collisionCircle.pos = {pos.x + texture.width/2.0f, pos.y + texture.height/2.0f};

        DrawTextureV(texture, pos, WHITE);

        //Debug Circle
        //DrawCircleLines(collisionCircle.pos.x, collisionCircle.pos.y, collisionCircle.radius, RED);
    }
}