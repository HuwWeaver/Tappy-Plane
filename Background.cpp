#include "Background.h"

Background::Background(const char *textureFilePath, float scrollSpeed, float yPos) : speed(scrollSpeed)
{
    texture = LoadTexture(textureFilePath);
    pos.y = yPos;
}

Background::~Background()
{
    UnloadTexture(texture);
}

void Background::tick(float deltaTime)
{
    pos.x -= speed * deltaTime;

    if(pos.x <= -texture.width)
    {
        pos.x = 0.0f;
    }

    DrawTextureV(texture, pos, WHITE);
    DrawTextureV(texture, {pos.x + texture.width, pos.y}, WHITE);
}