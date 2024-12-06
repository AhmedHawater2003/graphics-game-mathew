#pragma once
#include "GameObject.h"
#include "Model_3DS.h"

class Torch : public GameObject
{
	bool isFirstScene;
	Model_3DS model_torch;

public:
	Torch(bool isFirstScene);
	void init();
	void draw();
};