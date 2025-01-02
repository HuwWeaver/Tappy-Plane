#include "GameOverPanel.h"
#include <string>

GameOverPanel::GameOverPanel(Vector2 windowSize) : windowDimensions(windowSize)
{}

void GameOverPanel::SetValues(float time, int obstacles, int collectibles)
{
    timeScore = time;
    obstacleScore = obstacles;
    collectibleScore = collectibles;
    totalScore = timeScore + obstacleScore + collectibleScore;
}

void GameOverPanel::tick()
{
    if(visible)
    {
        DrawRectangle(box1Padding, box1Padding, windowDimensions.x - (box1Padding * 2), windowDimensions.y - (box1Padding * 2), {147, 163, 170, 255});
        DrawRectangle(box2Padding, box2Padding, windowDimensions.x - (box2Padding * 2), windowDimensions.y - (box2Padding * 2), {202, 224, 233, 255});
    
        //Lose the game
        DrawText("Game Over!", windowDimensions.x/4 + 30, windowDimensions.y/2 - 120, 60, BLACK);

        //Draw Score
        std::string totalScoreText = "Total Score: ";
        totalScoreText.append(std::to_string(totalScore), 0, 5);
        DrawText(totalScoreText.c_str(), windowDimensions.x/4 - 50, windowDimensions.y/2 - 50, 50, BLACK);

        std::string timeScoreText = "Time: ";
        timeScoreText.append(std::to_string(timeScore), 0, 5);
        DrawText(timeScoreText.c_str(), windowDimensions.x/4, windowDimensions.y/2 + 10, 30, BLACK);

        std::string obstacleScoreText = "Obstacles Passed: ";
        obstacleScoreText.append(std::to_string(obstacleScore), 0, 5);
        DrawText(obstacleScoreText.c_str(), windowDimensions.x/4, windowDimensions.y/2 + 35, 30, BLACK);

        std::string collectibleScoreText = "Stars Collected: ";
        collectibleScoreText.append(std::to_string(collectibleScore), 0, 5);
        DrawText(collectibleScoreText.c_str(), windowDimensions.x/4, windowDimensions.y/2 + 60, 30, BLACK);

        DrawText("Press R to restart!", windowDimensions.x/4 + 60, windowDimensions.y/2 + 100, 25, BLACK);
    }
}