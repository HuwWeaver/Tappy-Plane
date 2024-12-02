#include "Background.h"

Background::Background(const char *textureFilePath, float scrollSpeed, float yPos) : speed(scrollSpeed), yPos(yPos)
{
    texture = LoadTexture(textureFilePath);
}

Background::~Background()
{
    UnloadTexture(texture);
}

void Background::tick(float deltaTime)
{
    xPos -= speed * deltaTime;

    if(xPos <= -texture.width)
    {
        xPos = 0.0f;
    }

    DrawTextureEx(texture, {xPos, yPos}, 0.0, 1.0, WHITE);
    DrawTextureEx(texture, {xPos + texture.width, yPos}, 0.0, 1.0, WHITE);
}