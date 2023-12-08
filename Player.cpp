#include "Player.h"
#include <stdlib.h>
#include "glut.h"

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
	model_player.Draw();
	glPopMatrix();
}

void Player::onIdle()
{
	moveBy({ 0, -0.01, 0.1 });

	if (getAngle().getZ() >= 0.1 || getAngle().getZ() <= -0.1) {
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
		rotateBy({ 0.15, 0, 0 });
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
	} else {
		if (getAngle().getX() < -1) {
			rotateBy({ 0.4, 0, 0 });
		}
		else {
			setAngle({ 0, getAngle().getY(), getAngle().getZ() });
		}
	}
}

void Player::onSpecialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		if (getPosition().getX() < 50) {
			moveBy({ 0.025, 0, 0 });
			if (getAngle().getZ() > -30) {
				rotateBy({ 0, 0, -2 });
			}
		}
		break;

	case GLUT_KEY_RIGHT:
		if (getPosition().getX() > -50) {
			moveBy({ -0.025, 0, 0 });
			if (getAngle().getZ() < 30) {
				rotateBy({ 0, 0, 2 });
			}
		}
		break;
	default:
		break;
	}
}

void Player::onMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		shouldMoveUp = state == GLUT_DOWN;
	}
}
