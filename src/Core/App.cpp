#include "App.h"

App::App(const char * title, int width, int height, int scale)
	: windowTitle(title), baseWidth(width), baseHeight(height), scale(scale) {

	windowWidth = baseWidth * scale;
	windowHeight = baseHeight * scale;

	Init();
}

void App::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Failed to initialize SDL!");
		exit(1);
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	window = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, NULL);
	if (!window) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Failed to create SDL window!");
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		SDL_LogError(SDL_LOG_PRIORITY_ERROR, "Failed to create SDL renderer!");
		exit(1);
	}

	SDL_Surface* icon = IMG_Load("data/sprites/icon.png");
	SDL_SetWindowIcon(window, icon);
}

void App::Run() {
	while (!shouldQuit) {
		HandleEvents();
		Update();
		
		RenderBegin();
		Render();
		RenderEnd();

		LateUpdate();

		//TODO: calculate frame time
		SDL_Delay(16);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void App::HandleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: {
			shouldQuit = true;
		} break;
		case SDL_KEYDOWN: {
			Input::keys[event.key.keysym.sym] = true;
		} break;
		case SDL_KEYUP: {
			Input::keys[event.key.keysym.sym] = false;
		} break;
		}
	}
}

void App::DestroyEntity(Entity* entity) {
	entities.erase(std::remove(entities.begin(), entities.end(), entity), entities.end());
	delete entity;
}

void App::Update() {
	for (Entity* entity : entities) {
		if (entity->enabled) {
			entity->Update();
		}
	}
}

void App::RenderBegin() {
	SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255);
	SDL_RenderClear(renderer);
}

void App::Render() {
	for (Entity* entity : entities) {
		if (entity->enabled) {
			entity->Render();
		}
	}
}

void App::RenderEnd() {
	SDL_RenderPresent(renderer);
}

void App::LateUpdate() {
	Input::prevKeys = Input::keys;
}
