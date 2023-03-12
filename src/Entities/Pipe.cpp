#include "Pipe.h"

int Pipe::lowerPipeYOffset = 570;
int Pipe::minYpos = -310;
int Pipe::maxYpos = -20;

Pipe::Pipe(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect)
	:Entity(renderer, texturePath, src, rect), lowerPipe(nullptr) {
}

void Pipe::Update()
{
	rect.x -= GameState::scrollSpeed;;
	if (rect.x + rect.w < 0) {
		rect.x = startPosX;
		SetRandomYpos();
		passed = false;
	}
}

void Pipe::SetAsUpperPipeOf(Pipe* otherPipe)
{
	isUpperPipe = true;
	lowerPipe = otherPipe;
	SetRandomYpos();
}

void Pipe::SetRandomYpos() {
	if (isUpperPipe && lowerPipe != nullptr) {
		rect.y = -rand() % (maxYpos - minYpos);
		lowerPipe->rect.y = rect.y + lowerPipeYOffset;
	}
}