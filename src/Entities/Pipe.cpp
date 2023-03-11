#include "Pipe.h"
Pipe::Pipe(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect dest)
	:Entity(renderer, texturePath, src, dest) {
	startPosX = dest.x;
}

void Pipe::Update()
{
}
