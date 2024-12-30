#ifndef LOWER_OBSTACLE_H
#define LOWER_OBSTACLE_H

#include "Obstacle.h"

class LowerObstacle : public Obstacle
{
public:
    LowerObstacle();
    virtual void ResetPosition() override;
    virtual void tick(float deltaTime) override;
};

#endif