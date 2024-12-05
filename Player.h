#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
#include "AnimatingValue.h"

class Player : public GameObject
{
	Model_3DS model_player;
	bool shouldMoveUp = false;
	bool shouldMoveDown = false;
	bool shouldMoveForward = true;
	bool playCrashAnimation = false;
	bool playGroundCrash = false;

	bool playCollectAnimation = false;
	double collectAnimation = 0;
public:
	Player();
	struct Vector {
		float x;
		float y;
		float z;
	};
	void init();
	void draw();
	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y);
	void onMouse(int button, int state, int x, int y);
	void onCollision(GameObject*& pObject);
};

