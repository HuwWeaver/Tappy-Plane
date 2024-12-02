#include "raylib.h"
#include "Background.h"
#include "Character.h"
#include "Obstacle.h"

int main()
{
    //Window Dimensions
    int windowDimensions[2];
    windowDimensions[0] = 800;
    windowDimensions[1] = 480;
    InitWindow(windowDimensions[0], windowDimensions[1], "Flappy Bird!");

    Texture2D rock = LoadTexture("textures/rock.png");
    const int objectPoolSize{5};

    Obstacle obstaclePool[objectPoolSize]{
        Obstacle{rock},
        Obstacle{rock},
        Obstacle{rock},
        Obstacle{rock},
        Obstacle{rock}
    };

        for(int i =0; i < objectPoolSize; i++)
    {
        obstaclePool[i].SetInitialPosition(windowDimensions[0], windowDimensions[1]);
    }

    //obstacle timer
    float runningTime{2.0};
    float obstacleInterval{2.0};

    Character character{windowDimensions[0], windowDimensions[1]};

    bool gameOver{false};

    Background background{"textures/background.png", 25};
    Background foreground{"textures/groundGrass.png", 50, windowDimensions[1] - 60};

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
            DrawText("Game Over!", windowDimensions[0]/4, windowDimensions[1]/2, 50, BLACK);
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
                        obstaclePool[i].SetInitialPosition(windowDimensions[0], windowDimensions[1]);
                        break;
                    }
                }
            }

            //tick all active nebula obstacles - update animation, position, and collisions
            for (int i=0; i < objectPoolSize; i++)
            {
                if(obstaclePool[i].GetActive()) obstaclePool[i].tick(dt);            
            } 
            
            foreground.tick(dt);

            character.tick(dt, windowDimensions[1]);

            //Check if character has hit the floor
            if(character.IsOnGround(windowDimensions[1]))
            {
                gameOver = true;
            }

                
        }

        EndDrawing();
    }

    CloseWindow();
}