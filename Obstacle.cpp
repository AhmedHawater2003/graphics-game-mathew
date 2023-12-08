#include "Obstacle.h"
#include "glut.h"

Obstacle::Obstacle() : GameObject({10, 10, 10})
{
}

void Obstacle::draw()
{
	glPushMatrix();
	glutSolidCube(10);
	glPopMatrix();
}
