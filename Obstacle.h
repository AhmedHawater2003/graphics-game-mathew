#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class Obstacle : public GameObject
{
	Model_3DS model_obstacle;
public:
	Obstacle();
	void init();
	void draw();
};

