#pragma once

#include "Core/App.h"
#include <Entities/Ground.h>
#include <Entities/Pipe.h>
#include <Entities/Bird.h>

class FlappyBird : public App {
public:
	FlappyBird(const char* title, int width, int height, int scale = 1);
	void Update () override;
};