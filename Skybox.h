#pragma once
#include "GameObject.h"
#include <GLTexture.h>

class Skybox :
    public GameObject
{
    GLTexture tex;
public:
    void init();
    void draw();
};

