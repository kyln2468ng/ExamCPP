#pragma once

enum Scene
{
	TITLE,
	PLAY,
	GAMEOVER,
	MAXSTATE
};

class GameScene
{
public:
	GameScene();
	~GameScene();
	void Update();
	void Draw();
protected:
private:
	int sceneState;
};

