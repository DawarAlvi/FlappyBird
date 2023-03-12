#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
	bool enabled = true;
	double angle = 0;
	SDL_Point center = {0,0};
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect src;
	SDL_Rect rect;

	Entity();
	Entity(SDL_Renderer*, const char*);
	Entity(SDL_Renderer*, const char*, SDL_Rect);
	Entity(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);
	
	void virtual Update();
	void Render();
};
