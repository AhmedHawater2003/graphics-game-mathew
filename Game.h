#ifndef GRAPHICSASSIGNMENT2_GAME_H
#define GRAPHICSASSIGNMENT2_GAME_H

#include "GameScene.h"

class GameScene;
class GameSettings;

class Game {
    int score = 0;

    GameScene *scene{};
    GameSettings *gameSettings;
    static Game *instance;

    bool gameOver = false;

    explicit Game(GameSettings *gameSettings);

public:

    void draw();

    void setScene(GameScene *newScene);

    void onKeyPressed(unsigned char key, int mouseX, int mouseY);

    void onSpecialKeyPressed(int key, int mouseX, int mouseY);

    void onMouse(int button, int state, int x, int y);

    void init(int argc, char **argv, GameScene *initialScene);

    void onIdle();

    void onTimer(int value);

    [[nodiscard]] GameSettings *getGameSettings() const;

    static Game *getInstance(GameSettings *settings = nullptr);

    [[nodiscard]] GameScene *getScene() const;

    int getScore();

    void incrementScore();

    void setGameOver(bool gameOver);

    bool isGameOver();
};


#endif //GRAPHICSASSIGNMENT2_GAME_H
