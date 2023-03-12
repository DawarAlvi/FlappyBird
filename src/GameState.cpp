#include "GameState.h"

GameState::GameScenes GameState::currentScene = TapToPlay;
int GameState::scrollSpeed = 3;
int GameState::groundLevel = 0;
int GameState::score = 0;