#include "FirstScene.h"
#include "Player.h"
#include "Camera.h"
#include "Obstacle.h"
#include "Torch.h"
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

FirstScene::FirstScene()
{
	gameObjects["player"] = (new Player())
		->setPosition({ 0, -2, 0 })->setScale(Vector3f(0.5, 0.5, 0.5));


	gameObjects["goal"] = (new Goal(true))
		->setPosition({ 10.5, -2, 11.5 })->setScale({ 0.3, 0.3, 0.3 });

	gameObjects["maze"] = (new Maze(true))
		->setPosition({ -20, -3, 20 });


	gameObjects["gate"] = (new MazeGate(true, { 3,4,0.1 }))
		->setPosition({ -0.4, -2.2, 19.4 })->setScale({2.2, 2, 2});

	gameObjects["camera"] = (new Camera({ 0, 20, -105 }, { 0, 0, 0 }, { 0, 1, 0 }, 1280.0f/720));


	gameObjects["skybox"] = (new Skybox(true));

	gameObjects["gameText"] = (new GameText);


	// ----------------- MAZE WALLS ----------------------

	gameObjects["wall1"] = (new MazeWall(true, 19.2, 4, 0.5))
		->setPosition({ 0, 0, 9.8 }); // BOTTOM
	gameObjects["wall2"] = (new MazeWall(true, 19.2, 4, 0.5))
		->setPosition({ 0, 0, -9.2}); // TOP
	gameObjects["wall3"] = (new MazeWall(true, 0.5, 4, 19.2))
			->setPosition({ -9.8, 0, 0 }); // LEFT
	gameObjects["wall4"] = (new MazeWall(true, 0.5, 4, 7))
		->setPosition({ 9.2, 0, 6.8 }); // RIGHT
	gameObjects["wall5"] = (new MazeWall(true, 0.5, 4, 7.5))
		->setPosition({ 9.2, 0, -5 }); // RIGHT


	gameObjects["wall111"] = (new MazeWall(true, 3, 5, 1.5))
		->setPosition({ 10.5, 0, 7.5 }); // SPECIAL

	////// -----------------------------------------------


	gameObjects["wall6"] = (new MazeWall(true, 11, 4, 0.5))
		->setPosition({ -7, 0, 13.1 }); // BOTTOM
	gameObjects["wall7"] = (new MazeWall(true, 9, 4, 0.5))
		->setPosition({ 7.5, 0, 13.1 }); // BOTTOM
	gameObjects["wall8"] = (new MazeWall(true, 25, 4, 0.5))
		->setPosition({ 0, 0, -12.5 }); // TOP
	gameObjects["wall9"] = (new MazeWall(true, 0.5, 4, 25))
		->setPosition({ -13.1, 0, 0 }); // LEFT
	gameObjects["wall10"] = (new MazeWall(true, 0.5, 4, 25))
		->setPosition({ 12.5, 0, 0 }); // RIGHT

	gameObjects["wall222"] = (new MazeWall(true, 0.4, 4, 3))
		->setPosition({ -7.2, 0, -14 }); // SPECIAL

	// -----------------------------------------------

	gameObjects["wall11"] = (new MazeWall(true, 32, 4, 0.5))
		->setPosition({ 0, 0, 16.4 }); // BOTTOM
	gameObjects["wall12"] = (new MazeWall(true, 32, 4, 0.5))
		->setPosition({ 0, 0, -15.8 }); // TOP
	gameObjects["wall13"] = (new MazeWall(true, 0.5, 4, 32))
		->setPosition({ 15.8, 0, 0 }); // RIGHT
	gameObjects["wall14"] = (new MazeWall(true, 0.5, 4, 11))
		->setPosition({ -16.4, 0, 11 }); // LEFT
	gameObjects["wall15"] = (new MazeWall(true, 0.5, 4, 17))
		->setPosition({ -16.4, 0, -7 }); // LEFT


	gameObjects["wall333"] = (new MazeWall(true, 3, 4, 1.5))
		->setPosition({ 17, 0, 11 }); // SPECIAL

	// -----------------------------------------------

	gameObjects["wall16"] = (new MazeWall(true, 17, 4, 0.5))
		->setPosition({ -12, 0, 19.6 }); // BOTTOM
	gameObjects["wall17"] = (new MazeWall(true, 17, 4, 0.5))
		->setPosition({ 10, 0, 19.6 }); // BOTTOM
	gameObjects["wall18"] = (new MazeWall(true, 40, 4, 0.5))
		->setPosition({ 0, 0, -19 }); // TOP
	gameObjects["wall19"] = (new MazeWall(true, 0.5, 4, 40))
		->setPosition({ -19.6, 0, 0 }); // LEFT
	gameObjects["wall20"] = (new MazeWall(true, 0.5, 4, 40))
		->setPosition({ 19, 0, 0 }); // RIGHT

	// -----------------------------------------------

	gameObjects["collectable2"] = (new Collectable(true, { 5,5,5 }))
		->setPosition({ 8, -2, -1 })
		->setScale({ 0.5,0.5,0.5 });

	gameObjects["collectable_wall3"] = (new Collectable(true, { 5, 5, 5 }))
		->setPosition({ -8.8, -2, 0 }) 
		->setScale({ 0.5, 0.5, 0.5 });

	gameObjects["collectable_wall4"] = (new Collectable(true, { 5, 5, 5 }))
		->setPosition({ 8.8, -2, 6.8 }) 
		->setScale({ 0.5, 0.5, 0.5 });

	gameObjects["collectable_wall5"] = (new Collectable(true, { 5, 5, 5 }))
		->setPosition({ 8.8, -2, -5.0 })  
		->setScale({ 0.5, 0.5, 0.5 });

	gameObjects["collectable_wall6"] = (new Collectable(true, { 5, 5, 5 }))
		->setPosition({ -7, -2, 12.0 })  
		->setScale({ 0.5, 0.5, 0.5 });

	gameObjects["collectable_wall7"] = (new Collectable(true, { 5, 5, 5 }))
		->setPosition({ 7.5, -2, 12.0 }) 
		->setScale({ 0.5, 0.5, 0.5 });

	gameObjects["collectable_wall8"] = (new Collectable(true, { 5, 5, 5 }))
		->setPosition({ 0, -2, -10.5 })  
		->setScale({ 0.5, 0.5, 0.5 });

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

	//-----------------Torches-----------------------

	gameObjects["torch1"] = (new Torch(true))
		->setPosition({12.11, -1, 1 })
		->setAngle({0,-90,0});

	gameObjects["torch2"] = (new Torch(true))
		->setPosition({ -12.7, -1, 1 })
		->setAngle({ 0,90,0 });

	gameObjects["torch3"] = (new Torch(true))
		->setPosition({ 15.4, -1, 1 })
		->setAngle({ 0,-90,0 });
	
	gameObjects["torch4"] = (new Torch(true))
		->setPosition({ -5, -1, 15.9 })
		->setAngle({ 0,180,0 });

	gameObjects["torch5"] = (new Torch(true))
		->setPosition({ -12, -1, -15.4 });

	gameObjects["torch6"] = (new Torch(true))
		->setPosition({ -7, -1, -18.8 });

	gameObjects["torch7"] = (new Torch(true))
		->setPosition({ -19.3, -1, 1 })
		->setAngle({ 0,90,0 });
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
		camera->setUp(Vector3f(0, 0, -1));
	}

	gameText->setPosition(Vector3f(-0.9f, 0.9f, -1.0f)); // Adjust these values as needed for screen placement


	gameText->setText("Score: " + std::to_string(Game::getInstance()->getScore()) + "        Health: " + std::to_string(player->health));
	

	// Update warning lights for obstacles
	float deltaTime = 1.0f / 60.0f; // Assuming 60 FPS, adjust if needed
	for (const auto& pair : gameObjects) {
		Obstacle* obstacle = dynamic_cast<Obstacle*>(pair.second);
		if (obstacle) {
			obstacle->updateWarningLight(deltaTime);
		}
	}

	// Position the score above the player
	Vector3f playerPosition = player->getPosition();

	if (!is3rdPerson) {
		float A = playerX + sin(angle * M_PI / 180.0f);
		float B = playerY + 1.0f;
		float C = playerZ - cos(angle * M_PI / 180.0f);
		gameText->setPosition(Vector3f(A+0.1,B,C+0.1));
	}
	else {
		gameText->setPosition(Vector3f(playerPosition.getX(), playerPosition.getY() + 1.5f, playerPosition.getZ())); 
	}
}



void FirstScene::onSpecialKeyPressed(int key, int x, int y)
{
	GameScene::onSpecialKeyPressed(key, x, y);
}

void FirstScene::onMouse(int button, int state, int x, int y)
{
	GameScene::onMouse(button, state, x, y);

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		is3rdPerson = !is3rdPerson;
		isTopView = false;
	}
}

void FirstScene::onKeyPressed(unsigned char key, int x, int y)
{
	GameScene::onKeyPressed(key, x, y);
	if (key == '2') {
		isTopView = !isTopView;
	}

}

void FirstScene::setupLights()
{



	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//GLfloat ambient[] = { 0.1f, 0.1f, 0.1, 1.0f };
	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	//GLfloat diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	//GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	//GLfloat light_position[] = { 0.0f, 10.0f, 0.0f, 1.0f };
	//glLightfv(GL_LIGHT0, GL_POSITION, light_position);



	double p = hourOfDay / 48;
	
	glClearColor(127.0 / 255.0 * p, 207.0 / 255.0 * p, 255.0 / 255.0 * p, 0.0f);

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

	//// Spotlight
	GLfloat light_position1[] = {
		player->getPosition().getX(),
		player->getPosition().getY() + 25,
		player->getPosition().getZ(),
		1.0 };
	GLfloat light_ambient1[] = { 0.1, 0.1, 0.1, 0.0 };
	GLfloat light_diffuse1[] = { 255.0 / 255.0, 255.0 / 255.0, 255.0 / 255.0, 0.0 }; // Increase diffuse intensity
	GLfloat light_specular1[] = { 0.2, 0.2, 0.2, 0.0 }; // Increase specular intensity

	GLfloat spot_direction[] = { 0.0, -2.0, 1 };

	//// Set spotlight properties
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular1);
	glLightfv(GL_LIGHT1, GL_SHININESS, shininess);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);

	//// Enable lighting and light1
	glEnable(GL_LIGHT1);
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



