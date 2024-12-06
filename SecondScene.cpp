#include "SecondScene.h"
#include "Player.h"
#include "Camera.h"
#include "Obstacle.h"
#include "Collectable.h"
#include "Goal.h"
#include "Skybox.h"
#include "GameText.h"
#include "Maze.h"
#include <glut.h>
#include <Collectable.h>
#include "MazeWall.h"
#include "MazeGate.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

SecondScene::SecondScene()
{
	gameObjects["player"] = (new Player())
		->setPosition({ -0.4, -2.2, 19.4 })->setScale(Vector3f(0.5, 0.5, 0.5));


	gameObjects["goal"] = (new Goal(true))
		->setPosition({ 0, -2, 0 })->setScale({ 0.2, 0.2, 0.2 });

	gameObjects["maze"] = (new Maze(false))
		->setPosition({ -20, -3, 20 });


	gameObjects["camera"] = (new Camera({ 0, 20, -105 }, { 0, 0, 0 }, { 0, 1, 0 }, 1280.0f / 720));


	gameObjects["skybox"] = (new Skybox(true));

	gameObjects["gameText"] = (new GameText);


	// ----------------- MAZE WALLS ----------------------


	gameObjects["wall1"] = (new MazeWall(true, 19.2, 10, 0.8))
		->setPosition({ 0, 0, 9.8 }); // BOTTOM
	gameObjects["wall2"] = (new MazeWall(true, 19.2, 10, 0.8))
		->setPosition({ 0, 0, -9.2 }); // TOP
	gameObjects["wall3"] = (new MazeWall(true, 0.8, 10, 19.2))
		->setPosition({ -9.8, 0, 0 }); // LEFT
	gameObjects["wall4"] = (new MazeWall(true, 0.8, 10, 7))
		->setPosition({ 9.2, 0, 6.8 }); // RIGHT
	gameObjects["wall5"] = (new MazeWall(true, 0.8, 10, 7.5))
		->setPosition({ 9.2, 0, -5 }); // RIGHT


	gameObjects["wall111"] = (new MazeWall(true, 3, 10, 1.5))
		->setPosition({ 10.5, 0, 7.5 }); // SPECIAL

	////// -----------------------------------------------


	gameObjects["wall6"] = (new MazeWall(true, 11, 10, 0.8))
		->setPosition({ -7, 0, 13.1 }); // BOTTOM
	gameObjects["wall7"] = (new MazeWall(true, 9, 10, 0.8))
		->setPosition({ 7.5, 0, 13.1 }); // BOTTOM
	gameObjects["wall8"] = (new MazeWall(true, 25, 10, 0.8))
		->setPosition({ 0, 0, -12.5 }); // TOP
	gameObjects["wall9"] = (new MazeWall(true, 0.8, 10, 25))
		->setPosition({ -13.1, 0, 0 }); // LEFT
	gameObjects["wall10"] = (new MazeWall(true, 0.8, 10, 25))
		->setPosition({ 12.5, 0, 0 }); // RIGHT

	gameObjects["wall222"] = (new MazeWall(true, -1.5, 10, 3))
		->setPosition({ -7, 0, -14 }); // SPECIAL

	//// -----------------------------------------------

	gameObjects["wall11"] = (new MazeWall(true, 32, 10, 0.8))
		->setPosition({ 0, 0, 16.4 }); // BOTTOM
	gameObjects["wall12"] = (new MazeWall(true, 32, 10, 0.8))
		->setPosition({ 0, 0, -15.8 }); // TOP
	gameObjects["wall13"] = (new MazeWall(true, 0.8, 10, 32))
		->setPosition({ 15.8, 0, 0 }); // RIGHT
	gameObjects["wall14"] = (new MazeWall(true, 0.8, 10, 11))
		->setPosition({ -16.4, 0, 11 }); // LEFT
	gameObjects["wall15"] = (new MazeWall(true, 0.8, 10, 17))
		->setPosition({ -16.4, 0, -7 }); // LEFT


	gameObjects["wall333"] = (new MazeWall(true, 3, 10, 1.5))
		->setPosition({ 17, 0, 11 }); // SPECIAL

	//// -----------------------------------------------

	gameObjects["wall16"] = (new MazeWall(true, 17, 10, 0.8))
		->setPosition({ -12, 0, 19.4 }); // BOTTOM
	gameObjects["wall17"] = (new MazeWall(true, 17, 10, 0.8))
		->setPosition({ 10, 0, 19.4 }); // BOTTOM
	gameObjects["wall18"] = (new MazeWall(true, 40, 10, 0.8))
		->setPosition({ 0, 0, -19 }); // TOP
	gameObjects["wall19"] = (new MazeWall(true, 0.8, 10, 40))
		->setPosition({ -19.6, 0, 0 }); // LEFT
	gameObjects["wall20"] = (new MazeWall(true, 0.8, 10, 40))
		->setPosition({ 19, 0, 0 }); // RIGHT

	//// -----------------------------------------------




	// -----------------------------------------------
	//
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


	gameObjects["obstacle1"] = (new Obstacle(true))
		->setPosition({ 0, -2, -11.1 });
	gameObjects["obstacle2"] = (new Obstacle(true))
		->setPosition({ 0, -2, -14.1 });
	gameObjects["obstacle3"] = (new Obstacle(true))
		->setPosition({ 0, -2, -17.4 });

	gameObjects["obstacle4"] = (new Obstacle(true))
		->setPosition({ -15.0, -2, 10 });

	gameObjects["obstacle5"] = (new Obstacle(true))
		->setPosition({ 17.0, -2, 0 });

	gameObjects["obstacle6"] = (new Obstacle(true))
		->setPosition({ -11, -2, 18 });



}

void SecondScene::onIdle()
{
	GameScene::onIdle();

	Player* player = getGameObjectByTag<Player>("player");
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
			lookZ = playerZ - cos(angle * M_PI / 180.0f);

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
		camera->setUp(Vector3f(0, 0, -1));
	}

	gameText->setPosition(player->getPosition() + Vector3f(50, 10, 100));

	bool gameOver = Game::getInstance()->isGameOver();
	bool gameWin = Game::getInstance()->isGameWin();

	if (gameOver) {
		Game::getInstance()->setScene(new DeathScene);
	}
	else if (gameWin) {
		Game::getInstance()->setScene(new DeathScene);

	}
	else {
		gameText->setText("Score: " + std::to_string(Game::getInstance()->getScore()));
	}
}



void SecondScene::onSpecialKeyPressed(int key, int x, int y)
{
	GameScene::onSpecialKeyPressed(key, x, y);
}

void SecondScene::onKeyPressed(unsigned char key, int x, int y)
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

void SecondScene::setupLights()
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
