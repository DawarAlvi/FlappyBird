#include "Bird.h"

Bird::Bird(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect)
	:Entity(renderer, texturePath, src, rect) {
}

void Bird::Update() {
}