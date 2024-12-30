#include "Collectible.h"

Collectible::Collectible(){}

void Collectible::Init(Texture2D sprite, Vector2 winSize)
{
    texture = sprite;
    pos = {winSize.x/2.0f, winSize.y/2.0f};
    windowSize = winSize;
    collisionCircle = {{pos.x + texture.width/2.0f, pos.y + texture.height/2.0f}, 18};
}

void Collectible::Reset()
{
    SetActive(false);
    SetPosition({windowSize.x/2.0f, windowSize.y/2.0f});
}

void Collectible::tick(float deltaTime)
{
    if(active)
    {
        pos.x -= speed * deltaTime;
        collisionCircle.pos.x -= speed * deltaTime;
        if(pos.x <= -100) Reset();

        DrawTextureV(texture, pos, WHITE);

        //Debug Circle
        DrawCircleLines(collisionCircle.pos.x, collisionCircle.pos.y, collisionCircle.radius, RED);
    }
}