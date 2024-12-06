#include "Player.h"
#include <stdlib.h>
#include "glut.h"
#include <Windows.h>
#include "Obstacle.h"
#include "Collectable.h"
#include "Ground.h"
#include "Goal.h"
#include "SecondScene.h"
#include "Maze.h"
#include "MazeWall.h"
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

	model_player.Draw();
	glPopMatrix();
}


void Player::onIdle()
{
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
	/*if (playCrashAnimation || playGroundCrash) {
		Game::getInstance()->setGameOver(true);

		if (getPosition().getY() >= 5) {
			moveBy({ 0, -0.1, 0 });
			rotateBy({ 0, 2, 0 });
		}

		return;
	}

	if (playCollectAnimation) {
		collectAnimation += 0.01;
		if (collectAnimation >= 1) {
			collectAnimation = 0;
			playCollectAnimation = false;
		}*/
	

	
	/*if (getAngle().getZ() >= 0.1 || getAngle().getZ() <= -0.1) {
		if (getAngle().getZ() > 0) {
			rotateBy({ 0, 0, -0.15 });
		}
		else {
			rotateBy({ 0, 0, 0.15 });
		}
	}
	else {
		setAngle({ getAngle().getX(), getAngle().getY(), 0});
	}
	

	if (getAngle().getX() < -1) {
		rotateBy({ 0.3, 0, 0 });
	}
	else {
		setAngle({ 0, getAngle().getY(), getAngle().getZ() });
	}

	if (shouldMoveUp) {
		if (getPosition().getY() < 30) {
			moveBy({ 0, 0.05, 0 });
		}
		if (getAngle().getX() > -30) {
			rotateBy({ -1.5, 0, 0 });
		}
	} 

	if (shouldMoveDown) {
		moveBy({ 0, -0.1, 0 });
		if (getAngle().getX() > 30) {
			rotateBy({ 2, 0, 0 });
		}
	}
	
	if (!shouldMoveUp && ! shouldMoveDown) {
		if (getAngle().getX() < -1 || getAngle().getX() > 1) {
			if (getAngle().getX() > 0) {
				rotateBy({ -0.4, 0, 0 });
			}
			else {
				rotateBy({ 0.4, 0, 0 });
			}
		}
		else {
			setAngle({ 0, getAngle().getY(), getAngle().getZ() });
		}
	}*/


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
		if(shouldMoveForward) break;
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
	//case ' ':
	//	PlaySound("Sounds/jump.wav", NULL, SND_ASYNC | SND_FILENAME);
		// Jump only if not already jumping and moving forward is allowed
	//	if (!isJumping && !isFalling && shouldMoveForward) {
	 //	isJumping = true;
	//		isFalling = false;
	//		currentJumpHeight = 0.0f;

			// Calculate jump direction based on current facing angle
		//	jumpDirectionX = sin(angleRadians);
		//	jumpDirectionZ = -cos(angleRadians);
	//	}
	//	break;
		
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
	//Obstacle *obstacle = dynamic_cast<Obstacle*>(pObject);
	//if (obstacle != nullptr && !playCrashAnimation) {
	//	PlaySound("Sounds/crash.wav", NULL, SND_ASYNC | SND_FILENAME);
	//	playCrashAnimation = true;
	//}

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
	if (wall != nullptr ) {
		shouldMoveForward = false;
	}
	else {
		shouldMoveForward = true;
	}

	//if (goal != nullptr && !Game::getInstance()->isGameWin()) {
	//	goal->setShowing(false);
	//	shouldMoveForward = false;
	//	PlaySound("Sounds/win.wav", NULL, SND_ASYNC | SND_FILENAME);

	//	if (Game::getInstance()->isIsFirstScene()) {
	//		Game::getInstance()->setIsFirstScene(false);
	//		Game::getInstance()->setScene(new SecondScene());
	//	}
	//	else {
	//		Game::getInstance()->setGameWin(true);
	//	}
	//}

}
