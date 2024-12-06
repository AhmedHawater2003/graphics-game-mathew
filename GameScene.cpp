#include <stdlib.h>
#include <glut.h>
#include "GameScene.h"

void GameScene::draw() {
    if (Game::getInstance()->isGameOver() || Game::getInstance()->isGameWin()) return;
    for (auto &[_, gameObject]: gameObjects) {
        if (!gameObject->isShowing()) {
            continue;
        }

        glPushMatrix();
        glTranslatef(gameObject->getPosition().getX(),
                     gameObject->getPosition().getY(),
                     gameObject->getPosition().getZ());
        glRotated(gameObject->getAngle().getX(), 1, 0, 0);
        glRotated(gameObject->getAngle().getY(), 0, 1, 0);
        glRotated(gameObject->getAngle().getZ(), 0, 0, 1);
        glScaled(gameObject->getScale().getX(),
                 gameObject->getScale().getY(),
                 gameObject->getScale().getZ());
        gameObject->draw();
        glPopMatrix();

        if (Game::getInstance()->getGameSettings()->isCollisionBoxesShown()) {
            glPushMatrix();
            glTranslatef(gameObject->getStart().getX(),
                         gameObject->getStart().getY(),
                         gameObject->getStart().getZ());
            glTranslatef(
                    gameObject->getSize().getX() / 2,
                    gameObject->getSize().getY(),
                    gameObject->getSize().getZ() / 2
            );
            glScaled(gameObject->getSize().getX(),
                     gameObject->getSize().getY(),
                     gameObject->getSize().getZ());
            glutWireCube(1);
            glPopMatrix();
        }
    }
}

void GameScene::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onKeyPressed(key, mouseX, mouseY);
    }

    
}

void GameScene::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onSpecialKeyPressed(key, mouseX, mouseY);
    }
}

void GameScene::onMouse(int button, int state, int x, int y)
{
    for (auto &[_, gameObject]: gameObjects) {
		gameObject->onMouse(button, state, x, y);
	}
}

void GameScene::onIdle() {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onIdle();

        if (!gameObject->isShowing()) continue;

        for (auto &[_, otherGameObject]: gameObjects) {
            if (gameObject != otherGameObject && otherGameObject->isShowing()) {
                if (gameObject->isColliding(*otherGameObject)) {
                    gameObject->onCollision(otherGameObject);
                }
            }
        }
    }
}

void GameScene::setupLights() {
    
    if (Game::getInstance()->isGameOver() || Game::getInstance()->isGameWin()) return;


    // Light 0
    GLfloat light0Position[] = {-7.0f, 6.0f, 3.0f, 0.0f};
    GLfloat light0Ambient[] = {0.3f, 0.3f, 0.3, 1.0f};
    GLfloat light0Diffuse[] = {0.6f, 0.6f, 0.6, 1.0f};
    GLfloat light0Specular[] = {1.0f, 1.0f, 1.0, 1.0f};
    GLfloat light0Shininess[] = {50.0f};

    glLightfv(GL_LIGHT0, GL_POSITION, light0Position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light0Ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0Diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light0Specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, light0Shininess);

    glShadeModel(GL_SMOOTH);
}

void GameScene::onTimer(int value) {
    for (auto &[_, gameObject]: gameObjects) {
        gameObject->onTimer(value);
    }
}

void GameScene::init() {
    for (auto &[_, gameObject]: gameObjects) {
		gameObject->init();
	}
}

