#pragma once

#include "Core/Core.h"
#include "GameState.h"

class Ground : public Entity {
public:
	int startPosX = 0;

	Ground(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);

	void Update() override;
};

