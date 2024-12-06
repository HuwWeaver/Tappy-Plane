#include "raylib.h"
#include "Background.h"
#include "Character.h"
#include "Obstacle.h"
#include "Structs.h"

int main()
{
    //Window Dimensions
    Vector2 windowDimensions{800, 480};
    InitWindow(windowDimensions.x, windowDimensions.y, "Flappy Bird!");

    Texture2D rock = LoadTexture("textures/rock.png");
    const int objectPoolSize{5};

    Obstacle obstaclePool[objectPoolSize];

    for(int i=0; i < objectPoolSize; i++)
    {
        obstaclePool[i].Init(rock, windowDimensions.x, windowDimensions.y);
    }

    //obstacle timer
    float runningTime{2.0};
    float obstacleInterval{2.0};

    Character character{static_cast<int>(windowDimensions.x), static_cast<int>(windowDimensions.y)};

    bool gameOver{false};

    Background background{"textures/background.png", 25};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Delta time
        float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(BLACK);

        background.tick(dt);

        if(gameOver)
        {
            //Lose the game
            DrawText("Game Over!", windowDimensions.x/4, windowDimensions.y/2, 50, BLACK);

            if(IsKeyPressed(KEY_R))
            {
                character.Reset(windowDimensions.x, windowDimensions.y);
                gameOver = false;
            }
        }
        else
        {
            runningTime += dt;
            if(runningTime >= obstacleInterval)
            {
                runningTime = 0;

                //find inactive obstacle in pool
                for (int i=0; i < objectPoolSize; i++)
                {
                    if(!obstaclePool[i].GetActive())
                    {
                        //Spawn inactive obstacle and stop searching
                        obstaclePool[i].SetActive(true);
                        obstaclePool[i].SetStartPosition(windowDimensions.x, windowDimensions.y);
                        break;
                    }
                }
            }

            //tick all active obstacles - update position and collisions
            for (int i=0; i < objectPoolSize; i++)
            {
                if(obstaclePool[i].GetActive()) obstaclePool[i].tick(dt);            
            } 

            character.tick(dt, windowDimensions.y);

            //Check if character has hit the floor
            if(character.IsOnGround(windowDimensions.y))
            {
                gameOver = true;
            }

            //Check obstacle collisions
            for (Obstacle obstacle : obstaclePool)
            {          
                if(CheckCollisionCircleLine(character.GetCollisionCircle().pos, character.GetCollisionCircle().radius, 
                    obstacle.GetCollisionLine().point1, obstacle.GetCollisionLine().point2))
                {
                    gameOver = true;
                }
           }               
        }

        EndDrawing();
    }

    CloseWindow();
}