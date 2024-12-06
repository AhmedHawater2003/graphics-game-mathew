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
	bool obstacleCollisionAnimation = false;

	bool playCollectAnimation = false;
	double collectAnimation = 0;
	double health = 100;
	void setColor(float r, float g, float b, float a);
	void resetColor();
	float color[4];
	bool useCustomColor= false;

public:
	Player();
	struct Vector {
		float x;
		float y;
		float z;
	};
	bool hasKey = false;
	void init();
	void draw();
	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y);
	void onMouse(int button, int state, int x, int y);
	void onCollision(GameObject*& pObject);
};

