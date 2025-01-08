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
#include "CollectionEffectEmitter.h"
#include "GameOverPanel.h"

int main()
{
    //Window Dimensions
    Vector2 windowDimensions{800, 480};
    InitWindow(windowDimensions.x, windowDimensions.y, "Tappy Plane!");

    //Audio
    InitAudioDevice();

    //create obstacle pool of equal amount upper and lower obstacles
    std::vector<std::unique_ptr<Obstacle>> obstaclePool;
    Texture2D lowerRock = LoadTexture("textures/rock.png");
    Texture2D upperRock = LoadTexture("textures/rockDown.png");

    for(int i=0; i < 3; i++)
    {
        obstaclePool.push_back(std::make_unique<LowerObstacle>());
        obstaclePool.back()->Init(lowerRock, windowDimensions);
        obstaclePool.push_back(std::make_unique<UpperObstacle>());
        obstaclePool.back()->Init(upperRock, windowDimensions);
    }

    //obstacle timer
    float obstacleRunningTime{2.0};
    float obstacleInterval{2.0};
    const float minInterval{1.0}, maxInterval{2.5};

    //Create Collectibles Pool
    Collectible collectiblesPool[5]{};
    Texture2D collectibleTexture = LoadTexture("textures/starGold.png");
    Sound collectionSFX = LoadSound("sfx/StarCollect.wav");
    CollectionEffectEmitter collectionEffectEmitter{collectibleTexture};

    for (auto& collectible : collectiblesPool)
    {
        collectible.Init(collectibleTexture, collectionSFX, windowDimensions);
    }

    //collectibles timer
    float collectiblesRunningTime{2.0};
    float collectibleInterval{2.0};

    Character character{windowDimensions};

    bool gameOver{false};
    float timeScore{0.0}, totalScore{0.0};
    int obstacleScore{0}, collectibleScore{0};

    GameOverPanel gameOverPanel{windowDimensions};

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
            gameOverPanel.tick();

            //Reset Game
            if(IsKeyPressed(KEY_R))
            {
                gameOverPanel.Hide();

                for (auto& obstacle : obstaclePool)
                {
                    obstacle->Reset();            
                }

                for (auto& collecible : collectiblesPool)
                {
                    collecible.Reset();
                }
                
                collectionEffectEmitter.Reset();
                character.Reset();
                timeScore = 0.0;
                totalScore = 0.0;
                obstacleScore = 0;
                collectibleScore = 0;
                gameOver = false;
            }
        }
        else
        {
            // ##########################################
            // ########## OBJECT SPAWNING ###############
            // ##########################################
            
            //Spawn new obstacle if needed
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
                    inactivePool.at(obs)->Activate();
                }

            }

            //Spawn new collectible if needed
            collectiblesRunningTime += dt;
            if(collectiblesRunningTime >= collectibleInterval)
            {
                collectiblesRunningTime = 0;
                collectibleInterval = GetRandomValue(minInterval, maxInterval);

                for(auto& collecible : collectiblesPool)
                {
                    if(!collecible.GetActive())
                    {
                        collecible.Activate();
                        break;
                    }
                }
            }

            // ##########################################
            // ########## TICK EVENTS ###################
            // ##########################################

            //tick all active collectibles
            for (auto& collectible : collectiblesPool)
            {
                if(collectible.GetActive()) collectible.tick(dt);
            }
            
            collectionEffectEmitter.tick();

            //tick all active obstacles - update position and collisions
            for (auto& obstacle : obstaclePool)
            {
                if(obstacle->GetActive()) obstacle->tick(dt);            
            }

            character.tick(dt, windowDimensions.y);

            // ##########################################
            // ########## COLLISION CHECKS ##############
            // ##########################################

            //Check active collectible collisions & add to score/reset if collided
            for (auto& collectible : collectiblesPool)
            {
                if(collectible.GetActive())
                {
                    if(CheckCollisionCircles(collectible.GetCollisionCircle().pos, collectible.GetCollisionCircle().radius,
                                            character.GetCollisionCircle().pos, character.GetCollisionCircle().radius))
                    {
                        collectibleScore++;
                        collectionEffectEmitter.SpawnParticles(collectible.GetPosition());
                        collectible.Collect();
                    }
                }
            }

            //Check if character has hit the floor
            if(character.OutOfBounds(windowDimensions.y))
            {
                gameOver = true;
                gameOverPanel.SetValues(timeScore, obstacleScore, collectibleScore);
                gameOverPanel.Show();
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
                        gameOverPanel.SetValues(timeScore, obstacleScore, collectibleScore);
                        gameOverPanel.Show();
                    }
                }
            }

            //Draw Score
            timeScore += dt;
            totalScore = timeScore + obstacleScore + collectibleScore;
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

    //Unload Audio
    UnloadSound(collectionSFX);

    CloseAudioDevice();

    CloseWindow();
}