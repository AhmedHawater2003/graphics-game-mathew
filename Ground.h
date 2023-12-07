#pragma once
#include "GameObject.h"
#include "GLTexture.h"

class Ground : public GameObject
{
	GLTexture texture;
public:
	Ground();

	void init();
	void draw();
};

