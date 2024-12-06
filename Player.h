#pragma once
#include "GameObject.h"
#include "Model_3DS.h"
#include "AnimatingValue.h"
#include <chrono>

class Player : public GameObject
{
	Model_3DS model_player;
	bool shouldMoveUp = false;
	bool shouldMoveDown = false;
	bool shouldMoveForward = true;
	bool playCrashAnimation = false;
	bool playGroundCrash = false;
	int score = 0;

	bool isJumping = false;           // Is the player currently jumping?
	bool isFalling = false;           // Is the player falling back to the ground?
	float jumpHeight = 2.0f;          // Maximum height of the jump
	float currentJumpHeight = 0.0f;   // Current height during the jump
	float jumpSpeed = 0.1f;           // Speed at which the player moves up/down during the jump
	float jumpStartZ = 0.0f;          // Starting Z position for jumping
	float forwardJumpDistance = 0.25f; // Maximum forward distance while jumping
	float jumpProgress = 0.0f;        // Progress (0.0 to 1.0) of the forward jump
	bool isMovingForwardWhileJumping = false; // Whether the player is moving forward during the jump
	float jumpDirectionX = 0.0f;
	float jumpDirectionZ = 0.0f;
	bool obstacleCollisionAnimation = false;
	bool wallCollision = false;


	bool playCollectAnimation = false;
	double collectAnimation = 0;
	void setColor(float r, float g, float b, float a);
	void resetColor();
	float color[4];
	bool useCustomColor= false;
	bool hasFallen = false;
	std::chrono::steady_clock::time_point lastHealthUpdateTime;


	
	// Add variables for sparkle effect
	float originalColor[3] = { 1.0f, 1.0f, 1.0f }; // Default color is white
	float sparkleColor[3] = { 1.0f, 1.0f, 0.0f }; // Yellow color
	float sparkleStartTime = -1.0f; // Start time of the sparkle effect



public:
	Player();
	struct Vector {
		float x;
		float y;
		float z;
	};
	double health = 100;
	bool hasKey = false;
	bool isColliding = false;
	void init();
	void draw();
	void onIdle();
	void onSpecialKeyPressed(int key, int x, int y);
	void onSpecialKeyReleased(int key, int x, int y);
	void onKeyPressed(unsigned char key, int x, int y);
	void onMouse(int button, int state, int x, int y);
	void onCollision(GameObject*& pObject);
};

