#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity {
public:
	bool enabled = true;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
	SDL_Rect src;
	SDL_Rect dest;

	Entity();
	Entity(SDL_Renderer*, const char*);
	Entity(SDL_Renderer*, const char*, SDL_Rect);
	Entity(SDL_Renderer*, const char*, SDL_Rect, SDL_Rect);
	
	void virtual Update();
	void Render();
};
