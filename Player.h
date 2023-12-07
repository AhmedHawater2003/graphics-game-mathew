#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
#include "AnimatingValue.h"

class Player : public GameObject
{
	Model_3DS model_player;
public:
	Player();
	void init();
	void draw();
	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y);
	void onMouse(int button, int state, int x, int y);
};

