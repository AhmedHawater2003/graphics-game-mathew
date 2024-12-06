#pragma once
#include "GameScene.h"
#include "DeathScene.h"

class SecondScene : public GameScene
{
	bool is3rdPerson = true;
	bool isTopView = false;
	double hourOfDay = 0;
	double timeDirection = 1;
	bool scene = true; // false for the first Scene, true for the second Scene
public:
	SecondScene();

	void onIdle();
	void SecondScene::onMouse(int button, int state, int x, int y);
	void onSpecialKeyPressed(int key, int x, int y);
	void onKeyPressed(unsigned char key, int x, int y);
	void setupLights();
	void onTimer(int value);
};

