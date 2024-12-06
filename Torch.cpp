#include "Torch.h"
#include <glut.h>
#include <cmath>

Torch::Torch(bool isFirstScene, int lightID)
    : GameObject({ 1.8, 0.5, 1.8 }),
    isFirstScene(isFirstScene),
    lightID(lightID) // Store the light ID
{
}

void Torch::init()
{
    model_torch.Load("Models/torch/torch.3ds");
}

void Torch::draw()
{
    glPushMatrix();
    glScaled(2, 2, 2);
    model_torch.Draw();
    glPopMatrix();
}

void Torch::setupLighting()
{
    GLfloat light_position[] = {
        getPosition().getX(),
        getPosition().getY() + 5.0f, // Offset for light above the torch
        getPosition().getZ(),
        1.0f
    };
    GLfloat light_ambient[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    GLfloat light_diffuse[] = { 1.0f, 0.5f, 0.0f, 1.0f }; // Orange glow
    GLfloat light_specular[] = { 1.0f, 0.5f, 0.0f, 1.0f }; // Slight specular
    GLfloat spot_direction[] = { 0.0f, -0.5f, 0.0f };       // Downward spotlight

    glEnable(lightID);
    glLightfv(lightID, GL_POSITION, light_position);
    glLightfv(lightID, GL_AMBIENT, light_ambient);
    glLightfv(lightID, GL_DIFFUSE, light_diffuse);
    glLightfv(lightID, GL_SPECULAR, light_specular);
    glLightf(lightID, GL_SPOT_CUTOFF, 45.0f);  // Spotlight angle
    glLightfv(lightID, GL_SPOT_DIRECTION, spot_direction);
    glLightf(lightID, GL_SPOT_EXPONENT, 150.0f); // Focus intensity
}

void Torch::animateTorch(float maxDistance, char axis, float speed = 0.02f) {
    static float time = 0.0f;

    float displacement = sin(time) * maxDistance;

    auto currentPos = getPosition();

    if (axis == 'x') {
        setPosition({ currentPos.getX() + displacement, currentPos.getY(), currentPos.getZ() });
    }
    else if (axis == 'z') {
        setPosition({ currentPos.getX(), currentPos.getY(), currentPos.getZ() + displacement });
    }

    setupLighting();

    time += speed;
}