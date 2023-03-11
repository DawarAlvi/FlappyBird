#pragma once
#include "Core/Entity.h"

class Bird : public Entity
{
public:
	Bird(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);
	void Update() override;
};

