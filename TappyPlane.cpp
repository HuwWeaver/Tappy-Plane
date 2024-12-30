//Standard Libraries
#include <vector>
#include <memory>
#include <string>
//Raylib
#include "raylib.h"
//Custom
#include "Structs.h"
#include "Background.h"
#include "Character.h"
#include "Obstacle.h"
#include "UpperObstacle.h"
#include "LowerObstacle.h"
#include "Collectible.h"

int main()
{
    //Window Dimensions
    Vector2 windowDimensions{800, 480};
    InitWindow(windowDimensions.x, windowDimensions.y, "Tappy Plane!");

    //create obstacle pool of equal amount upper and lower obstacles
    std::vector<std::unique_ptr<Obstacle>> obstaclePool;
    Texture2D lowerRock = LoadTexture("textures/rock.png");
    Texture2D upperRock = LoadTexture("textures/rockDown.png");

    for(int i=0; i < 3; i++)
    {
        obstaclePool.push_back(std::make_unique<LowerObstacle>());
        obstaclePool.back()->Init(lowerRock, windowDimensions.x, windowDimensions.y);
        obstaclePool.push_back(std::make_unique<UpperObstacle>());
        obstaclePool.back()->Init(upperRock, windowDimensions.x, windowDimensions.y);
    }

    //obstacle timer
    float obstacleRunningTime{2.0};
    float obstacleInterval{2.0};
    const float minInterval{1.0}, maxInterval{2.5};

    //Create Collectibles Pool
    Collectible colleciblesPool[5]{};
    Texture2D collectibleTexture = LoadTexture("textures/starGold.png");

    for (auto& collectible : colleciblesPool)
    {
        collectible.Init(collectibleTexture, windowDimensions);
    }

    //collectibles timer
    float collectiblesRunningTime{2.0};
    float collectibleInterval{2.0};

    Character character{static_cast<int>(windowDimensions.x), static_cast<int>(windowDimensions.y)};

    bool gameOver{false};
    float timeScore{0.0}, totalScore{0.0};
    int obstacleScore{0};

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
            DrawText("Game Over!", windowDimensions.x/4, windowDimensions.y/2 - 70, 60, BLACK);

            //Draw Score
            std::string totalScoreText = "Total Score: ";
            totalScoreText.append(std::to_string(totalScore), 0, 5);
            DrawText(totalScoreText.c_str(), windowDimensions.x/4, windowDimensions.y/2 - 15, 50, BLACK);

            std::string timeScoreText = "Time: ";
            timeScoreText.append(std::to_string(timeScore), 0, 5);
            DrawText(timeScoreText.c_str(), windowDimensions.x/4, windowDimensions.y/2 + 30, 30, BLACK);

            std::string obstacleScoreText = "Obstacles Passed: ";
            obstacleScoreText.append(std::to_string(obstacleScore), 0, 5);
            DrawText(obstacleScoreText.c_str(), windowDimensions.x/4, windowDimensions.y/2 + 55, 30, BLACK);

            //Reset Game
            if(IsKeyPressed(KEY_R))
            {
                for (auto& obstacle : obstaclePool)
                {
                    obstacle->Reset(windowDimensions.x, windowDimensions.y);            
                }
                character.Reset(windowDimensions.x, windowDimensions.y);
                timeScore = 0.0;
                totalScore = 0.0;
                obstacleScore = 0;
                gameOver = false;
            }
        }
        else
        {
            obstacleRunningTime += dt;
            if(obstacleRunningTime >= obstacleInterval)
            {
                obstacleRunningTime = 0;
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

            collectiblesRunningTime += dt;
            if(collectiblesRunningTime >= collectibleInterval)
            {
                collectiblesRunningTime = 0;
                collectibleInterval = GetRandomValue(minInterval, maxInterval);

                for(auto& collecible : colleciblesPool)
                {
                    if(!collecible.active)
                    {
                        collecible.SetActive(true);
                        break;
                    }
                }
            }

            //tick all active obstacles - update position and collisions
            for (auto& obstacle : obstaclePool)
            {
                if(obstacle->GetActive()) obstacle->tick(dt);            
            }

            //tick all active collectibles
            for (auto& collectible : colleciblesPool)
            {
                if(collectible.active) collectible.tick(dt);
            }

            character.tick(dt, windowDimensions.y);

            //Check if character has hit the floor
            if(character.OutOfBounds(windowDimensions.y))
            {
                gameOver = true;
            }

            //Check active obstacle collisions & add to score if passed char
            for (auto& obstacle : obstaclePool)
            {                        
                if(obstacle->GetActive())
                {
                    if(obstacle->hasPassedChar(character.GetPosition().x)) obstacleScore++;
                    
                    if(CheckCollisionCircleLine(character.GetCollisionCircle().pos, character.GetCollisionCircle().radius, 
                                                obstacle->GetCollisionLine().point1, obstacle->GetCollisionLine().point2))
                    {
                        gameOver = true;
                    }
                }
            }

            //Draw Score
            timeScore += dt;
            totalScore = timeScore + obstacleScore;
            std::string scoreText = "Score: ";
            scoreText.append(std::to_string(totalScore), 0, 5);
            DrawText(scoreText.c_str(), 5, 5, 30, BLACK);           
        }

        EndDrawing();
    }

    //Unload Textures
    UnloadTexture(lowerRock);
    UnloadTexture(upperRock);
    UnloadTexture(collectibleTexture);

    CloseWindow();
}