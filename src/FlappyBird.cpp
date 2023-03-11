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
	
	Ground* ground1 = CreateEntity <Ground>(
		"data/sprites/atlas.png", 
		{ 146, 0, 154,56 },
		{ 0, windowHeight - (56 * scale) , 154 * scale, 56 * scale});

	Ground* ground2 = CreateEntity <Ground>(
		"data/sprites/atlas.png",
		{ 146, 0, 154,56 },
		{ 154 * scale, windowHeight - (56 * scale) , 154 * scale, 56 * scale });

	Entity* bird = CreateEntity<Entity>(
		"data/sprites/atlas.png",
		{ 264, 90, 17, 12},
		{ windowWidth / 4, windowHeight / 2, 17 * scale, 12 * scale});
}