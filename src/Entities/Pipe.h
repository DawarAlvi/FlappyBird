#pragma once

#include "Core/Core.h"
#include "GameState.h"

class Pipe : public Entity
{
public:
	static int lowerPipeYOffset;
	static int minYpos;
	static int maxYpos;

	int startPosX = 0;
	bool passed = false;
	bool isUpperPipe = false;
	Pipe* lowerPipe;

	Pipe(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);

	void Update() override;
	void SetAsUpperPipeOf(Pipe* otherPipe);

private:
	void SetRandomYpos();
};
