#include "Ground.h"

Ground::Ground(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect dest)
	:Entity(renderer, texturePath, src, dest) {
	startPosX = dest.x;
}

void Ground::Update() {
	dest.x -= 1;
	if (dest.x + dest.w < startPosX) dest.x = startPosX;
}
