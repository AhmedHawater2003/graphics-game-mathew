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
	gameObjects["camera"] = (new Camera({ 0, 20, -105 }, { 0, 0, 0 }, { 0, 1, 0 }, 1280.0f / 720));

}

void DeathScene::onIdle()
{
	GameScene::onIdle();

	GameText* gameText = getGameObjectByTag<GameText>("gameText");


	gameText->setPosition({ 30, 0, 0 });
	gameText->setText("YOU DID IT, ADVENTURER!");

}