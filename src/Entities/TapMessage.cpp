#include "TapMessage.h"

TapMessage::TapMessage(SDL_Renderer* renderer, const char* texturePath, SDL_Rect src, SDL_Rect rect)
	: Entity(renderer, texturePath, src, rect) {

}

void TapMessage::Update()
{
	switch (GameState::currentScene) {
	case GameState::GameScene::TapToPlay: {
		enabled = true;
	} break;
	case GameState::GameScene::Playing: {
		enabled = false;
	} break;
	}
}
