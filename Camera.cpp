#include <math.h>
#include <stdlib.h>
#include <glut.h>
#include "Camera.h"
#include <iostream>

#define DEG2RAD(a) (a * 0.0174532925)

Camera::Camera(Vector3f eye, Vector3f center, Vector3f up, double aspectRatio)
        : eye(eye), center(center), up(up), aspectRatio(aspectRatio) {

}

void Camera::moveX(float d) {
    Vector3f right = up.cross(center - eye).unit();
    eye = eye + right * d;
    center = center + right * d;
}

void Camera::moveY(float d) {
    eye = eye + up.unit() * d;
    center = center + up.unit() * d;
}

void Camera::moveZ(float d) {
    Vector3f view = (center - eye).unit();
    eye = eye + view * d;
    center = center + view * d;
}

void Camera::rotateX(float a) {
    Vector3f view = (center - eye).unit();
    Vector3f right = up.cross(view).unit();
    view = view * cos(DEG2RAD(a)) + up * sin(DEG2RAD(a));
    up = view.cross(right);
    center = eye + view;
}

void Camera::rotateY(float a) {
    Vector3f view = (center - eye).unit();
    Vector3f right = up.cross(view).unit();
    view = view * cos(DEG2RAD(a)) + right * sin(DEG2RAD(a));
    right = view.cross(up);
    center = eye + view;
}

void Camera::look() const {
    gluLookAt(
            eye.getX(), eye.getY(), eye.getZ(),
            center.getX(), center.getY(), center.getZ(),
            up.getX(), up.getY(), up.getZ()
    );
}

void Camera::setup() const {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, aspectRatio, 1, 100000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    look();
}

void Camera::init()
{
    setup();
}

void Camera::onIdle()
{
    setup();
}

const Vector3f &Camera::getEye() const {
    return eye;
}

void Camera::setEye(const Vector3f &newEye) {
    eye = newEye;
}

const Vector3f &Camera::getCenter() const {
    return center;
}

void Camera::setCenter(const Vector3f &newCenter) {
    center = newCenter;
}

const Vector3f &Camera::getUp() const {
    return up;
}

void Camera::setUp(const Vector3f &newUp) {
    up = newUp;
}
