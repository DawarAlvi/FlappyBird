#include "GameState.h"

GameState::GameScene GameState::currentScene = GameScene::TapToPlay;
int GameState::scrollSpeed = 3;
int GameState::groundLevel = 0;
int GameState::score = 0;