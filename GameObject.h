#ifndef GRAPHICSASSIGNMENT2_GAMEOBJECT_H
#define GRAPHICSASSIGNMENT2_GAMEOBJECT_H

#include "Vector3f.h"
#include "CollisionBox.h"
#include "Game.h"

class GameObject : public CollisionBox {
protected:
    Vector3f targetPosition{0, 0, 0};

    Vector3f angle{0, 0, 0};
    Vector3f targetAngle{0, 0, 0};

    Vector3f scale{1, 1, 1};

    bool showing = true;
public:

public:
    explicit GameObject(Vector3f collisionBoxSize = {0, 0, 0});

    virtual void init();

    ~GameObject() override = default;

    virtual void draw();

    virtual void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    virtual void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    virtual void onMouse(int button, int state, int x, int y);

    virtual void onIdle();

    [[nodiscard]] const Vector3f &getAngle() const;

    void rotateBy(const Vector3f &rotationAngle);

    void moveBy(const Vector3f &translation);

    void smoothMoveBy(const Vector3f &translation);

    void smoothRotateTo(const Vector3f &newAngle);

    [[nodiscard]] const Vector3f &getScale() const;

    GameObject *setScale(const Vector3f &newScale);

    GameObject *setPosition(const Vector3f &newPosition);

    GameObject *setAngle(const Vector3f &newAngle);

    void smoothRotateBy(const Vector3f &newAngle);

    virtual void onCollision(GameObject *&pObject);

    [[nodiscard]] bool isShowing() const;

    GameObject * setShowing(bool newShowing);

    virtual void onTimer(int value);
};


#endif //GRAPHICSASSIGNMENT2_GAMEOBJECT_H
