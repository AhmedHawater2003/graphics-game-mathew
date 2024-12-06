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
	else
		model_maze.Load("models/simple_maze2/maze.3ds");
	scale.start();
}

void Maze::draw() {

	glPushMatrix();
	model_maze.Draw();
	glPopMatrix();

}

void Maze::onIdle() {
	/*rotateBy({ 0, 2, 0 });
	scale.animate();*/
}