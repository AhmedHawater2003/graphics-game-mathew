#include "utils.h"
#include <stdlib.h>
#include <glut.h>


void color(long hex) {
    short r = (hex >> 16) & 0xFF;
    short g = (hex >> 8) & 0xFF;
    short b = hex & 0xFF;
    color(r, g, b);
}

void color(short r, short g, short b) {
    glColor3d(r / 255.0, g / 255.0, b / 255.0);
}


void cylinder(double radius, double height) {
    GLUquadricObj *quadratic1 = gluNewQuadric();
    GLUquadricObj *quadratic2 = gluNewQuadric();
    GLUquadricObj *quadratic3 = gluNewQuadric();

    gluCylinder(quadratic1, radius, radius, height, 255, 255);
    glPushMatrix();
    glTranslatef(0, 0, height);
    gluDisk(quadratic2, 0, radius, 255, 255);
    glPopMatrix();
    gluDisk(quadratic3, 0, radius, 255, 255);

    gluDeleteQuadric(quadratic1);
    gluDeleteQuadric(quadratic2);
    gluDeleteQuadric(quadratic3);
}

void drawText(const std::string &text, int x, int y, int c) {
    glDisable(GL_LIGHTING);
    color(c);
    glRasterPos2d(0, 0);
    for (char i: text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }
    glEnable(GL_LIGHTING);
}
