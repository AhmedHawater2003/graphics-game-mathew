#include "Obstacle.h"
#include <stdlib.h>
#include "glut.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Obstacle::Obstacle(bool isFirstScene) : GameObject({ 1.8, 0.5, 1.8 }), isFirstScene(isFirstScene) {
    warningLightIntensity = 0.0f;
    warningLightPhase = 0.0f;
    glowRadius = 3.0f;
    glowIntensity = 0.5f;
}

void Obstacle::init() {
    if (isFirstScene == false) {
        model_obstacle.Load("Models/bomb/bomb.3ds");
    }
    else {
        model_obstacle.Load("Models/trap/trap.3DS");
        model_obstacle.pos = { 0.28,0,0.7 };
    }
}

void Obstacle::draw() {
    glPushMatrix();
    if (!isFirstScene) {
        glScaled(2, 2, 2);
    }
    else {
        glScaled(3, 3, 3);
    }
    model_obstacle.Draw();

    // Draw the warning light
    glPushMatrix();
    glTranslatef(0, 2.0f, 0); // Position the light above the obstacle
    glDisable(GL_LIGHTING);
    glColor4f(1.0f, 0.0f, 0.0f, warningLightIntensity); // Red color with varying intensity
    glutSolidSphere(0.2, 10, 10);
    glEnable(GL_LIGHTING);
    glPopMatrix();

    // Set up the warning light
    GLfloat light_position[] = { 0.0f, 2.0f, 0.0f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 0.0f, 0.0f, warningLightIntensity };
    glLightfv(GL_LIGHT2, GL_POSITION, light_position);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
    glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.5f);
    glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.05f);

    glPopMatrix();

    // Draw the ground glow
    drawGroundGlow();
}

void Obstacle::updateWarningLight(float deltaTime) {
    warningLightPhase += deltaTime * 2.0f; // Adjust the 2.0f to change the pulsing speed
    if (warningLightPhase > 2 * M_PI) {
        warningLightPhase -= 2 * M_PI;
    }
    warningLightIntensity = (sin(warningLightPhase) + 1.0f) * 0.5f; // Pulsing effect
    glowIntensity = warningLightIntensity * 0.5f; // Sync ground glow with warning light
}

void Obstacle::drawGroundGlow() {
    glPushMatrix();
    glTranslatef(0, 0.01f, 0); // Slightly above the ground to prevent z-fighting
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glBegin(GL_TRIANGLE_FAN);
    glColor4f(1.0f, 0.0f, 0.0f, glowIntensity);
    glVertex3f(0, 0, 0); // Center of the glow

    for (int i = 0; i <= 360; i += 10) {
        float angle = i * M_PI / 180.0f;
        float x = glowRadius * cos(angle);
        float z = glowRadius * sin(angle);
        glColor4f(1.0f, 0.0f, 0.0f, 0.0f); // Fade to transparent at the edges
        glVertex3f(x, 0, z);
    }
    glEnd();

    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glPopMatrix();
}
