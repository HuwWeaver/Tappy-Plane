#ifndef UPPER_OBSTACLE_H
#define UPPER_OBSTACLE_H

#include "Obstacle.h"

class UpperObstacle : public Obstacle
{
public:
    UpperObstacle();
    virtual void SetStartPosition(int winWidth, int winHeight) override;
    virtual void tick(float deltaTime) override;
};

#endif