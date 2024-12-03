#include "Obstacle.h"

Obstacle::Obstacle(Texture2D sprite)
{
    texture = sprite;
    spriteRect = {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)};
}

void Obstacle::SetInitialPosition(int winWidth, int winHeight)
{
    pos = {static_cast<float>(winWidth + 200), static_cast<float>((winHeight - texture.height + 10))};
}

void Obstacle::tick(float deltaTime)
{
    pos.x += speed * deltaTime;
    if(pos.x <= -100) SetActive(false);

    collisionRect = {pos.x + collisionPadding, pos.y + collisionPadding, spriteRect.width - 2*collisionPadding, spriteRect.height - 2*collisionPadding};
    DrawTextureRec(texture, spriteRect, pos, WHITE);

    //DEBUG RECTANGLE
    DrawRectangleLines(pos.x + collisionPadding, pos.y + collisionPadding, spriteRect.width - 2*collisionPadding, spriteRect.height - 2*collisionPadding, RED);
}