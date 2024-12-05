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
    if(active)
    {
        pos.x += speed * deltaTime;
        if(pos.x <= -100) SetActive(false);

        collisionLine = {{pos.x + spriteRect.width/2.0f + 5, pos.y}, {pos.x, pos.y + spriteRect.height}};

        DrawTextureRec(texture, spriteRect, pos, WHITE);

        //DEBUG Line
        DrawLine(collisionLine.point1.x, collisionLine.point1.y, collisionLine.point2.x, collisionLine.point2.y, BLUE);
    }
}