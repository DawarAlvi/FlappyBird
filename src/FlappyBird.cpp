#include "FlappyBird.h"
#include <iostream>

int main(int argc, char* argv[]) {
	FlappyBird app("Flappy Bird", 143, 256, 3);
	app.Run();
	return 0;
}

FlappyBird::FlappyBird(const char* title, int width, int height, int scale)
	: App(title, width, height, scale) {

	GameState::groundLevel = windowHeight - (56 * scale);

	background = CreateEntity<Entity>(
		"data/sprites/atlas.png",
		{ 0, 0, baseWidth, baseHeight },
		{ 0, 0, windowWidth, windowHeight });

	lowerPipe1 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 330, 0, 26, 120 },
		{ windowWidth, 0, 26 * scale, 120 * scale });

	lowerPipe2 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 330, 0, 26, 120 },
		{ windowWidth + (windowWidth / 2) + (13*scale), 0, 26 * scale, 120 * scale});

	upperPipe1 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{302, 0, 26, 135},
		{ lowerPipe1->rect.x,0, 26 * scale, 135 * scale});

	upperPipe2 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 302, 0, 26, 135 },
		{ lowerPipe2->rect.x ,0, 26 * scale, 135 * scale});

	bird = CreateEntity<Bird>(
		"data/sprites/atlas.png",
		{ 264, 90, 17, 12 },
		{ windowWidth / 4, 360, 17 * scale, 12 * scale });

	ground1 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 0, GameState::groundLevel , 154 * scale, 56 * scale });

	ground2 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 154 * scale, GameState::groundLevel , 154 * scale, 56 * scale });

	tapMessage = CreateEntity <TapMessage>(
		"data/sprites/atlas.png",
		{ 156, 122, 55,49 },
		{ windowWidth/2 - (156/2), 320, 55 * scale, 49 * scale});

	upperPipe1->startPosX
	= upperPipe2->startPosX
	= lowerPipe1->startPosX
	= lowerPipe2->startPosX
	= windowWidth;

	upperPipe1->SetAsUpperPipeOf(lowerPipe1);
	upperPipe2->SetAsUpperPipeOf(lowerPipe2);
}

void FlappyBird::Update() {
	App::Update();

	switch (GameState::currentScene) {
	case GameState::GameScene::TapToPlay: {
		if (Input::KeyJustPressed(SDLK_SPACE)) {
			GameState::currentScene = GameState::GameScene::Playing;
		}
	} break;
	}

	if (!upperPipe1->passed && bird->rect.x > upperPipe1->rect.x) {
		GameState::score += 1;
		upperPipe1->passed = true;
		std::cout << "SCORE: " << GameState::score << std::endl;
	}
	if (!upperPipe2->passed && bird->rect.x > upperPipe2->rect.x) {
		GameState::score += 1;
		upperPipe2->passed = true;
		std::cout << "SCORE: " << GameState::score << std::endl;
	}
}
