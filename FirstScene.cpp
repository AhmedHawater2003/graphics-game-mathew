#include "FirstScene.h"
#include "Player.h"
#include "Camera.h"
#include "Ground.h"
#include "Obstacle.h"
#include "Collectable.h"
#include "Goal.h"
#include "Skybox.h"
#include "GameText.h"
#include "Maze.h"
#include <glut.h>
#include <Collectable.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

FirstScene::FirstScene()
{
	gameObjects["player"] = (new Player())
		->setPosition({ 0, 0, 0 })->setScale(Vector3f(0.5, 0.5, 0.5));

	gameObjects["ground"] = (new Ground(true));

	gameObjects["goal"] = (new Goal(true))
		->setPosition({ 0, 0, 100 });

	gameObjects["maze"] = (new Maze(true))
		->setPosition({ -20, -3, 20 });

	gameObjects["camera"] = (new Camera({ 0, 20, -105 }, { 0, 0, 0 }, { 0, 1, 0 }, 1280.0f/720));


	gameObjects["skybox"] = (new Skybox(true));

	gameObjects["gameText"] = (new GameText);
	//gameObjects["collectable1"] = (new Collectable(true, { 22,30,10 }))
	//	->setPosition({ 0,0,5 });
	//	->setScale({0.5,0.5,0.5});
	//gameObjects["collectable2"] = (new Collectable(true, {22,30,10}))
	//	->setPosition({ 15,15,-50 })
	//	->setScale({ 0.5,0.5,0.5 });
	//gameObjects["collectable3"] = (new Collectable(true, {22 ,30 ,10}))
	//	->setPosition({15,18,-10 })
	//	->setScale({ 0.5,0.5,0.5 });
	//gameObjects["collectable4"] = (new Collectable(true, {22,30,10}))
	//	->setPosition({ 5,18,20 })
	//	->setScale({ 0.5,0.5,0.5 });
	//gameObjects["collectable5"] = (new Collectable(true, {22,30,10}))
	//	->setPosition({ -5,20,50 })
	//	->setScale({ 0.5,0.5,0.5 });


	//gameObjects["obstacle1"] = (new Obstacle(true))
	//	->setPosition({ 0, 100, -70 });
	//gameObjects["obstacle2"] = (new Obstacle(true))
	//	->setPosition({ -5, 0, -50 });
	//gameObjects["obstacle3"] = (new Obstacle(true))
	//	->setPosition({ 6, 0, -30 });

	//gameObjects["obstacle4"] = (new Obstacle(true))
	//	->setPosition({ 0, 0, -5 });

	//gameObjects["obstacle5"] = (new Obstacle(true))
	//	->setPosition({ -5, 0, 20 });

	//gameObjects["obstacle6"] = (new Obstacle(true))
	//	->setPosition({ 7, 0, 40 });
	//
	//gameObjects["obstacle7"] = (new Obstacle(true))
	//	->setPosition({ -6, 0, 60 });
	
	
}

void FirstScene::onIdle()
{
	GameScene::onIdle();

	Player *player = getGameObjectByTag<Player>("player");
	Camera* camera = getGameObjectByTag<Camera>("camera");
	GameText* gameText = getGameObjectByTag<GameText>("gameText");


	float angle = player->getAngle().getY();
	float playerX = player->getPosition().getX();
	float playerY = player->getPosition().getY();
	float playerZ = player->getPosition().getZ();
	float thirdPersonDistance = 2.0f;
	float thirdPersonHeight = 2.0f;
	float lookX, lookY, lookZ;



	if (!isTopView) {
		if (is3rdPerson) {

			float camX = playerX - thirdPersonDistance * sin(angle * M_PI / 180.0f);
			float camY = playerY + thirdPersonHeight;
			float camZ = playerZ + thirdPersonDistance * cos(angle * M_PI / 180.0f);
			lookX = playerX + sin(angle * M_PI / 180.0f);
			lookY = playerY + 0.5f;
			lookZ = playerZ- cos(angle * M_PI / 180.0f);

			camera->setCenter(Vector3f(lookX, lookY, lookZ));
			camera->setEye(Vector3f(camX, camY - 0.5, camZ));
			camera->setUp(Vector3f(0, 1, 0));
		}
		else {
			lookX = playerX + sin(angle * M_PI / 180.0f);
			lookY = playerY + 1.0f;
			lookZ = playerZ - cos(angle * M_PI / 180.0f);

			camera->setEye(Vector3f(playerX, playerY + 1.0f, playerZ));
			camera->setCenter(Vector3f(lookX, lookY, lookZ));
			camera->setUp(Vector3f(0, 1, 0));
		}
	}
	else {
		camera->setEye(Vector3f(0, 50, 0));
		//camera->setEye(player->getPosition() + Vector3f(0, 10, 0));
		camera->setUp(Vector3f(0, 0, 1));
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



void FirstScene::onSpecialKeyPressed(int key, int x, int y)
{
	GameScene::onSpecialKeyPressed(key, x, y);
}

void FirstScene::onKeyPressed(unsigned char key, int x, int y)
{
	GameScene::onKeyPressed(key, x, y);

	if (key == '1') {
		is3rdPerson = !is3rdPerson;
		isTopView = false;
	}
	if (key == '2') {
		isTopView = !isTopView;
	}

}

void FirstScene::setupLights()
{

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//double p = hourOfDay / 48;
	//
	////glClearColor(127.0 / 255.0 * p, 207.0 / 255.0 * p, 255.0 / 255.0 * p, 0.0f);

	//GLfloat light_position[] = { 0.0, 100.0, 0.0, 1.0 };
	//GLfloat light_ambient[] = { p, p, p, 0 };
	//GLfloat light_diffuse[] = { 127.0 / 255.0 * p, 207.0 / 255.0 * p, 255.0 / 255.0 * p, 0.0f };
	//GLfloat light_specular[] = { p, p, p, 0.0f };
	//GLfloat shininess[] = { 0.5 };

	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	//glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
	//glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	//glEnable(GL_LIGHT0);


	//Player* player = getGameObjectByTag<Player>("player");

	//// Spotlight
	//GLfloat light_position1[] = {
	//	player->getPosition().getX(),
	//	player->getPosition().getY() + 25,
	//	player->getPosition().getZ(),
	//	1.0 };
	//GLfloat light_ambient1[] = { 0.1, 0.1, 0.1, 0.0 };
	//GLfloat light_diffuse1[] = { 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 0.0 }; // Increase diffuse intensity
	//GLfloat light_specular1[] = { 0.2, 0.2, 0.2, 0.0 }; // Increase specular intensity

	//GLfloat spot_direction[] = { 0.0, -2.0, 1 };

	//// Set spotlight properties
	//glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	//glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	//glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	//glLightfv(GL_LIGHT1, GL_SHININESS, shininess);

	//glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	//glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);

	//// Enable lighting and light1
	//glEnable(GL_LIGHT1);
}

void FirstScene::onTimer(int value)
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



