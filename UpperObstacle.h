#ifndef UPPER_OBSTACLE_H
#define UPPER_OBSTACLE_H

#include "Obstacle.h"

class UpperObstacle : public Obstacle
{
public:
    UpperObstacle();
    virtual void ResetPosition() override;
    virtual void tick(const float& deltaTime) override;
};

#endif