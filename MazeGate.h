#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
class MazeGate :
    public GameObject
{
    bool isFirstScene;
    Model_3DS model_gate;
    bool translationalAnimation = true;
public:
    MazeGate(bool isFirstScene, Vector3f CollisionBoxSize);

    void init();
    void draw();
    void onIdle();
    void onCollision(GameObject*& pObject);
};

