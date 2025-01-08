#include "GameOverPanel.h"
#include <string>

GameOverPanel::GameOverPanel(Vector2 windowSize) : windowDimensions(windowSize)
{
    gameOverText = LoadTexture("textures/UI/textGameOver.png");
    gameOverSFX = LoadSound("sfx/GameOver.wav");
    textFont = GetFontDefault();
}

GameOverPanel::~GameOverPanel()
{
    UnloadTexture(gameOverText);
    UnloadFont(textFont);
    UnloadSound(gameOverSFX);
}

void GameOverPanel::SetValues(float time, int obstacles, int collectibles)
{
    timeScore = time;
    obstacleScore = obstacles;
    collectibleScore = collectibles;
    totalScore = timeScore + obstacleScore + collectibleScore;
}

void GameOverPanel::Show()
{
    visible = true;
    PlaySound(gameOverSFX);
}

void GameOverPanel::tick()
{
    if(visible)
    {
        DrawRectangle(box1Padding, box1Padding, windowDimensions.x - (box1Padding * 2), windowDimensions.y - (box1Padding * 2), {147, 163, 170, 255});
        DrawRectangle(box2Padding, box2Padding, windowDimensions.x - (box2Padding * 2), windowDimensions.y - (box2Padding * 2), {202, 224, 233, 255});

        DrawTexturePro(gameOverText,
            {0, 0, static_cast<float>(gameOverText.width), static_cast<float>(gameOverText.height)}, 
            {windowDimensions.x/2.0f, windowDimensions.y/2.0f - 90, static_cast<float>(gameOverText.width), static_cast<float>(gameOverText.height)}, 
            {gameOverText.width/2.0f, gameOverText.height/2.0f},
            0.0,
            WHITE);

        //Draw Score
        std::string totalScoreText = "Total Score: ";
        totalScoreText.append(std::to_string(totalScore), 0, 5);
        DrawTextEx(textFont, totalScoreText.c_str(), {windowDimensions.x/4 - 30, windowDimensions.y/2 - 50}, 50, 4.0, BLACK);

        std::string timeScoreText = "Time: ";
        timeScoreText.append(std::to_string(timeScore), 0, 5);
        DrawTextEx(textFont, timeScoreText.c_str(), {windowDimensions.x/4, windowDimensions.y/2 + 10}, 30, 3.0, BLACK);

        std::string obstacleScoreText = "Obstacles Passed: ";
        obstacleScoreText.append(std::to_string(obstacleScore), 0, 5);
        DrawTextEx(textFont, obstacleScoreText.c_str(), {windowDimensions.x/4, windowDimensions.y/2 + 35}, 30, 3.0, BLACK);

        std::string collectibleScoreText = "Stars Collected: ";
        collectibleScoreText.append(std::to_string(collectibleScore), 0, 5);
        DrawTextEx(textFont, collectibleScoreText.c_str(), {windowDimensions.x/4, windowDimensions.y/2 + 60}, 30, 3.0, BLACK);

        DrawTextEx(textFont, "Press R to restart!", {windowDimensions.x/3 + 15, windowDimensions.y/2 + 100}, 25, 2.0, BLACK);
    }
}