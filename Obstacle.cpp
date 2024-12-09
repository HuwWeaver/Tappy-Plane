#include "Obstacle.h"

Obstacle::Obstacle(){}

void Obstacle::Init(Texture2D lowerSprite, Texture2D upperSprite, int winWidth, int winHeight)
{
    //Assign lowerTexture
    lowerTexture = lowerSprite;
    spriteRect = {0, 0, static_cast<float>(lowerTexture.width), static_cast<float>(lowerTexture.height)};
    upperTexture = upperSprite;
    
    //Set Initial Position
    SetStartPosition(winWidth, winHeight);
}

void Obstacle::SetStartPosition(int winWidth, int winHeight)
{
    //Set Start Position
    xPos = static_cast<float>(winWidth + 200);
    lowerSpritePosY = static_cast<float>(winHeight - lowerTexture.height + 10);
    upperSpritePosY = static_cast<float>(-10);
}

void Obstacle::tick(float deltaTime)
{
    if(active)
    {
        xPos += speed * deltaTime;
        if(xPos <= -100) SetActive(false);

        lowerCollisionLine = {{xPos + spriteRect.width/2.0f + 10, lowerSpritePosY}, {xPos, lowerSpritePosY + spriteRect.height}};
        upperCollisionLine = {{xPos + spriteRect.width/2.0f + 10, upperSpritePosY + spriteRect.height}, {xPos, upperSpritePosY}};

        DrawTextureRec(lowerTexture, spriteRect, {xPos, lowerSpritePosY}, WHITE);
        DrawTextureRec(upperTexture, spriteRect, {xPos, upperSpritePosY}, WHITE);

        //DEBUG Line
        DrawLine(lowerCollisionLine.point1.x, lowerCollisionLine.point1.y, lowerCollisionLine.point2.x, lowerCollisionLine.point2.y, BLUE);
        DrawLine(upperCollisionLine.point1.x, upperCollisionLine.point1.y, upperCollisionLine.point2.x, upperCollisionLine.point2.y, GREEN);
    }
}