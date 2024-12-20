#include <stdlib.h>
#include <glut.h>
#include "Game.h"


#define GLUT_KEY_ESCAPE 27

Game::Game(GameSettings *gameSettings) : gameSettings(gameSettings) {
}

void Game::draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    scene->setupLights();
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

void Game::onMouse(int button, int state, int x, int y)
{
    scene->onMouse(button, state, x, y);
	glutPostRedisplay();
}

void Game::init(int argc, char **argv, GameScene *initialScene) {
    glutInit(&argc, argv);

    glutInitWindowSize(gameSettings->getWindowWidth(), gameSettings->getWindowHeight());

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutCreateWindow("Game 6");

    setScene(initialScene);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
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

int Game::getScore()
{
    return score;
}

void Game::incrementScore() {
    if (isFirstScene)
        score += 10;
	else
		score += 20;
}

void Game::setGameOver(bool newGameOver)
{
    gameOver = newGameOver;
}

bool Game::isGameOver()
{
    return gameOver;
}


void Game::setGameWin(bool newGameWin)
{
    gameWin = newGameWin;
}

bool Game::isGameWin()
{
    return gameWin;
}


void Game::setIsFirstScene(bool newIsFirstScene)
{
    isFirstScene = newIsFirstScene;
}

bool Game::isIsFirstScene()
{
    return isFirstScene;
}



