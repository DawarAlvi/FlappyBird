#include "Pipe.h"
Pipe::Pipe(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect)
	:Entity(renderer, texturePath, src, rect) {
}

void Pipe::Update()
{
	rect.x -= 2;
	if (rect.x + rect.w < 0) rect.x = startPosX;

}
