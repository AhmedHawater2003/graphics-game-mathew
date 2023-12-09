#include "Obstacle.h"
#include <stdlib.h>
#include "glut.h"

Obstacle::Obstacle()
	: GameObject({ 4, 4, 4 })
{
}

void Obstacle::init()
{
	model_obstacle.Load("Models/plane/Airplane N080714.3DS"); //TODO change model
}

void Obstacle::draw()
{
	glPushMatrix();
	model_obstacle.Draw();
	glPopMatrix();
}
