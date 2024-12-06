#include "Goal.h"
#include "glut.h"
#include "AnimatingValue.h"

Goal::Goal(bool isFirstScene)
	: GameObject({ 5, 7, 5 }),
	isFirstScene(isFirstScene)
{
}

void Goal::init() {
	if (isFirstScene)
		model_goal.Load("models/Trophy/Trophy star N250516.3DS");
	else
		model_goal.Load("models/Trophy/Trophy star N250516.3DS");
}

void Goal::draw() {

	glPushMatrix();
	model_goal.Draw();
	glPopMatrix();

}

void Goal::onIdle() {
	/*rotateBy({ 0, 2, 0 });
	scale.animate();*/
}