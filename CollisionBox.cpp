#include "CollisionBox.h"

CollisionBox::CollisionBox(const Vector3f &position, const Vector3f &size)
        : position(position), size(size) {}

Vector3f CollisionBox::getPosition() const {
    return position;
}

Vector3f CollisionBox::getStart() const {
    return position - size / 2;
}

Vector3f CollisionBox::getSize() const { return size; }

Vector3f CollisionBox::getEnd() const { return position + size / 2; }

bool CollisionBox::isColliding(const CollisionBox &other) const {
    if (getSize().length() == 0 || other.getSize().length() == 0) {
        return false;
    }

    Vector3f thisStart = getStart();
    Vector3f otherStart = other.getStart();
    Vector3f thisEnd = getEnd();
    Vector3f otherEnd = other.getEnd();

    return thisStart.getX() <= otherEnd.getX() && thisEnd.getX() >= otherStart.getX() &&
           thisStart.getY() <= otherEnd.getY() && thisEnd.getY() >= otherStart.getY() &&
           thisStart.getZ() <= otherEnd.getZ() && thisEnd.getZ() >= otherStart.getZ();
}
