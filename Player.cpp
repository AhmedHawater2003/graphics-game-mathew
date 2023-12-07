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

	if (getAngle().getY() >= 0.1 || getAngle().getY() <= -0.1) {
		if (getAngle().getY() > 0) {
			rotateBy({ 0, -0.15, 0 });
		}
		else {
			rotateBy({ 0, 0.15, 0 });
		}
	}
	else {
		setAngle({ getAngle().getX(), 0, getAngle().getZ()});
	}

	if (getAngle().getX() < -1) {
		rotateBy({ 0.15, 0, 0 });
	}
	else {
		setAngle({ 0, getAngle().getY(), getAngle().getZ() });
	}
}

void Player::onSpecialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		moveBy({ 0.1, 0, 0 });
		rotateBy({ 0, 1, 0 });
		break;

	case GLUT_KEY_RIGHT:
		moveBy({ -0.1, 0, 0 });
		rotateBy({ 0, -1, 0 });
		break;

	default:
		break;
	}
}

void Player::onMouse(int button, int state, int x, int y)
{
	moveBy({ 0, 0.1, 0 });
	rotateBy({ -5, 0, 0 });
}
