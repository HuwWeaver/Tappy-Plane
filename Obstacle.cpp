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

    //lower obstacle
    pos.y = static_cast<float>(winHeight - texture.height + 10);
    //upper obstacle
    //upperSpritePosY = static_cast<float>(-10);
}

void Obstacle::tick(float deltaTime)
{
    if(active)
    {
        pos.x += speed * deltaTime;
        if(pos.x <= -100) SetActive(false);

        collisionLine = {{pos.x + spriteRect.width/2.0f + 10, pos.y}, {pos.x, pos.y + spriteRect.height}};
        //upperCollisionLine = {{xPos + spriteRect.width/2.0f + 10, upperSpritePosY + spriteRect.height}, {xPos, upperSpritePosY}};

        DrawTextureRec(texture, spriteRect, pos, WHITE);
        //DrawTextureRec(upperTexture, spriteRect, {xPos, upperSpritePosY}, WHITE);

        //DEBUG Line
        DrawLine(collisionLine.point1.x, collisionLine.point1.y, collisionLine.point2.x, collisionLine.point2.y, BLUE);
        //DrawLine(upperCollisionLine.point1.x, upperCollisionLine.point1.y, upperCollisionLine.point2.x, upperCollisionLine.point2.y, GREEN);
    }
}