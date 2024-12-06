#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class Torch : public GameObject
{
    bool isFirstScene;
    Model_3DS model_torch;
    int lightID; // OpenGL light ID (e.g., GL_LIGHT2)


public:
    Torch(bool isFirstScene, int lightID);
    void init();
    void draw();
    void setupLighting(); // New method for torch lighting
    void animateTorch(float maxDistance, char axis, float speed );
};
