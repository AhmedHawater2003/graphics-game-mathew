#pragma once
#include "GameObject.h"
class Goal :
    public GameObject
{
    bool isFirstScene;
public:
    Goal(bool isFirstScene);

    void init();
    void draw();
    void onIdle();
};

