#include "UpperObstacle.h"

UpperObstacle::UpperObstacle(){}

void UpperObstacle::SetStartPosition(int winWidth, int winHeight)
{
    Obstacle::SetStartPosition(winWidth, winHeight);

    pos.y = static_cast<float>(-10);
}

void UpperObstacle::tick(float deltaTime)
{
    Obstacle::tick(deltaTime);
    
    if(active)
    {
        DrawTextureRec(texture, spriteRect, pos, WHITE);

        collisionLine = {{pos.x + spriteRect.width/2.0f + 10, pos.y + spriteRect.height}, pos};
        //DEBUG Line
        DrawLine(collisionLine.point1.x, collisionLine.point1.y, collisionLine.point2.x, collisionLine.point2.y, BLUE);
    }
}