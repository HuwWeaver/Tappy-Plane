#include "Particle.h"

Particle::Particle(const char *textureFilePath, Vector2 startPos)
{
    texture = LoadTexture(textureFilePath);
    pos = startPos;
}

Particle::~Particle()
{
    UnloadTexture(texture);
}

void Particle::tick(float deltaTime)
{
    pos.x += speed * deltaTime;
    //if(pos.x <= -100) SetActive(false);

    DrawTextureEx(texture, pos, 0.0, 1.0, WHITE);
}