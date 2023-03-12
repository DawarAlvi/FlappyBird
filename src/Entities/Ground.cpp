#include "Ground.h"

Ground::Ground(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect)
	:Entity(renderer, texturePath, src, rect) {
	startPosX = rect.x;
}

void Ground::Update() {
	rect.x -= GameState::scrollSpeed;
	if (rect.x + rect.w < startPosX) rect.x = startPosX;
}
