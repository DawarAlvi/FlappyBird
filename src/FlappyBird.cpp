#include "FlappyBird.h"

int main(int argc, char* argv[]) {
	FlappyBird app("Flappy Bird", 143, 256, 3);
	app.Run();
	return 0;
}

FlappyBird::FlappyBird(const char* title, int width, int height, int scale)
	: App(title, width, height, scale) {

	GameState::groundLevel = windowHeight - (56 * scale);

	Entity* background = CreateEntity<Entity>(
		"data/sprites/atlas.png",
		{ 0, 0, baseWidth, baseHeight },
		{ 0, 0, windowWidth, windowHeight });

	Pipe* lowerPipe1 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 330, 0, 26, 120 },
		{ windowWidth, 0, 26 * scale, 120 * scale });

	Pipe* lowerPipe2 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 330, 0, 26, 120 },
		{ windowWidth + (windowWidth / 2) + (13*scale), 0, 26 * scale, 120 * scale});

	Pipe* upperPipe1 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{302, 0, 26, 135},
		{ lowerPipe1->rect.x,0, 26 * scale, 135 * scale});

	Pipe* upperPipe2 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 302, 0, 26, 135 },
		{ lowerPipe2->rect.x ,0, 26 * scale, 135 * scale});

	Bird* bird = CreateEntity<Bird>(
		"data/sprites/atlas.png",
		{ 264, 90, 17, 12 },
		{ windowWidth / 4, windowHeight / 2, 17 * scale, 12 * scale });

	Ground* ground1 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 0, GameState::groundLevel , 154 * scale, 56 * scale });

	Ground* ground2 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 154 * scale, GameState::groundLevel , 154 * scale, 56 * scale });

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

}
