#include "Character.h"

Character::Character(int winWidth, int winHeight)
{
    texture = LoadTexture("textures/Planes/planeRedSpriteSheet.png");
    spriteRect = {0, 0, texture.width/4.0f, texture.height/1.0f};
    pos = {winWidth/4.0f - (texture.width/4.0f)/2.0f, winHeight/3.0f};
    collisionCircle = {Vector2{pos.x + spriteRect.width/2.0f, pos.y + spriteRect.height/2.0f}, 40};
}

Character::~Character()
{
    UnloadTexture(texture);
}

bool Character::IsOnGround(int winHeight)
{
    return pos.y >= winHeight - spriteRect.height;
}

void Character::Reset(int winWidth, int winHeight)
{
    pos = {winWidth/4.0f - (texture.width/4.0f)/2.0f, winHeight/3.0f};
    collisionCircle.pos = {pos.x + spriteRect.width/2.0f, pos.y + spriteRect.height/2.0f};
    yVelocity = 0;
}

void Character::tick(float deltaTime, int winHeight)
{
    if (IsOnGround(winHeight))
    {
        yVelocity = 0;
    }
    else
    {
        //In the air - Apply Gravity
        yVelocity += gravity * deltaTime;
    }

    if(IsKeyPressed(KEY_SPACE))
    {
        yVelocity += jumpVel;
    }

    //TODO - Don't like having to update 2 different things, find another way
    pos.y += yVelocity * deltaTime;
    collisionCircle.pos.y += yVelocity * deltaTime;

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

    DrawTextureRec(texture, spriteRect, pos, WHITE);

    //DEBUG Circle
    DrawCircleLines(collisionCircle.pos.x, collisionCircle.pos.y, collisionCircle.radius, BLUE);
}