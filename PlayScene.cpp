#include "PlayScene.h"
#include "DxLib.h"
#include "globals.h"
#include "input.h"
#include <vector>
#include "Stage.h"

PlayScene::PlayScene()
{
	Stage* stage = new Stage(); // ステージオブジェクトの生成
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	//ゲームオブジェクトの追加
	if (newObjects.size() > 0) {
		for (auto& obj : newObjects) {
			gameObjects.push_back(obj); // 新しいゲームオブジェクトを追加	
		}
		newObjects.clear(); // 新しいゲームオブジェクトのベクターをクリア
	}
	//gameObjectsの更新
	for (auto& obj : gameObjects) {
		obj->Update(); // ゲームオブジェクトの更新
	}
	//gameObjectsの描画
	for (auto& obj : gameObjects) {
		obj->Draw(); // ゲームオブジェクトの描画
	}

	for (auto it = gameObjects.begin(); it != gameObjects.end();) {
		if (!(*it)->IsAlive()) {
			delete* it; // ゲームオブジェクトを削除
			it = gameObjects.erase(it); // ベクターから削除
		}
		else {
			++it; // 次の要素へ
		}
	}
}

void PlayScene::Draw()
{
}
