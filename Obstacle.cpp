#include "Obstacle.h"

Obstacle::Obstacle(){}

Obstacle::~Obstacle()
{
    UnloadTexture(texture);
}

void Obstacle::Init(const char *textureFilePath, int winWidth, int winHeight)
{
    //Assign texture
    texture = LoadTexture(textureFilePath);
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