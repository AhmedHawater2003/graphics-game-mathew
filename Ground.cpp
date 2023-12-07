#include "Ground.h"

Ground::Ground() : GameObject({ 20, 1, 200 }) {}

void Ground::init()
{
	texture.Load("Textures/asphalt-texture-close-up.bmp");
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
	glVertex3f(-10, 0, -100);
	glTexCoord2f(1, 0);
	glVertex3f(10, 0, -100);
	glTexCoord2f(1, 10);
	glVertex3f(10, 0, 100);
	glTexCoord2f(0, 10);
	glVertex3f(-10, 0, 100);
	glEnd();
	glPopMatrix();
}
