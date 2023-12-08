#include "Collectable.h"
#include "glut.h"

Collectable::Collectable(bool isFirstScene) 
	: GameObject({10, 10, 10}), 
	isFirstScene(isFirstScene)
{
}

void Collectable::init() {

}

void Collectable::draw() {
	glutSolidCube(10);
}

void Collectable::onIdle() {
	
}
