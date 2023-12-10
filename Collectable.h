#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
class Collectable :
    public GameObject
{
    bool isFirstScene;
    Model_3DS model_collectable;
    bool translationalAnimation = true;
public:
    Collectable(bool isFirstScene , Vector3f CollisionBoxSize);

    void init();
    void draw();
    void onIdle();
    void onCollision(GameObject*& pObject);
};

