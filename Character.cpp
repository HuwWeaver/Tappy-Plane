#include "Character.h"

Character::Character(Vector2 winSize)
{
    windowDimensions = winSize;
    
    texture = LoadTexture("textures/Planes/planeRedSpriteSheet.png");
    spriteRect = {0, 0, texture.width/4.0f, texture.height/1.0f};   
    pos = {windowDimensions.x/4.0f - (texture.width/4.0f)/2.0f, windowDimensions.y/3.0f};
    collisionCircle = {{pos.x + spriteRect.width/2.0f, pos.y + spriteRect.height/2.0f}, 35};

    jumpSFX = LoadSound("sfx/Jump.wav");
    SetSoundVolume(jumpSFX, 0.5);

    smokePuffTexture = LoadTexture("textures/puffSmall.png");

    for (auto& puff : smokePuffPool)
    {
        puff.Init(smokePuffTexture);
    }
}

Character::~Character()
{
    UnloadSound(jumpSFX);
    UnloadTexture(texture);
    UnloadTexture(smokePuffTexture);
}

bool Character::OutOfBounds(int winHeight)
{
    if(pos.y >= winHeight - spriteRect.height) return true;
    if(pos.y <= -10) return true;
    
    return false;
}

void Character::Reset()
{
    for (auto& puff : smokePuffPool)
    {
        puff.Reset();
    }
    
    pos = {windowDimensions.x/4.0f - (texture.width/4.0f)/2.0f, windowDimensions.y/3.0f};
    collisionCircle.pos = {pos.x + spriteRect.width/2.0f, pos.y + spriteRect.height/2.0f};
    yVelocity = 0;
}

void Character::tick(float deltaTime, int winHeight)
{
    //In the air - Apply Gravity
    yVelocity += gravity * deltaTime;

    if(IsKeyPressed(KEY_SPACE))
    {
        yVelocity += jumpVel;
        SetSoundPitch(jumpSFX, GetRandomValue(8, 12)/10.0f);
        PlaySound(jumpSFX);

        for (auto& puff : smokePuffPool)
        {
            if(!puff.GetActive())
            {
                puff.Activate(pos);
                break;  
            }
        }
    }

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

    //Tick Particles
    for (auto& puff : smokePuffPool)
    {
        if(puff.GetActive()) puff.tick(deltaTime);
    }

    DrawTextureRec(texture, spriteRect, pos, WHITE);

    //DEBUG Circle
    //DrawCircleLines(collisionCircle.pos.x, collisionCircle.pos.y, collisionCircle.radius, BLUE);
}