#include <iostream>
#include "GameObject.h"

GameObject::GameObject(Vector3f collisionBoxSize)
        : CollisionBox({0, 0, 0}, collisionBoxSize) {}

void GameObject::moveBy(const Vector3f &translation) {
    setPosition(position + translation);
}

void GameObject::smoothMoveBy(const Vector3f &translation) {
    targetPosition = position + translation;
}

void GameObject::onKeyPressed(unsigned char key, int mouseX, int mouseY) {}

void GameObject::onSpecialKeyPressed(int key, int mouseX, int mouseY) {}

void GameObject::onMouse(int button, int state, int x, int y)
{
}

void GameObject::onIdle() {
    if (targetPosition != position) {
        Vector3f translation = targetPosition - position;
        if (translation.length() < 0.1) {
            position = targetPosition;
            return;
        }
        translation = translation.unit() * 0.1;
        position = position + translation;
    }

    if (targetAngle != angle) {
        Vector3f rotation = targetAngle - angle;
        if (rotation.length() < 5) {
            angle = targetAngle;
            return;
        }

        float x = rotation.getX();
        float y = rotation.getY();
        float z = rotation.getZ();

        if (x > 180) {
            x -= 360;
        } else if (x < -180) {
            x += 360;
        }

        if (y > 180) {
            y -= 360;
        } else if (y < -180) {
            y += 360;
        }

        if (z > 180) {
            z -= 360;
        } else if (z < -180) {
            z += 360;
        }

        rotation = Vector3f(x, y, z);

        rotation = rotation.unit() * 5;
        angle = angle + rotation;
    }
}

const Vector3f &GameObject::getAngle() const {
    return angle;
}

void GameObject::smoothRotateTo(const Vector3f &newAngle) {
    targetAngle = newAngle;
}

void GameObject::smoothRotateBy(const Vector3f &newAngle) {
    targetAngle = targetAngle + newAngle;
}

void GameObject::rotateBy(const Vector3f &rotationAngle) {
    angle = angle + rotationAngle;
}

const Vector3f &GameObject::getScale() const {
    return scale;
}

GameObject *GameObject::setScale(const Vector3f &newScale) {
    scale = newScale;
    size = {size.getX() * newScale.getX(),
            size.getY() * newScale.getY(),
            size.getZ() * newScale.getZ()};
    return this;
}

GameObject *GameObject::setPosition(const Vector3f &newPosition) {
    position = newPosition;
    targetPosition = newPosition;
    return this;
}

GameObject *GameObject::setAngle(const Vector3f &newAngle) {
    angle = newAngle;
    targetAngle = newAngle;
    return this;
}

void GameObject::onCollision(GameObject *&pObject) {

}

bool GameObject::isShowing() const {
    return showing;
}

GameObject * GameObject::setShowing(bool newShowing) {
    showing = newShowing;
    return this;
}

void GameObject::draw() {

}

void GameObject::onTimer(int value) {

}

void GameObject::init() {

}