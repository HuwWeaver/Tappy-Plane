#include "SmokePuff.h"

SmokePuff::SmokePuff(){}

void SmokePuff::Init(Texture2D sprite)
{
    texture = sprite;
}

void SmokePuff::Activate(Vector2 newPos)
{
    pos = newPos;
    active = true;
}

void SmokePuff::Reset()
{
    active = false;
    colorLerpFactor = 1.0;
}

void SmokePuff::tick(float deltaTime)
{
    if(active)
    {
        pos.x += xSpeed * deltaTime;
        pos.y += ySpeed * deltaTime;
        if(pos.x <= -10) Reset();

        colorLerpFactor -= fadeSpeed * deltaTime;
        if (colorLerpFactor <= 0) colorLerpFactor = 0;

        DrawTextureV(texture, pos, ColorLerp(BLANK, GRAY, colorLerpFactor));
    }
}