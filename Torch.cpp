#include "Torch.h"
#include <stdlib.h>
#include "glut.h"

Torch::Torch(bool isFirstScene)
	: GameObject({ 1.8, 0.5, 1.8 }),
	isFirstScene(isFirstScene)
{
}


void Torch::init()
{

	model_torch.Load("Models/torch/torch.3ds");

}

void Torch::draw()
{
	glPushMatrix();
	glScaled(2, 2, 2);

	model_torch.Draw();
	glPopMatrix();
}