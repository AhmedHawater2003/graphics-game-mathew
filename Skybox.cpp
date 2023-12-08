#include "Skybox.h"
#include "glut.h"

void Skybox::init() {
	tex.Load("Textures/blu-sky-3.bmp");
}

void Skybox::draw()
{
	//sky box
	glPushMatrix();

	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	glTranslated(50, 0, 0);
	glRotated(90, 1, 0, 1);
	glBindTexture(GL_TEXTURE_2D, tex.texture[0]);
	gluQuadricTexture(qobj, true);
	gluQuadricNormals(qobj, GL_SMOOTH);
	gluSphere(qobj, 1000, 1000, 1000);
	gluDeleteQuadric(qobj);


	glPopMatrix();
}
