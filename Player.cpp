#include "Player.h"
#include <stdlib.h>
#include "glut.h"

Player::Player()
	: GameObject({ 1, 1, 1 })
{
}

void Player::init()
{
	model_player.Load("Models/house/house.3DS");
}

void Player::draw()
{
	model_player.Draw();
}
