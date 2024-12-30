#include "LowerObstacle.h"

LowerObstacle::LowerObstacle(){}

void LowerObstacle::ResetPosition()
{
    Obstacle::ResetPosition();

    pos.y = windowDimensions.y - texture.height + 10;
}

void LowerObstacle::tick(float deltaTime)
{
    Obstacle::tick(deltaTime);
    
    if(active)
    {
        DrawTextureV(texture, pos, WHITE);

        collisionLine = {{pos.x + texture.width/2.0f + 10, pos.y}, {pos.x, pos.y + texture.height}};
        //DEBUG Line
        //DrawLine(collisionLine.point1.x, collisionLine.point1.y, collisionLine.point2.x, collisionLine.point2.y, BLUE);
    }
}