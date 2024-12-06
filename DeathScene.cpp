#include "DeathScene.h"
#include "Player.h"
#include "Camera.h"
#include "Ground.h"
#include "Obstacle.h"
#include "Goal.h"
#include "Skybox.h"
#include "GameText.h"
#include <glut.h>
#include <Collectable.h>

DeathScene::DeathScene()
{
	gameObjects["gameText"] = (new GameText());

}

void DeathScene::onIdle()
{
	GameScene::onIdle();

	GameText* gameText = getGameObjectByTag<GameText>("gameText");


	gameText->setPosition({ -0.2, 0, 0 });
	gameText->setText("Game Over // Final Score: ");

}
