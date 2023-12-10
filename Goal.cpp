#include "Goal.h"
#include "glut.h"
#include "AnimatingValue.h"

Goal::Goal(bool isFirstScene)
	: GameObject({ 10, 10, 10 }),
	isFirstScene(isFirstScene)
{
}

void Goal::init() {
	if (isFirstScene)
		model_goal.Load("models/Flag/Flag.3ds");
	else
		model_goal.Load("models/Tropyh/Tropy star N250516.3DS");
	scale.start();
}

void Goal::draw() {

	glPushMatrix();
	glScaled(50,50,50);
	model_goal.Draw();
	glPopMatrix();

}

void Goal::onIdle() {
	Goal::rotateBy((0, 5, 0));
	scale.animate();
}