#pragma once

#include "Core/App.h"
#include <Entities/Ground.h>


class FlappyBird : public App {
public:
	FlappyBird(const char* title, int width, int height, int scale = 1);
};