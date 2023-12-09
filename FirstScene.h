#pragma once
#include "GameScene.h"

class FirstScene : public GameScene
{
	bool is3rdPerson = true;
	double hourOfDay = 0;
	double timeDirection = 1;
	bool scene = false; // false for the first Scene, true for the second Scene
public:
	FirstScene();

	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y);
	void onKeyPressed(unsigned char key, int x, int y);
	void setupLights();
	void onTimer(int value);
};

