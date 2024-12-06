#include "MazeWall.h"
#include "glut.h"

MazeWall::MazeWall(bool isFirstScene, float x, float y, float z): lengthX(x), lengthY(y), lengthZ(z),
	isFirstScene(isFirstScene), GameObject({ 1, 1, 1 })
{
}

void MazeWall::init() {
	if (isFirstScene) {
		model_maze_wall
			.Load("Models/maze_wall/grass.3ds");
	}
	else {
		model_maze_wall
			.Load("Models/maze_wall/rock.3ds");
	}
	model_maze_wall.scale = 0.5f;
	setScale({ lengthX, lengthY, lengthZ });

}

void MazeWall::draw() {

	glPushMatrix();
	model_maze_wall.Draw();
	glPopMatrix();
}

void MazeWall::onIdle() {


}
void MazeWall::onCollision(GameObject*& pObject) {

}
