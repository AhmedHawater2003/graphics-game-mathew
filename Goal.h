#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
#include "AnimatingValue.h"
class Goal :
    public GameObject
{
    bool isFirstScene;
    Model_3DS model_goal;
    AnimatingValue scale = new AnimatingValue(20,100,10);

public:
    Goal(bool isFirstScene);

    void init();
    void draw();
    void onIdle();
};

