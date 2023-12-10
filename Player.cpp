#include "Player.h"
#include <stdlib.h>
#include "glut.h"
#include <Windows.h>
#include "Obstacle.h"
#include "Collectable.h"
#include "Ground.h"
#include "Goal.h"
#include "SecondScene.h"


Player::Player()
	: GameObject({ 3, 1, 3 })
{
}

void Player::init()
{
	model_player.Load("Models/plane/Airplane N080714.3DS");
}

void Player::draw()
{
	glPushMatrix();
	double scale = collectAnimation - collectAnimation * collectAnimation;
	glScaled(1 + 2 * scale, 1 + 2 * scale, 1 + 2 * scale);
	model_player.Draw();
	glPopMatrix();
}

void Player::onIdle()
{
	if (playCrashAnimation || playGroundCrash) {
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
		}
	}

	if (shouldMoveForward) {
		moveBy({ 0, -0.01, 0.2 });
	}
	
	if (getAngle().getZ() >= 0.1 || getAngle().getZ() <= -0.1) {
		if (getAngle().getZ() > 0) {
			rotateBy({ 0, 0, -0.6 });
		}
		else {
			rotateBy({ 0, 0, 0.6 });
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
		if (getPosition().getY() < 100) {
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
	}


}

void Player::onSpecialKeyPressed(int key, int x, int y)
{
	if (Game::getInstance()->isGameOver() || Game::getInstance()->isGameWin()) return;

	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (getPosition().getX() < 18) {
			moveBy({ 0.1, 0, 0 });
		}
		if (getAngle().getZ() > -30) {
			rotateBy({ 0, 0, -2 });
		}
		break;

	case GLUT_KEY_RIGHT:
		if (getPosition().getX() > -18) {
			moveBy({ -0.1, 0, 0 });
		}
		if (getAngle().getZ() < 30) {
			rotateBy({ 0, 0, 2 });
		}
		break;
	default:
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
	
	Goal *goal = dynamic_cast<Goal*>(pObject);
	if (goal != nullptr && !Game::getInstance()->isGameWin()) {
		goal->setShowing(false);
		shouldMoveForward = false;
		PlaySound("Sounds/win.wav", NULL, SND_ASYNC | SND_FILENAME);

		if (Game::getInstance()->isIsFirstScene()) {
			Game::getInstance()->setIsFirstScene(false);
			Game::getInstance()->setScene(new SecondScene());
		}
		else {
			Game::getInstance()->setGameWin(true);
		}
	}

	Ground* ground = dynamic_cast<Ground*>(pObject);
	if (ground != nullptr && !playCrashAnimation) {
		PlaySound("Sounds/crash.wav", NULL, SND_ASYNC | SND_FILENAME);
		playCrashAnimation = true;
	}
}
