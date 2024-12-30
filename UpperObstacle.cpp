#include "UpperObstacle.h"

UpperObstacle::UpperObstacle(){}

void UpperObstacle::ResetPosition()
{
    Obstacle::ResetPosition();

    pos.y = static_cast<float>(-10);
}

void UpperObstacle::tick(float deltaTime)
{
    Obstacle::tick(deltaTime);
    
    if(active)
    {
        DrawTextureV(texture, pos, WHITE);

        collisionLine = {{pos.x + texture.width/2.0f + 10, pos.y + texture.height}, pos};
        //DEBUG Line
        //DrawLine(collisionLine.point1.x, collisionLine.point1.y, collisionLine.point2.x, collisionLine.point2.y, BLUE);
    }
}