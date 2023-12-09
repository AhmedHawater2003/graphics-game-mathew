#include "Obstacle.h"
#include <stdlib.h>
#include "glut.h"

Obstacle::Obstacle(bool isFirstScene)
	: GameObject({ 4, 4, 4 }),
	  isFirstScene(isFirstScene)
{
}

void Obstacle::init()
{
	if (isFirstScene == false)
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
	model_obstacle.Draw();
	glPopMatrix();
}
