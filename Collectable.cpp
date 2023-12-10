#include "Collectable.h"
#include "glut.h"

Collectable::Collectable(bool isFirstScene , Vector3f collisionBoxsize) 
	: GameObject(collisionBoxsize), 
	isFirstScene(isFirstScene)
{
}

void Collectable::init() {
	if (isFirstScene) {
		model_collectable
			.Load("Models/parachute/Hot Air Balloon Iridesium/Air_Balloon.3DS");
	}
	else {
		model_collectable
			.Load("Models/airdrop/AIRDROP.3DS");
	}

}

void Collectable::draw() {
	glPushMatrix();
	if (!isFirstScene) {
		glTranslated(0, 1, 0);
	}
	model_collectable.Draw();
	glPopMatrix();
}

void Collectable::onIdle() {
	if (translationalAnimation) {
		moveBy({ 0,-0.05,0 });
	}
	rotateBy({ 0,2,0 });
	
}
void Collectable::onCollision(GameObject*& pObject) {
	translationalAnimation = false;

}
