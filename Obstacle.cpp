#include "Obstacle.h"
#include <stdlib.h>
#include "glut.h"

Obstacle::Obstacle()
	: GameObject({ 4, 4, 4 })
{
}

void Obstacle::init(bool scene)
{
	if (scene == false)
	{
		model_obstacle.Load("Models/building/buildnig-1.3DS");
	}
	else
	{
		model_obstacle.Load("Models/watertower/watertower22.3ds");
	}
}

void Obstacle::draw()
{
	glPushMatrix();
	glutSolidCube(10);
	glPopMatrix();
}
