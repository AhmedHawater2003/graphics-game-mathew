#include <cmath>
#include "Vector3f.h"

#define DEG2RAD(a) (a * 0.0174532925)

Vector3f::Vector3f(float x, float y, float z)
        : x(x), y(y), z(z) {}


const float &Vector3f::getX() const { return x; }

const float &Vector3f::getY() const { return y; }

const float &Vector3f::getZ() const { return z; }

Vector3f Vector3f::operator+(Vector3f v) const {
    return {x + v.x, y + v.y, z + v.z};
}

Vector3f Vector3f::operator-(Vector3f v) const {
    return {x - v.x, y - v.y, z - v.z};
}

Vector3f Vector3f::operator*(float n) const {
    return {x * n, y * n, z * n};
}

Vector3f Vector3f::operator/(float n) const {
    return {x / n, y / n, z / n};
}

bool Vector3f::operator==(Vector3f v) const {
    return x == v.x && y == v.y && z == v.z;
}

bool Vector3f::operator!=(Vector3f v) const {
    return x != v.x || y != v.y || z != v.z;
}

Vector3f Vector3f::unit() const {
    if (x == 0 && y == 0 && z == 0) {
        return {0, 0, 0};
    }

    return *this / std::sqrt(x * x + y * y + z * z);
}

Vector3f Vector3f::cross(Vector3f v) const {
    return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
}

float Vector3f::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

float Vector3f::operator[](int i) const {
    return i == 0 ? x : i == 1 ? y : z;
}

Vector3f Vector3f::rotateY(double angle) {

    return {
            (float) (x * std::cos(DEG2RAD(angle)) + z * std::sin(DEG2RAD(angle))),
            y,
            (float) (z * std::cos(DEG2RAD(angle)) - x * std::sin(DEG2RAD(angle)))
    };
}

