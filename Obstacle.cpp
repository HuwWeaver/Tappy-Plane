#include "Obstacle.h"

Obstacle::Obstacle(Texture2D sprite)
{
    texture = sprite;
    spriteRect = {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)};
}

void Obstacle::SetInitialPosition(int winWidth, int winHeight)
{
    pos = {static_cast<float>(winWidth + 200), static_cast<float>((winHeight - texture.height))};
}

void Obstacle::tick(float deltaTime)
{
    pos.x += speed * deltaTime;
    if(pos.x <= -100) SetActive(false);

    collisionRect = {pos.x + pad, pos.y + pad, spriteRect.width - 2*pad, spriteRect.height - 2*pad};
    DrawTextureRec(texture, spriteRect, pos, WHITE);
}