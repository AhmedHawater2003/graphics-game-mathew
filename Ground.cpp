#include "Ground.h"
#include "glut.h"

Ground::Ground(bool isFirstScene) 
	: GameObject({ 40, 1, 800 }), isFirstScene(isFirstScene) {}

void Ground::init()
{
	//if (isFirstScene) {
		texture.Load("Textures/ground.bmp");
	//}
	//else {
	//	texture.Load("Textures/close-up-mixture-clay-powder.bmp");
	//}
}

void Ground::draw()
{
    glDisable(GL_LIGHTING);
    glColor3f(0.6, 0.6, 0.6);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture.texture[0]);
    glPushMatrix();
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 0);
    glVertex3f(-10, 0, -10);
    glTexCoord2f(5, 0);
    glVertex3f(10, 0, -10);
    glTexCoord2f(5, 5);
    glVertex3f(10, 0, 10);
    glTexCoord2f(0, 5);
    glVertex3f(-10, 0, 10);
    glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
    glColor3f(1, 1, 1);
}
