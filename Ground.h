#pragma once
#include "GameObject.h"
#include "GLTexture.h"

class Ground : public GameObject
{
	bool isFirstScene;
	GLTexture texture;
public:
	Ground(bool isFirstScene);

	void init();
	void draw();
};

