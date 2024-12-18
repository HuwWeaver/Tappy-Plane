#include "SmokePuff.h"

SmokePuff::SmokePuff(){}

SmokePuff::~SmokePuff()
{
    UnloadTexture(texture);
}

void SmokePuff::Init(const char *textureFilePath, Vector2 startPos)
{
    texture = LoadTexture(textureFilePath);
    SetPosition(startPos);
}

void SmokePuff::tick(float deltaTime)
{
    if(active)
    {
        pos.x += speed * deltaTime;
        if(pos.x <= -10) SetActive(false);

        DrawTextureEx(texture, pos, 0.0, 1.0, GRAY);
    }
}