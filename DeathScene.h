#pragma once
#include "GameScene.h"

class DeathScene :
	public GameScene
{
	bool is3rdPerson = true;
	double hourOfDay = 0;
	double timeDirection = 1;
public:
	DeathScene();

	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y) {};
	void onKeyPressed(unsigned char key, int x, int y) {};
	void setupLights() {};
	void onTimer(int value) {};
};
