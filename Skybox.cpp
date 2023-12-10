#include "Skybox.h"
#include "glut.h"

Skybox::Skybox(bool isFirstScene) : isFirstScene(isFirstScene)
{
}

void Skybox::init() {
	if (isFirstScene) {
		tex.Load("Textures/blu-sky-3.bmp");
	}
	else {
		tex.Load("Textures/starry-night-sky.bmp");
	}

}

void Skybox::draw()
{
	glDisable(GL_COLOR_MATERIAL);
	//sky box
	glPushMatrix();

	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	glTranslated(50, 0, 0);
	glRotated(-90, 1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, tex.texture[0]);
	gluQuadricTexture(qobj, true);
	gluQuadricNormals(qobj, GL_SMOOTH);
	gluSphere(qobj, 1000, 1000, 1000);
	gluDeleteQuadric(qobj);


	glPopMatrix();
	glEnable(GL_COLOR_MATERIAL);
}
