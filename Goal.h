#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
#include "AnimatingValue.h"
class Goal :
    public GameObject
{
    bool isFirstScene;
    Model_3DS model_goal;
    AnimatingValue scale{ 0,0.3,0.005 };

public:
    Goal(bool isFirstScene);

    void init();
    void draw();
    void onIdle();
};

