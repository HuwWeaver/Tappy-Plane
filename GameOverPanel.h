#ifndef GAMEOVERPANEL_H
#define GAMEOVERPANEL_H

#include "raylib.h"

class GameOverPanel {
public:
    GameOverPanel(Vector2 windowSize);
    void SetValues(float time, int obstacles, int collectibles);
    void tick();
    void Show() {visible = true;};
    void Hide() {visible = false;};

protected:
    Font kennyFont{};
    Vector2 windowDimensions{};
    const int box1Padding{90}, box2Padding{100};
    bool visible{false};
    float totalScore{}, timeScore{};
    int obstacleScore{}, collectibleScore{};
};

#endif