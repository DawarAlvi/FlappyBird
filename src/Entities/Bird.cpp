#include "Bird.h"

Bird::Bird(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect)
	:Entity(renderer, texturePath, src, rect) {
	center = { rect.w / 2, rect.h / 2 };
	frames.push_back({ 264, 90, 17, 12 });
	frames.push_back({ 264, 64, 17, 12 });
	frames.push_back({ 264, 90, 17, 12 });
	frames.push_back({ 223, 124, 17, 12 });
}

void Bird::Update() {
	src = frames[currentFrame];
	
	if (Time::frames % (int)(1/animSpeed) == 0)
		currentFrame = (currentFrame + 1) % frames.size();

	rect.y += (int)acceleration;
	if (Input::KeyJustPressed(SDLK_SPACE)) {
		acceleration = -jumpForce * Time::dt;
	}
	else {
		acceleration += gravity * Time::dt;
	}

	float x = acceleration;
	float a = -jumpForce * Time::dt;
	float b = 20;
	float c = -25;
	float d = 90;

	angle = (x - a) * ((d - c) / (b - a)) + c;
	if (angle < c) angle = c;
	if (angle > d) angle = d;
	
	if (rect.y < 0) {
		rect.y = 0;
		acceleration = 0;
	}
	else if (rect.y + rect.h > GameState::groundLevel) {
		rect.y = GameState::groundLevel - rect.h;
	}
}