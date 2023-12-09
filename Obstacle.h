#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class Obstacle : public GameObject
{
	bool isFirstScene;
	Model_3DS model_obstacle;
public:
	Obstacle(bool isFirstScene);
	void init();
	void draw();
};

