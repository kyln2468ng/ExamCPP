#include "GameScene.h"
#include "Input.h"
#include <DxLib.h>

GameScene::GameScene()
	:sceneState(TITLE)
{
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	switch (sceneState)
	{
	case TITLE:
		if (Input::IsKeyDown(KEY_INPUT_P))
		{
			sceneState = PLAY;
		}
		break;
	case PLAY:
		if (Input::IsKeyDown(KEY_INPUT_O))
		{
			sceneState = GAMEOVER;
		}
		break;
	case GAMEOVER:
		if (Input::IsKeyDown(KEY_INPUT_T))
		{
			sceneState = TITLE;
		}
		break;
	default:
		break;
	}
}

void GameScene::Draw()
{
	switch (sceneState)
	{
	case TITLE:
		DrawString(0, 0, "TITLE SCENE", GetColor(255, 255, 255));
		break;
	case PLAY:
		DrawString(0, 0, "PlAY SCENE", GetColor(255, 255, 255));
		break;
	case GAMEOVER:
		DrawString(0, 0, "GAMEOVER SCENE", GetColor(255, 255, 255));
		break;
	default:
		break;
	}
}
