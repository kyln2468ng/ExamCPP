#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "Stage.h"

// STL(Standard Template Library)…vector,list,forward_list,queue,stack,array,set,map,pair...などがSTLに属してる
//                               コンテナ(container)
namespace
{
	const int BGCOLOR[3] = { 0, 0, 0 }; // 背景色
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; // ゲームのモブジェクトのベクター
std::vector<GameObject*> newObjects; // ゲームオブジェクトのベクター

float gDeltaTime = 0.0f; // フレーム間の時間差　

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage* stage = new Stage();

	//const int ENEMY_NUM = 10; // 敵の数
	//Player* player = new Player();
	//Enemy* enemy = new Enemy[ENEMY_NUM];
	//for (int i = 0;i < 10;i++)
	//{
	//	enemy[i].SetPos(100 + i * 50, 100);
	//}
	//std::vector<Enemy> enemy(ENEMY_NUM); // std::vectorを使用して敵の配列作る
	//for (int i = 0;i < ENEMY_NUM;i++)
	//{
	//	enemy[i].SetPos(100 + i * 50, 100);
	//}
	//int i = 0;
	//for (auto& e : enemy)
	//{
	//	e.SetPos(100 + i * 50, 100);
	//	i++;
	//}


	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate(); // キーの状態を更新

		crrTime = GetNowCount(); // 現在の時間を取得
		// 前回の差分を計算
		float delatTime = (crrTime - prevTime) / 1000.0f;
		gDeltaTime = delatTime;

		if (newObjects.size() > 0)
		{
			for (auto& obj : newObjects)
			{
				gameObjects.push_back(obj);
			}
		}

		for (auto& obj : newObjects)
		{
			gameObjects.push_back(obj); // 新しいゲームオブジェクトを追加
		}
		newObjects.clear();			// 新しいゲームオブジェクトのベクターをクリア

		// gameobjectsの更新
		for (auto& obj : gameObjects)
		{
			obj->Update(); // ゲームオブジェクトの更新
		}
		// gameObjectsの描画
		for (auto& obj : gameObjects)
		{
			obj->Draw(); // ゲームオブジェクトの描画
		}

		//for (auto it = gameObjects.begin(); it != gameObjects.end();) 
		//{
		//	if (!(*it)->IsAlive()) 
		//	{
		//		delete* it; // ゲームオブジェクトを削除
		//		it = gameObjects.erase(it); // ベクターから削除
		//	}
		//	else 
		//	{
		//		++it; // 次の要素へ
		//	}
		//}

		////ここにやりたい処理を書く
		//player->Update();
		//player->Draw();

		//// 全部の要素(コンテナ)になんかしらする
		//for (auto& elm : enemy) // &をつけると参照になる。なんもしなきゃコピーができる
		//{
		//	elm.Update();
		//	elm.Draw();
		//}
		//for (int i = 0;i < 10;i++ )
		//{
		//	(enemy+i)->Update();
		//	(enemy+i)->Draw();
		//}
		// 裏画面の描画

		/*stage->Update();
		stage->Draw();*/

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime; // 現在の時間前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}