#ifndef LOWER_OBSTACLE_H
#define LOWER_OBSTACLE_H

#include "Obstacle.h"

class LowerObstacle : public Obstacle
{
public:
    LowerObstacle();
    virtual void SetStartPosition(int winWidth, int winHeight) override;
    virtual void tick(float deltaTime) override;
};

#endif