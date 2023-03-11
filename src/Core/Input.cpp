#include "Input.h"

std::map<SDL_Keycode, bool> Input::keys;
std::map<SDL_Keycode, bool> Input::prevKeys;

bool Input::KeyPressed(SDL_Keycode key)
{
	return keys[key];
}
bool Input::KeyJustPressed(SDL_Keycode key)
{
	return keys[key] && !prevKeys[key];
}
