#include "FirstScene.h"
#include "Player.h"
#include "Camera.h"
#include "Ground.h"
#include "Obstacle.h"
#include <glut.h>

const int zMin = -100, zMax = 100;
const int xMin = -10, xMax = 10;
const int yPosition = 0; 

FirstScene::FirstScene()
{
	gameObjects["player"] = (new Player())
		->setPosition({ 0, 15, -90 });

	gameObjects["ground"] = (new Ground());

	gameObjects["camera"] = (new Camera({ 0, 20, -105 }, { 0, 0, 0 }, { 0, 1, 0 }, 1));


    for (int i = 0; i < 7; i++) {

        float xPosition = xMin + (xMax - xMin) / 6 * i;
        float zPosition = zMin + (zMax - zMin) / 6 * i;

        gameObjects["obstacle" + std::to_string(i)] = (new Obstacle())
            ->setPosition({
                xPosition, 
                yPosition,
                zPosition 
            });
    }


	
}

void FirstScene::onIdle()
{
	GameScene::onIdle();

	Player *player = getGameObjectByTag<Player>("player");
	Camera *camera = getGameObjectByTag<Camera>("camera");

	if (is3rdPerson) {
		camera->setCenter(player->getPosition());
		camera->setEye(player->getPosition() + Vector3f(0, 10, -1));
	}
	else {
		camera->setCenter(player->getPosition() + Vector3f(0, 0, 5));
		camera->setEye(player->getPosition());
	}
}



void FirstScene::onSpecialKeyPressed(int key, int x, int y)
{
	GameScene::onSpecialKeyPressed(key, x, y);
	Player *player = getGameObjectByTag<Player>("player");
}

void FirstScene::onKeyPressed(unsigned char key, int x, int y)
{
	GameScene::onKeyPressed(key, x, y);

	if (key == '1') {
		is3rdPerson = !is3rdPerson;
	}
}

