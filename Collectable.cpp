#include "Collectable.h"
#include "glut.h"

Collectable::Collectable(bool isFirstScene, Vector3f collisionBoxsize)
	: GameObject(collisionBoxsize),
	isFirstScene(isFirstScene)
{}

void Collectable::init() {
	if (isFirstScene) {
		model_collectable
			.Load("models/coin/coin.3ds");

	}
	else {
		model_collectable
			.Load("Models/diamond/diamond.3ds");
	}

}

void Collectable::draw() {
	glPushMatrix();
	if (!isFirstScene) {
		glTranslated(0, 0.5, 0); // Adjustment for airdrop model
	}

	model_collectable.Draw(); // Render the model
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
