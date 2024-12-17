#ifndef PARTICLE_H
#define PARTICLE_H

#include "raylib.h"

class Particle
{
public:
    Particle(const char *textureFilePath, Vector2 startPos);
    ~Particle();
    void tick(float deltaTime);
    bool GetActive() {return active;};
    void SetActive(bool newActive) {active = newActive;};

protected:
    Texture2D texture{};
    Vector2 pos{};
    int speed{-200};
    bool active{false};
};

#endif