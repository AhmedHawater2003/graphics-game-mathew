#include "Maze.h"
#include "glut.h"
#include "AnimatingValue.h"

Maze::Maze(bool isFirstScene)
	: GameObject({ 8, 10, 8 }),
	isFirstScene(isFirstScene)
{
}

void Maze::init() {
	if (isFirstScene)
		model_maze.Load("models/simple_maze/maze.3ds");
	//else
	//	model_maze.Load("models/Trophy/Trophy star N250516.3DS");
	scale.start();
}

void Maze::draw() {

	glPushMatrix();
	//glTranslatef(-1, -1, 0);
	//glScalef(2, 2, 2);
	model_maze.Draw();
	glPopMatrix();

}

void Maze::onIdle() {
	/*rotateBy({ 0, 2, 0 });
	scale.animate();*/
}