#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class Obstacle : public GameObject {
    bool isFirstScene;
    Model_3DS model_obstacle;

    float warningLightIntensity;
    float warningLightPhase;

    // New variables for the ground glow effect
    float glowRadius;
    float glowIntensity;

public:
    Obstacle(bool isFirstScene);
    void init();
    void draw();
    void updateWarningLight(float deltaTime);

    // New method to draw the ground glow
    void drawGroundGlow();
};

