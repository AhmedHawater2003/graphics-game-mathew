#include "Obstacle.h"
#include "glut.h"

void Obstacle::draw()
{
	glPushMatrix();
	glutSolidCube(10);
	glPopMatrix();
}
