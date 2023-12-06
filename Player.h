#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class Player : public GameObject
{
	Model_3DS model_player;

public:
	Player();
	void init();
	void draw();
};

