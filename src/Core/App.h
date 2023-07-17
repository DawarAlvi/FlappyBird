#pragma once

#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"
#include "Input.h"
#include "Time.h"

class App {
public:
	bool shouldQuit = false;

	SDL_Window* window;
	SDL_Renderer* renderer;

	const char* windowTitle;
	int baseWidth, baseHeight, scale;
	int windowWidth, windowHeight;

	std::vector<Entity*> entities;
	
	App(const char * title, int width, int height, int scale = 1);

	void Run();

protected:
	virtual void Update();
	template <typename T>
	T* CreateEntity(const char*, SDL_Rect, SDL_Rect);
	void DestroyEntity(Entity* entity);

private:
	int targetFrameRate = 60;
	int frameStartTicks = 0;
	int frameEndTicks = 0;
	int frameTicks = 0;
	float targetWaitTicks = 1000.0f / targetFrameRate;
	float waitTicks = 0.0f;

	void Init();
	void HandleEvents();

	void RenderBegin();
	void Render();
	void RenderEnd();

	void LateUpdate();
};

template<typename T>
inline T* App::CreateEntity(const char* texturePath, SDL_Rect src_rect, SDL_Rect dest_rect)
{
	static_assert(std::is_base_of<Entity, T>::value, "Can only create entities of type 'Entity'.");
	T* entity = new T(renderer, texturePath, src_rect, dest_rect);
	entities.push_back(entity);
	return entity;
}
