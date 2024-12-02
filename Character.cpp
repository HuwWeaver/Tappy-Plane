#include "Character.h"

Character::Character(int winWidth, int winHeight)
{
    texture = LoadTexture("textures/Planes/planeRedSpriteSheet.png");
    spriteRect = {0, 0, texture.width/4.0f, texture.height/1.0f};
    pos = {winWidth/4.0f - (texture.width/4.0f)/2.0f, winHeight/3.0f};
}

Character::~Character()
{
    UnloadTexture(texture);
}

bool Character::IsOnGround(int winHeight)
{
    return pos.y >= winHeight - spriteRect.height;
}

void Character::tick(float deltaTime, int winHeight)
{
    if (IsOnGround(winHeight))
    {
        //Rectangle on the floor
        yVelocity = 0;
    }
    else
    {
        //Rectangle in the air - Apply Gravity
        yVelocity += gravity * deltaTime;
    }

    if(IsKeyPressed(KEY_SPACE))
    {
        yVelocity += jumpVel;
    }

    pos.y += yVelocity * deltaTime;

    //Character Animation
    runningTime += deltaTime;
    if(runningTime >= updateTime)
    {
        runningTime = 0.0;
        //Update animation frame
        spriteRect.x = frame * spriteRect.width;
        frame++;
        if(frame > maxFrame)
        {
            frame = 0;
        }
    }

    collisionRect = {pos.x, pos.y, spriteRect.width, spriteRect.height};
    DrawTextureRec(texture, spriteRect, pos, WHITE);
}