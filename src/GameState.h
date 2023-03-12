#pragma once

struct GameState
{
	static enum GameScenes {
		MainMenu,
		TapToPlay,
		Playing,
		GameOver
	};
	static GameScenes currentScene;
	static int scrollSpeed;
	static int groundLevel;
	static int score;
};
