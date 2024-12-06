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


	//glPushMatrix();

	//// Set the color with transparency (RGBA)
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // Blue with 50% transparency
	//// Draw the cube
	//glutSolidCube(1.0f); // Cube of size 1.0, scaled by glScalef

	//glPopMatrix();


	//glPushMatrix();
	//model_maze_wall.Draw();

	//// Enable blending for transparency
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//// Set the color with transparency (RGBA)
	//glColor4f(1.0f, 1.0f, 1.0f, 1.0f); // Blue with 50% transparency
	//// Draw the cube
	//glutSolidCube(1.0f); // Cube of size 1.0, scaled by glScalef

	////// Disable blending (optional, if no further blending is required)
	//glDisable(GL_BLEND);

	//glPopMatrix();
}

void MazeWall::onIdle() {


}
void MazeWall::onCollision(GameObject*& pObject) {

}
