#pragma once

struct GameState
{
	static enum class GameScene {
		MainMenu,
		TapToPlay,
		Playing,
		GameOver
	};
	static GameScene currentScene;
	static int scrollSpeed;
	static int groundLevel;
	static int score;
};
