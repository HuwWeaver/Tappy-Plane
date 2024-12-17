#include "Obstacle.h"

Obstacle::Obstacle(){}

void Obstacle::Init(Texture2D sprite, int winWidth, int winHeight)
{
    //Assign texture
    texture = sprite;
    spriteRect = {0, 0, static_cast<float>(texture.width), static_cast<float>(texture.height)};
    
    //Set Initial Position
    SetStartPosition(winWidth, winHeight);
}

void Obstacle::SetStartPosition(int winWidth, int winHeight)
{
    //Set Start Position
    pos.x = static_cast<float>(winWidth + 200);
}

void Obstacle::Reset(int winWidth, int winHeight)
{
    SetActive(false);
    SetStartPosition(winWidth, winHeight);
}

void Obstacle::tick(float deltaTime)
{
    if(active)
    {
        pos.x += speed * deltaTime;
        if(pos.x <= -100) SetActive(false);
    }
}