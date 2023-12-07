#pragma once
#include "GameScene.h"

class FirstScene : public GameScene
{
	bool is3rdPerson = true;
public:
	FirstScene();

	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y);
	void onKeyPressed(unsigned char key, int x, int y);
};

