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
        pos.x += xSpeed * deltaTime;
        pos.y += ySpeed * deltaTime;
        if(pos.x <= -10) SetActive(false);

        opacity -= fadeSpeed * deltaTime;
        if (opacity <= 0) opacity = 0;

        DrawTextureEx(texture, pos, 0.0, 1.0, {130, 130, 130, static_cast<unsigned char>(opacity)});
    }
}

void SmokePuff::Reset()
{
    opacity = 255.0;
    SetActive(false);
}