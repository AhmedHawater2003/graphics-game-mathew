#pragma once
#include "GameObject.h"
#include <string>

class GameText :
    public GameObject
{
    std::string text;
public:
    void draw();

    GameText *setText(std::string text);
};

