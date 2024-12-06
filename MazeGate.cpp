#include "MazeGate.h"
#include "glut.h"

MazeGate::MazeGate(bool isFirstScene, Vector3f collisionBoxsize)
	: GameObject(collisionBoxsize),
	isFirstScene(isFirstScene)
{
}

void MazeGate::init() {
	if (isFirstScene) {
		model_gate
			.Load("Models/gate/gate.3ds");
	}
	else {
		model_gate
			.Load("Models/airdrop/AIRDROP.3DS");
	}
	model_gate.pos.x = -3;

}

void MazeGate::draw() {
	glPushMatrix();
	model_gate.Draw();
	glPopMatrix();
}

void MazeGate::onIdle() {

}
void MazeGate::onCollision(GameObject*& pObject) {
	translationalAnimation = false;

}
