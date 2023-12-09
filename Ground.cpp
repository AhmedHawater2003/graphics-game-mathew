#include "Ground.h"
#include "glut.h"

Ground::Ground(bool isFirstScene) 
	: GameObject({ 40, 1, 800 }), isFirstScene(isFirstScene) {}

void Ground::init()
{
	if (isFirstScene) {
		texture.Load("Textures/asphalt-texture-close-up.bmp");
	}
	else {
		texture.Load("Textures/close-up-mixture-clay-powder.bmp");
	}
}

void Ground::draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, texture.texture[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glPushMatrix();
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-20, 0, -400);
	glTexCoord2f(1, 0);
	glVertex3f(20, 0, -400);
	glTexCoord2f(1, 10);
	glVertex3f(20, 0, 400);
	glTexCoord2f(0, 10);
	glVertex3f(-20, 0, 400);
	glEnd();
	glPopMatrix();	
}
