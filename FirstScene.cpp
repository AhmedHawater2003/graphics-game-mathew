#include "FirstScene.h"
#include "Player.h"
#include "Camera.h"
#include <iostream>

FirstScene::FirstScene()
{
	gameObjects["player"] = (new Player());

	gameObjects["camera"] = (new Camera({ 20, 20, 20 }, { 0, 0, 0 }, { 0, 1, 0 }, 1));
}

void FirstScene::onIdle()
{
}


