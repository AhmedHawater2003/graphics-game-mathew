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
	if (health<=0) {
		Game::getInstance()->setGameOver(true);

		if (getPosition().getY() >= 5) {
			moveBy({ 0, -0.1, 0 });
			rotateBy({ 0, 2, 0 });
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

		// Color the collided obstacle slightly red
		/*if (lastCollidedObstacle) {
			lastCollidedObstacle->setColor(1.0f, 0.2f, 0.2f, 0.5f);
		}*/

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
			//if (lastCollidedObstacle) {
			//	lastCollidedObstacle->resetColor(); // Reset obstacle color
			//	lastCollidedObstacle = nullptr;
			//}
			//setPosition(originalPosition); // Reset position
			obstacleCollisionAnimation = false;
		}
	}

	/*if (playCollectAnimation) {
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
		if(!shouldMoveForward) break;
		moveX = playerSpeed * sin(angleRadians);
		moveZ = -playerSpeed * cos(angleRadians);
		moveBy({ moveX, 0, moveZ });
		//playCrashAnimation = false;
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

		if (Game::getInstance()->isIsFirstScene()) {
			health -= 20;
			obstacleCollisionAnimation = true;
			//lastCollidedObstacle = obstacle; // Store the collided obstacle
		}
		else {
			health -= 25;
		}
		std::cout << "Player health: " << health << std::endl;
	}


	//Collectable *collectable = dynamic_cast<Collectable*>(pObject);
	//if (collectable != nullptr && !playCollectAnimation) {
	//	PlaySound("Sounds/collect.wav", NULL, SND_ASYNC | SND_FILENAME);
	//	playCollectAnimation = true;
	//	collectable->setShowing(false);
	//	Game::getInstance()->incrementScore();
	//}

	MazeWall *wall = dynamic_cast<MazeWall*>(pObject);
	if (wall != nullptr) {
		shouldMoveForward = false;
	}
	else {
		shouldMoveForward = true;
	}

	Goal *goal = dynamic_cast<Goal*>(pObject);
	if (goal != nullptr && !Game::getInstance()->isGameWin()) {
		goal->setShowing(false);
		hasKey = true;
	}

	MazeGate* gate = dynamic_cast<MazeGate*>(pObject);
	if (gate != nullptr && !Game::getInstance()->isGameWin()) {
		if(hasKey)
			Game::getInstance()->setScene(new SecondScene());
		else
			shouldMoveForward = false;
		
	}

}
