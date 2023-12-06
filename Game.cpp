#include <stdlib.h>
#include <glut.h>
#include "Game.h"

#define GLUT_KEY_ESCAPE 27

Game::Game(GameSettings *gameSettings) : gameSettings(gameSettings) {
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //scene->setupLights();
    scene->draw();
    glutSwapBuffers();
}

void Game::onKeyPressed(unsigned char key, int mouseX, int mouseY) {
    scene->onKeyPressed(tolower(key), mouseX, mouseY);

    if (key == GLUT_KEY_ESCAPE) {
        exit(EXIT_SUCCESS);
    }

    glutPostRedisplay();
}

void Game::onSpecialKeyPressed(int key, int mouseX, int mouseY) {
    scene->onSpecialKeyPressed(key, mouseX, mouseY);
    glutPostRedisplay();
}

void Game::init(int argc, char **argv, GameScene *initialScene) {
    glutInit(&argc, argv);

    glutInitWindowSize(gameSettings->getWindowWidth(), gameSettings->getWindowHeight());

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("Game 6");

    glClearColor(127.0 / 255.0, 207.0 / 255.0, 255.0 / 255.0, 0.0f);
    setScene(initialScene);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
}

void Game::onIdle() {
    scene->onIdle();
    glutPostRedisplay();
}

void Game::onTimer(int value) {
    scene->onTimer(value);
}

GameSettings *Game::getGameSettings() const {
    return gameSettings;
}

void Game::setScene(GameScene *newScene) {
    scene = newScene;
    scene->init();
}

Game *Game::instance;

Game *Game::getInstance(GameSettings *settings) {
    if (instance == nullptr) {
        instance = new Game(settings);
    }

    return instance;
}

GameScene *Game::getScene() const {
    return scene;
}




