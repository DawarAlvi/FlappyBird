#pragma once

#include "Core/Core.h"
#include "GameState.h"

class TapMessage : public Entity
{
public:
	TapMessage(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect);
	void Update() override;
};

