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
		model_obstacle.Load("Models/plane/Airplane N080714.3DS"); //TODO change model
	}
	else
	{
		model_obstacle.Load("Models/plane/Airplane N080714.3DS"); //TODO change model
	}
}

void Obstacle::draw()
{
	glPushMatrix();
	glutSolidCube(10);
	glPopMatrix();
}
