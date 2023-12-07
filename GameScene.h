#ifndef GRAPHICSASSIGNMENT2_GAMESCENE_H
#define GRAPHICSASSIGNMENT2_GAMESCENE_H

#include <string>
#include <unordered_map>
#include "GameObject.h"
#include "GameSettings.h"
#include "Game.h"

class Game;

class GameObject;

class GameScene {
protected:
    std::unordered_map<std::string, GameObject *> gameObjects;
public:
    virtual ~GameScene() = default;

    virtual void init();

    virtual void draw();

    virtual void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    virtual void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    virtual void onMouse(int button, int state, int x, int y);

    virtual void onIdle();

    virtual void setupLights();

    virtual void onTimer(int value);

    template<class T>
    T *getGameObjectByTag(const std::string &tag) const {
        if (gameObjects.find(tag) == gameObjects.end()) {
            return nullptr;
        }

        return dynamic_cast<T *>(gameObjects.at(tag));
    }
};


#endif //GRAPHICSASSIGNMENT2_GAMESCENE_H
