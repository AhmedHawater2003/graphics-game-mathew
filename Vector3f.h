#ifndef GRAPHICSASSIGNMENT2_VECTOR3F_H
#define GRAPHICSASSIGNMENT2_VECTOR3F_H


class Vector3f {
protected:
    float x, y, z;
public:
    Vector3f(float x, float y, float z);

    [[nodiscard]] const float &getX() const;

    [[nodiscard]] const float &getY() const;

    [[nodiscard]] const float &getZ() const;

    Vector3f operator+(Vector3f v) const;

    Vector3f operator-(Vector3f v) const;

    Vector3f operator*(float n) const;

    Vector3f operator/(float n) const;

    float operator[](int i) const;

    bool operator==(Vector3f v) const;

    bool operator!=(Vector3f v) const;

    [[nodiscard]] Vector3f unit() const;

    [[nodiscard]] Vector3f cross(Vector3f v) const;

    [[nodiscard]] float length() const;

    Vector3f rotateY(double angle);
};


#endif //GRAPHICSASSIGNMENT2_VECTOR3F_H
