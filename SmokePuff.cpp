#include "SmokePuff.h"

SmokePuff::SmokePuff(){}

SmokePuff::~SmokePuff()
{
    UnloadTexture(texture);
}

void SmokePuff::Init(Texture2D sprite, Vector2 startPos)
{
    texture = sprite;
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

        DrawTextureV(texture, pos, ColorLerp(BLANK, GRAY, colorLerpFactor));
    }
}

void SmokePuff::Reset()
{
    colorLerpFactor = 1.0;
    SetActive(false);
}