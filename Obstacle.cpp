#include "Obstacle.h"

Obstacle::Obstacle(){}

void Obstacle::Init(Texture2D sprite, Vector2 winSize)
{
    //Assign texture
    texture = sprite;
    
    windowDimensions = winSize;

    //Set Initial Position
    ResetPosition();
}

void Obstacle::Activate()
{
    ResetPosition();
    active = true;
}

void Obstacle::Reset()
{
    scoreAdded = false;
    active = false;
    ResetPosition();
}

void Obstacle::tick(float deltaTime)
{
    if(active)
    {
        pos.x -= speed * deltaTime;
        if(pos.x <= -100) Reset();
    }
}

void Obstacle::ResetPosition()
{
    pos.x = windowDimensions.x + 200;
}

bool Obstacle::hasPassedChar(float charXPos)
{
    if(!scoreAdded && charXPos > pos.x)
    {
        scoreAdded = true;
        return true;
    }

    return false;
}