#pragma once
#include <map>
#include <SDL2/SDL.h>
struct Input
{
	static std::map<SDL_Keycode, bool> keys;
	static std::map<SDL_Keycode, bool> prevKeys;

	static bool KeyPressed(SDL_Keycode);
	static bool KeyJustPressed(SDL_Keycode);
};