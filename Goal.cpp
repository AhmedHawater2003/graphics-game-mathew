#include "Goal.h"
#include "glut.h"
#include "AnimatingValue.h"

Goal::Goal(bool isFirstScene)
	: GameObject({ 5, 7, 5 }),
	isFirstScene(isFirstScene)
{
}

void Goal::init() {
	if (isFirstScene) {
		model_goal.Load("models/key/key.3ds");
		model_goal.scale = 70;
		model_goal.pos = { 0, 2, 0 };
		model_goal.rot.y = 90;
	}
	else {
		model_goal.Load("models/treasure/treasure.3ds");
		model_goal.scale = 5;
		model_goal.pos = { 0, 2, 0 };
	}
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