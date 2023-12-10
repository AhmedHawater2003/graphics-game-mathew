#include "SecondScene.h"
#include "Player.h"
#include "Camera.h"
#include "Ground.h"
#include "Obstacle.h"
#include "Goal.h"
#include "Skybox.h"
#include "GameText.h"
#include <glut.h>
#include <Collectable.h>

SecondScene::SecondScene()
{

	gameObjects["player"] = (new Player())
		->setPosition({ 0, 15, -90 });

	gameObjects["ground"] = (new Ground(false));

	gameObjects["goal"] = (new Goal(false))
		->setPosition({ 0, 5, 50 });

	gameObjects["camera"] = (new Camera({ 0, 20, -105 }, { 0, 0, 0 }, { 0, 1, 0 }, 1));

	gameObjects["obstacle1"] = (new Obstacle(false))
		->setPosition({ 0, 100, -70 });
	gameObjects["obstacle2"] = (new Obstacle(false))
		->setPosition({ -5, 0, -50 });
	gameObjects["obstacle3"] = (new Obstacle(false))
		->setPosition({ 6, 0, -30 });

	gameObjects["obstacle4"] = (new Obstacle(false))
		->setPosition({ 0, 0, -5 });

	gameObjects["obstacle5"] = (new Obstacle(false))
		->setPosition({ -5, 0, 20 });

	gameObjects["obstacle6"] = (new Obstacle(false))
		->setPosition({ 7, 0, 40 });

	gameObjects["obstacle7"] = (new Obstacle(false))
		->setPosition({ -6, 0, 60 });

	gameObjects["gameText"] = (new GameText);


	gameObjects["skybox"] = (new Skybox(false));

	gameObjects["gameText"] = (new GameText);
	gameObjects["collectable1"] = (new Collectable(false, {3,2,3}))
		->setPosition({ 0,20,35 })
		->setScale({ 3,3,3 });
	gameObjects["collectable2"] = (new Collectable(false, {3,2,3}))
		->setPosition({ 15,50,105 })
		->setScale({ 3,3,3 });
	gameObjects["collectable3"] = (new Collectable(false, {3,2,3}))
		->setPosition({ -15,60,145 })
		->setScale({ 3,3,3 });
	gameObjects["collectable4"] = (new Collectable(false,{3,2,3}))
		->setPosition({ 0,80,05 })
		->setScale({ 3,3,3 });
	gameObjects["collectable5"] = (new Collectable(false, {3,2,3}))
		->setPosition({ 0,100,305 })
		->setScale({ 3,3,3 });
}

void SecondScene::onIdle()
{
	GameScene::onIdle();

	Player* player = getGameObjectByTag<Player>("player");
	Camera* camera = getGameObjectByTag<Camera>("camera");
	GameText* gameText = getGameObjectByTag<GameText>("gameText");

	if (is3rdPerson) {
		camera->setCenter(player->getPosition() + Vector3f(0, 0, 5));
		camera->setEye(player->getPosition() + Vector3f(0, 5, -10));
	}
	else {
		camera->setCenter(player->getPosition() + Vector3f(0, 5, 5));
		camera->setEye(player->getPosition() + Vector3f(0, 5, 2));
	}

	gameText->setPosition(player->getPosition() + Vector3f(50, 10, 100));

	bool gameOver = Game::getInstance()->isGameOver();
	bool gameWin = Game::getInstance()->isGameWin();

	if (gameOver) {
		gameText->setText("Game Over // Final Score: " + std::to_string(Game::getInstance()->getScore()));
	}
	else if (gameWin) {
		gameText->setText("You win!! // Final Score: " + std::to_string(Game::getInstance()->getScore()));

	}
	else {
		gameText->setText("Score: " + std::to_string(Game::getInstance()->getScore()));
	}
}



void SecondScene::onSpecialKeyPressed(int key, int x, int y)
{
	GameScene::onSpecialKeyPressed(key, x, y);
	Player* player = getGameObjectByTag<Player>("player");
}

void SecondScene::onKeyPressed(unsigned char key, int x, int y)
{
	GameScene::onKeyPressed(key, x, y);

	if (key == '1') {
		is3rdPerson = !is3rdPerson;
	}
}

void SecondScene::setupLights()
{
	double p = hourOfDay / 48;

	//glClearColor(127.0 / 255.0 * p, 207.0 / 255.0 * p, 255.0 / 255.0 * p, 0.0f);

	GLfloat light_position[] = { 0.0, 100.0, 0.0, 1.0 };
	GLfloat light_ambient[] = { p, p, p, 0 };
	GLfloat light_diffuse[] = { 127.0 / 255.0 * p, 207.0 / 255.0 * p, 255.0 / 255.0 * p, 0.0f };
	GLfloat light_specular[] = { p, p, p, 0.0f };
	GLfloat shininess[] = { 0.5 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glEnable(GL_LIGHT0);


	Player* player = getGameObjectByTag<Player>("player");

	// Spotlight
	GLfloat light_position1[] = {
		player->getPosition().getX(),
		player->getPosition().getY() + 25,
		player->getPosition().getZ(),
		1.0 };
	GLfloat light_ambient1[] = { 0.1, 0.1, 0.1, 0.0 };
	GLfloat light_diffuse1[] = { 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 0.0 }; // Increase diffuse intensity
	GLfloat light_specular1[] = { 0.2, 0.2, 0.2, 0.0 }; // Increase specular intensity

	GLfloat spot_direction[] = { 0.0, -2.0, 1 };

	// Set spotlight properties
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_SHININESS, shininess);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);

	// Enable lighting and light1
	glEnable(GL_LIGHT1);
}

void SecondScene::onTimer(int value)
{
	GameScene::onTimer(value);

	hourOfDay += timeDirection;
	if (hourOfDay == 24) {
		timeDirection = -1;
	}
	else if (hourOfDay == 0) {
		timeDirection = 1;
	}
}