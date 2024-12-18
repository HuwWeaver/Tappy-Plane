#include <iostream>
#include <vector>
#include <memory>
#include "raylib.h"
#include "Background.h"
#include "Character.h"
#include "Obstacle.h"
#include "UpperObstacle.h"
#include "LowerObstacle.h"
#include "Structs.h"

int main()
{
    //Window Dimensions
    Vector2 windowDimensions{800, 480};
    InitWindow(windowDimensions.x, windowDimensions.y, "Flappy Bird!");

    //create obstacle pool of equal amount upper and lower obstacles
    const int numEachObstacleType{3};

    std::vector<std::unique_ptr<Obstacle>> obstaclePool;

    for(int i=0; i < numEachObstacleType; i++)
    {
        obstaclePool.push_back(std::make_unique<LowerObstacle>());
        obstaclePool.back()->Init("textures/rock.png", windowDimensions.x, windowDimensions.y);
        obstaclePool.push_back(std::make_unique<UpperObstacle>());
        obstaclePool.back()->Init("textures/rockDown.png", windowDimensions.x, windowDimensions.y);
    }

    //obstacle timer
    float runningTime{2.0};
    float obstacleInterval{2.0}, minInterval{1.0}, maxInterval{2.5};

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
                for (auto& obstacle : obstaclePool)
                {
                    obstacle->Reset(windowDimensions.x, windowDimensions.y);            
                }
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
                obstacleInterval = GetRandomValue(minInterval, maxInterval);

                std::vector<Obstacle*> inactivePool;

                //find inactive obstacles in pool
                for (auto& obstacle : obstaclePool)
                {
                    if(!obstacle->GetActive())
                    {                      
                        //add to pool of inactive obstacles
                        inactivePool.push_back(obstacle.get());
                    }
                }

                //pick random obstacle from inactive pool and activate
                if (!inactivePool.empty())
                {
                    int obs = GetRandomValue(0, inactivePool.size() - 1);
                    inactivePool.at(obs)->SetActive(true);
                    inactivePool.at(obs)->SetStartPosition(windowDimensions.x, windowDimensions.y);
                }

            }

            //tick all active obstacles - update position and collisions
            for (auto& obstacle : obstaclePool)
            {
                if(obstacle->GetActive()) obstacle->tick(dt);            
            } 

            character.tick(dt, windowDimensions.y);

            //Check if character has hit the floor
            if(character.OutOfBounds(windowDimensions.y))
            {
                gameOver = true;
            }

            //Check active obstacle collisions
            for (auto& obstacle : obstaclePool)
            {                        
                if(obstacle->GetActive() && CheckCollisionCircleLine(character.GetCollisionCircle().pos, character.GetCollisionCircle().radius, 
                    obstacle->GetCollisionLine().point1, obstacle->GetCollisionLine().point2))
                {
                    gameOver = true;
                }
           }               
        }

        EndDrawing();
    }

    CloseWindow();
}