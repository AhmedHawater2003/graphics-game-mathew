#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
#include "AnimatingValue.h"
class Maze :
    public GameObject
{
    bool isFirstScene;
    AnimatingValue scale{ 0,0.3,0.005 };

public:
    Maze(bool isFirstScene);
    Model_3DS model_maze;
    void init();
    void draw();
    void onIdle();
};

