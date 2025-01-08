#ifndef GAME_OVER_PANEL_H
#define GAME_OVER_PANEL_H

#include "raylib.h"

class GameOverPanel {
public:
    GameOverPanel(Vector2 windowSize);
    ~GameOverPanel();
    void SetValues(float time, int obstacles, int collectibles);
    void tick();
    void Show();
    void Hide() {visible = false;};

protected:
    Font textFont{};
    Texture2D gameOverText{};
    Sound gameOverSFX{};
    Vector2 windowDimensions{};
    const int box1Padding{90}, box2Padding{100};
    bool visible{false};
    float totalScore{}, timeScore{};
    int obstacleScore{}, collectibleScore{};
};

#endif