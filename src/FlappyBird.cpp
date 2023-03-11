#include "FlappyBird.h"

int main(int argc, char* argv[]) {
	FlappyBird app("Flappy Bird", 143, 256, 3);
	app.Run();
	return 0;
}

FlappyBird::FlappyBird(const char* title, int width, int height, int scale)
	: App(title, width, height, scale) {


	Entity* background = CreateEntity<Entity>(
		"data/sprites/atlas.png",
		{ 0, 0, baseWidth, baseHeight },
		{ 0, 0, windowWidth, windowHeight });
	
	Pipe* upperPipe1 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{302, 0, 26, 135},
		{windowWidth,0, 26 * scale, 135 * scale}
		);
	Pipe* upperPipe2 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 302, 0, 26, 135 },
		{ windowWidth + (windowWidth/2) + 39 ,0, 26 * scale, 135 * scale}
	);
	Pipe* lowerPipe1 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 330, 0, 26, 120},
		{ windowWidth,windowHeight - 120 * scale, 26 * scale, 120 * scale }
	);
	Pipe* lowerPipe2 = CreateEntity<Pipe>(
		"data/sprites/atlas.png",
		{ 330, 0, 26, 120 },
		{ windowWidth + (windowWidth/2) + 39,windowHeight - 120 * scale, 26 * scale, 120 * scale}
	);

	Ground* ground1 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 0, windowHeight - (56 * scale) , 154 * scale, 56 * scale });

	Ground* ground2 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 154 * scale, windowHeight - (56 * scale) , 154 * scale, 56 * scale });

	Bird* bird = CreateEntity<Bird>(
		"data/sprites/atlas.png",
		{ 264, 90, 17, 12},
		{ windowWidth / 4, windowHeight / 2, 17 * scale, 12 * scale});


	upperPipe1->startPosX
	= upperPipe2->startPosX
	= lowerPipe1->startPosX
	= lowerPipe2->startPosX
	= windowWidth;

}

void FlappyBird::Update() {
	App::Update();

}
