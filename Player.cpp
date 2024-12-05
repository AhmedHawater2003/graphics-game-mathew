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
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


Player::Player()
	: GameObject({ 3, 1, 3 })
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
	model_player.Draw();
	glPopMatrix();
}

void Player::onIdle()
{
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

	const float playerSpeed = 0.1f;
	const float rotationSpeed = 2.0f;
	float angleRadians = getAngle().getY() * M_PI / 180.0f;
	printf("Angle: %f\n", getAngle().getY());
	float moveX = 0.0f, moveZ = 0.0f;

	switch (key) {
	case GLUT_KEY_UP:
		moveX = playerSpeed * sin(angleRadians);
		moveZ = -playerSpeed * cos(angleRadians);
		moveBy({ moveX, 0, moveZ });
		break;
	case GLUT_KEY_DOWN:
		moveX = -playerSpeed * sin(angleRadians);
		moveZ = playerSpeed * cos(angleRadians);
		moveBy({ moveX, 0, moveZ });
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

	printf("Position: %f, %f, %f\n", getPosition().getX(), getPosition().getY(), getPosition().getZ());
	printf("Movex: %f, Movez: %f\n", moveX, moveZ);
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
	Obstacle *obstacle = dynamic_cast<Obstacle*>(pObject);
	if (obstacle != nullptr && !playCrashAnimation) {
		PlaySound("Sounds/crash.wav", NULL, SND_ASYNC | SND_FILENAME);
		playCrashAnimation = true;
	}

	Collectable *collectable = dynamic_cast<Collectable*>(pObject);
	if (collectable != nullptr && !playCollectAnimation) {
		PlaySound("Sounds/collect.wav", NULL, SND_ASYNC | SND_FILENAME);
		playCollectAnimation = true;
		collectable->setShowing(false);
		Game::getInstance()->incrementScore();
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
