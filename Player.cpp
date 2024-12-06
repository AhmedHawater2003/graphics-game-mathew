#include "Player.h"
#include <stdlib.h>
#include "glut.h"
#include <Windows.h>
#include "Obstacle.h"
#include "Collectable.h"
#include "Ground.h"
#include "Goal.h"
#include "SecondScene.h"
#include "DeathScene.h"
#include "Maze.h"
#include "MazeWall.h"
#include "MazeGate.h"
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Player::Player()
	: GameObject({ 1, 1, 1 })
{
	
}

void Player::init()
{
	model_player.Load("Models/jinx/jinx.3ds");
	model_player.rot.y = -90 + 25;
}

void Player::draw()
{
	glPushMatrix();

	// Apply sparkle color if the effect is active
	if (sparkleStartTime != -1.0f) {
		glColor3f(sparkleColor[0], sparkleColor[1], sparkleColor[2]); // Yellow color for sparkle effect
	}
	else {
		glColor3f(originalColor[0], originalColor[1], originalColor[2]); // Original color
	}

	if (useCustomColor) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(color[0], color[1], color[2], color[3]);
	}

	model_player.Draw();

	if (useCustomColor) {
		glDisable(GL_BLEND);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	}
	glPopMatrix();
}

void Player::setColor(float r, float g, float b, float a) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
	useCustomColor = true;
}

void Player::resetColor() {
	useCustomColor = false;
}


void Player::onIdle()
{


	if (health <= 0) {
		Game::getInstance()->setGameOver(true);

		static float fallProgress = 0.0f;
		if (!hasFallen) {
			fallProgress = 0.0f;
			hasFallen = true;
		}

		if (fallProgress < 1.0f) {
			float fallSpeed = 0.02f;
			float newAngle = getAngle().getZ() + (90.0f - getAngle().getZ()) * fallSpeed;
			float newY = getPosition().getY() - fallSpeed * 2.0f;

			setAngle({ getAngle().getX(), getAngle().getY(), newAngle });
			//setPosition({ getPosition().getX(), newY, getPosition().getZ() });

			fallProgress += fallSpeed;
		}
		else {
			setAngle({ getAngle().getX(), getAngle().getY(), 90.0f });
			//setPosition({ getPosition().getX(), getPosition().getY() - 1.0f, getPosition().getZ() });
		}

		return;
	}


	if (obstacleCollisionAnimation) {
		static float animationTime = 0.0f;
		static float originalRotation = getAngle().getY();
		static Vector3f originalPosition = getPosition();

		// Tilt the camera
		float tiltAngle = sin(animationTime * 10) * 5.0f; // 5 degree max tilt
		setAngle({ getAngle().getX(), getAngle().getY(), tiltAngle });

		// Color the player model slightly red
		setColor(1.0f, 0.2f, 0.2f, 0.5f);

		// Slightly move the player back
		float moveBackDistance = 0.6f; // Gradually decrease the movement
		float angleRadians = originalRotation * M_PI / 180.0f;
		float moveX = moveBackDistance * sin(angleRadians);
		float moveZ = moveBackDistance * cos(angleRadians);
		setPosition({ originalPosition.getX() - moveX, originalPosition.getY(), originalPosition.getZ() + moveZ });

		animationTime += 0.016f; // Assuming 60 FPS

		if (animationTime >= 1.0f) {
			// Reset animation
			animationTime = 0.0f;
			setAngle({ getAngle().getX(), getAngle().getY(), 0 });
			resetColor(); // Reset player color
			obstacleCollisionAnimation = false;
		}
	}


	const float playerSpeed = 0.5f;
	float angleRadians = getAngle().getY() * M_PI / 180.0f;

	// Jump logic
	if (isJumping) {
		if (!isFalling) {
			// Ascend during the jump
			if (currentJumpHeight < jumpHeight) {
				// Move upward
				moveBy({ 0, jumpSpeed, 0 });
				currentJumpHeight += jumpSpeed;

				// Move forward in the direction player is facing
				moveBy({
					jumpDirectionX * (forwardJumpDistance * (currentJumpHeight / jumpHeight)),
					0,
					jumpDirectionZ * (forwardJumpDistance * (currentJumpHeight / jumpHeight))
					});
			}
			else {
				// Peak reached, start falling
				isFalling = true;
			}
		}
		else {
			// Descend during the fall
			if (currentJumpHeight > 0.0f) {
				// Move downward
				moveBy({ 0, -jumpSpeed, 0 });
				currentJumpHeight -= jumpSpeed;

				// Continue moving forward in the direction player is facing
				moveBy({
					jumpDirectionX * (forwardJumpDistance * (currentJumpHeight / jumpHeight)),
					0,
					jumpDirectionZ * (forwardJumpDistance * (currentJumpHeight / jumpHeight))
					});
			}
			else {
				// Landing
				isJumping = false;
				isFalling = false;
				currentJumpHeight = 0.0f;

				// Snap player back to ground level
				setPosition({ getPosition().getX(), -2, getPosition().getZ() });
			}
		}
	}


	if (sparkleStartTime != -1.0f) {
		// Check how much time has passed since the sparkle effect started
		float currentTime = glutGet(GLUT_ELAPSED_TIME);
		float elapsedTime = (currentTime - sparkleStartTime) / 1000.0f; // Time in seconds

		if (elapsedTime >= 2.0f) {
			// After 2 seconds, revert to the original color
			sparkleStartTime = -1.0f;
			originalColor[0] = 1.0f; // Red
			originalColor[1] = 1.0f; // Green
			originalColor[2] = 1.0f; // Blue
		}
	}

	if (!Game::getInstance()->isIsFirstScene()) {
		// Decrease health every 3 seconds
		auto currentTime = std::chrono::steady_clock::now();
		if (lastHealthUpdateTime == std::chrono::steady_clock::time_point{}) {
			lastHealthUpdateTime = currentTime; // Initialize timer
		}
		else {
			auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastHealthUpdateTime).count();
			if (elapsedTime >= 3) { // Only update health every 3 seconds
				health -= elapsedTime / 3; // Decrease health based on how many 3-second intervals have passed
				if (health < 0) health = 0; // Ensure health doesn't go below 0
				lastHealthUpdateTime += std::chrono::seconds(elapsedTime / 3 * 3); // Update timer
				std::cout << "Health decreased to: " << health << std::endl;
			}
		}
	}

}

void Player::onSpecialKeyPressed(int key, int x, int y) {
	if (Game::getInstance()->isGameOver() || Game::getInstance()->isGameWin()) return;

	const float playerSpeed = 0.5f;
	const float rotationSpeed = 2.0f;
	float angleRadians = getAngle().getY() * M_PI / 180.0f;
	float moveX = 0.0f, moveZ = 0.0f;

	switch (key) {
	case GLUT_KEY_UP:
		if (!shouldMoveForward) break;
		if (!isJumping) {
			moveX = playerSpeed * sin(angleRadians);
			moveZ = -playerSpeed * cos(angleRadians);
			moveBy({ moveX, 0, moveZ });
		}
		else {
			isMovingForwardWhileJumping = true;
		}
		break;
	case GLUT_KEY_DOWN:
		if (shouldMoveForward) break;
		moveX = -playerSpeed * sin(angleRadians);
		moveZ = playerSpeed * cos(angleRadians);
		moveBy({ moveX, 0, moveZ });
		shouldMoveForward = true;
		break;
	case GLUT_KEY_LEFT:
		rotateBy({ 0, -rotationSpeed, 0 });
		model_player.rot.y += 4;
		if (getAngle().getY() < 0.0f) rotateBy({ 0, 360, 0 });
		break;
	case GLUT_KEY_RIGHT:
		rotateBy({ 0, +rotationSpeed, 0 });
		model_player.rot.y -= 4;
		if (getAngle().getY() > 360.0f) rotateBy({ 0, -360, 0 });
		break;


	}
}


void Player::onKeyPressed(unsigned char key, int x, int y) {
	if (Game::getInstance()->isGameOver() || Game::getInstance()->isGameWin()) return;

	const float playerSpeed = 0.5f;
	const float rotationSpeed = 2.0f;
	float angleRadians = getAngle().getY() * M_PI / 180.0f;
	float moveX = 0.0f, moveZ = 0.0f;

	if (key == ' ') {
		{
			PlaySound("Sounds/jump.wav", NULL, SND_ASYNC | SND_FILENAME);
			// Jump only if not already jumping and moving forward is allowed
			if (!isJumping && !isFalling && shouldMoveForward) {
				isJumping = true;
				isFalling = false;
				currentJumpHeight = 0.0f;

				// Calculate jump direction based on current facing angle
				jumpDirectionX = sin(angleRadians);
				jumpDirectionZ = -cos(angleRadians);
			}
		}
	}
}

void Player::onSpecialKeyReleased(int key, int x, int y)
{
	if (key == GLUT_KEY_UP) {
		// Stop moving forward when UP key is released
		isMovingForwardWhileJumping = false;
	}
}

void Player::onMouse(int button, int state, int x, int y)
{
	if (Game::getInstance()->isGameOver() || Game::getInstance()->isGameWin()) return;

	if (button == GLUT_LEFT_BUTTON) {
		shouldMoveUp = state == GLUT_DOWN;

		if (shouldMoveUp) {
			PlaySound("Sounds/plane-elevate.wav", NULL, SND_ASYNC | SND_FILENAME);
		}
		else {
			PlaySound(NULL, NULL, SND_ASYNC);
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		shouldMoveDown = state == GLUT_DOWN;

		if (shouldMoveDown) {
			PlaySound("Sounds/plane-elevate.wav", NULL, SND_ASYNC | SND_FILENAME);
		}
		else {
			PlaySound(NULL, NULL, SND_ASYNC);
		}
	}
}

void Player::onCollision(GameObject*& pObject)
{
	const float playerSpeed = 0.5f;
	float angleRadians = getAngle().getY() * M_PI / 180.0f;
	float moveX = 0.0f, moveZ = 0.0f;

	Obstacle* obstacle = dynamic_cast<Obstacle*>(pObject);
	if (obstacle != nullptr) {
		PlaySound("Sounds/crash.wav", NULL, SND_ASYNC | SND_FILENAME);

		const float playerSpeed = 0.5f;
		float angleRadians = getAngle().getY() * M_PI / 180.0f;
		float moveX = -playerSpeed * sin(angleRadians);
		float moveZ = -playerSpeed * cos(angleRadians);
		moveBy({ moveX, 0, moveZ });

		obstacleCollisionAnimation = true;
		if (Game::getInstance()->isIsFirstScene()) {
			health -= 20;
		}
		else {
			health -= 25;
		}
		std::cout << "Player health: " << health << std::endl;
	}


	Collectable* collectable = dynamic_cast<Collectable*>(pObject);
	if (collectable != nullptr) {
		PlaySound("Sounds/collect.wav", NULL, SND_ASYNC | SND_FILENAME);
		collectable->setShowing(false);
		Game::getInstance()->incrementScore();

		// Start the sparkle effect by changing the player's color to yellow
		originalColor[0] = 1.0f; // Red
		originalColor[1] = 1.0f; // Green
		originalColor[2] = 1.0f; // Blue

		// Record the time when the sparkle effect started
		sparkleStartTime = glutGet(GLUT_ELAPSED_TIME);
	}

	MazeWall *wall = dynamic_cast<MazeWall*>(pObject);
	//if (wall != nullptr) {
	//	shouldMoveForward = false;
	//}
	//else {
	//	shouldMoveForward = true;
	//}

	Goal *goal = dynamic_cast<Goal*>(pObject);
	if (goal != nullptr && !Game::getInstance()->isGameWin() ) {
		if (Game::getInstance()->isIsFirstScene()) {
			goal->setShowing(false);
			hasKey = true;
		}
		else {
			Game::getInstance()->setScene(new DeathScene());
		}
	}

	MazeGate* gate = dynamic_cast<MazeGate*>(pObject);
	if (gate != nullptr && !Game::getInstance()->isGameWin() ) {
		if (hasKey) {
			Game::getInstance()->setIsFirstScene(false);
			Game::getInstance()->setScene(new SecondScene());
		}
		else
			shouldMoveForward = false;
		
	}

}
