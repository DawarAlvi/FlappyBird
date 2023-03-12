#pragma once

#include "Core/Core.h"
#include "Core/PreferDiscreteGPU.h"

#include <Entities/Ground.h>
#include <Entities/Pipe.h>
#include <Entities/Bird.h>
#include <Entities/TapMessage.h>

class FlappyBird : public App {
public:
	FlappyBird(const char* title, int width, int height, int scale = 1);
	void Update () override;

private:
	Entity* background;
	
	Pipe* lowerPipe1;
	Pipe* lowerPipe2;
	Pipe* upperPipe1;
	Pipe* upperPipe2;
	
	Bird* bird;
	
	Ground* ground1;
	Ground* ground2;

	TapMessage* tapMessage;
};