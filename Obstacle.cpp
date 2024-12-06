#include "Obstacle.h"
#include <stdlib.h>
#include "glut.h"

Obstacle::Obstacle(bool isFirstScene)
	: GameObject({ 1.8, 0.5, 1.8 }),
	isFirstScene(isFirstScene)
{
}


void Obstacle::init()
{
	if (isFirstScene == false)
	{
		model_obstacle.Load("Models/bomb/bomb.3ds");
	}
	else
	{
		model_obstacle.Load("Models/trap/trap.3DS");
		model_obstacle.pos = { 0.28,0,0.7 };

	}
}

void Obstacle::draw()
{
	glPushMatrix();
	if (!isFirstScene) {
		glScaled(2, 2, 2);
	}
	else {
		glScaled(3, 3, 3);
	}
	model_obstacle.Draw();
	glPopMatrix();
}
