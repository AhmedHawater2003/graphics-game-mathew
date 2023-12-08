#include "Goal.h"
#include "glut.h"

Goal::Goal(bool isFirstScene)
	: GameObject({ 10, 10, 10 }),
	isFirstScene(isFirstScene)
{
}

void Goal::init() {

}

void Goal::draw() {
	glutSolidCube(10);
}

void Goal::onIdle() {

}