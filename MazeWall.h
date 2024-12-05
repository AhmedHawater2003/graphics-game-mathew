#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
class MazeWall :
    public GameObject
{
    bool isFirstScene;
    Model_3DS model_maze_wall;
    bool translationalAnimation = true;
public:
    float lengthX, lengthY, lengthZ; // Dimensions of the wall
    MazeWall(bool isFirstScene, float w, float h, float angle);
    void init();
    void draw();
    void onIdle();
    void onCollision(GameObject*& pObject);
};

