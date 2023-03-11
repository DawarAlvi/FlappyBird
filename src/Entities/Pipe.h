#pragma once
#include "Core/Entity.h"
class Pipe : public Entity
{
	int startPosX = 0;

	Pipe(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);

	void Update() override;
};

