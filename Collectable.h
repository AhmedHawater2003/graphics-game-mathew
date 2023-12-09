#pragma once
#include "GameObject.h"
class Collectable :
    public GameObject
{
    bool isFirstScene;
public:
    Collectable(bool isFirstScene);

    void init();
    void draw();
    void onIdle();
};

