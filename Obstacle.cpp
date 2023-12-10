#include "Obstacle.h"
#include <stdlib.h>
#include "glut.h"

Obstacle::Obstacle(bool isFirstScene)
	: GameObject({ 6, 50, 6 }),
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
	if (!isFirstScene) {
		glScaled(70, 70, 70);
	}
	model_obstacle.Draw();
	glPopMatrix();
}
