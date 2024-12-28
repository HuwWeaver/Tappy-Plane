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

        colorLerpFactor -= fadeSpeed * deltaTime;
        if (colorLerpFactor <= 0) colorLerpFactor = 0;

        DrawTextureEx(texture, pos, 0.0, 1.0, ColorLerp(BLANK, GRAY, colorLerpFactor));
    }
}

void SmokePuff::Reset()
{
    colorLerpFactor = 1.0;
    SetActive(false);
}