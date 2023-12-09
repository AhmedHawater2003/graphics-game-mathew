#pragma once
#include "GameObject.h"
#include <GLTexture.h>

class Skybox :
    public GameObject
{
    bool isFirstScene;
    GLTexture tex;
public:
    Skybox(bool isFirstScene);
    void init();
    void draw();
};

