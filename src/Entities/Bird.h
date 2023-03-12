#pragma once

#include <vector>

#include "Core/Core.h"
#include "GameState.h"

class Bird : public Entity
{
public:
	float animSpeed = 0.25f;
	float acceleration = 0.0f;
	float gravity = 31.25f;
	float jumpForce = 562.5f;
	std::vector<SDL_Rect> frames;

	Bird(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);
	
	void Update() override;

private:
	int currentFrame = 0;

	void Animate();
	void Fall();
	void Jump();
	void Collide();

};

