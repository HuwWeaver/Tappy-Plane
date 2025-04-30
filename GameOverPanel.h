#ifndef GAME_OVER_PANEL_H
#define GAME_OVER_PANEL_H

#include "raylib.h"

class GameOverPanel {
public:
    GameOverPanel(const Vector2& windowSize);
    ~GameOverPanel();
    void SetValues(const float& time, const int& obstacles, const int& collectibles);
    void tick();
    void Show();
    void Hide() {visible = false;};

protected:
    Font textFont{};
    Texture2D gameOverText{};
    Sound gameOverSFX{};
    const Vector2* windowDimensions{};
    const int box1Padding{90}, box2Padding{100};
    bool visible{false};
    float totalScore{};
    const float* timeScore{};
    const int* obstacleScore{};
    const int* collectibleScore{};
};

#endif