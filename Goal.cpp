#include "Goal.h"
#include "glut.h"
#include "AnimatingValue.h"

Goal::Goal(bool isFirstScene)
	: GameObject({ 8, 10, 8 }),
	isFirstScene(isFirstScene)
{
}

void Goal::init() {
	if (isFirstScene)
		model_goal.Load("models/Flag/Flag.3ds");
	else
		model_goal.Load("models/Trophy/Trophy star N250516.3DS");
	scale.start();
}

void Goal::draw() {

	glPushMatrix();
	glScaled(1 + scale.getValue(), 1 + scale.getValue(), 1 + scale.getValue());
	if (isFirstScene) {
		glScaled(0.05, 0.05, 0.05);
	}
	model_goal.Draw();
	glPopMatrix();

}

void Goal::onIdle() {
	/*rotateBy({ 0, 2, 0 });
	scale.animate();*/
}