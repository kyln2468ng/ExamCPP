#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10*7; // 敵の数
	const int ENEMY_COL_SIZE = 10; // 敵の列
	const int ENEMY_ROW_SIZE = 7;  // 敵の行
}

Stage::Stage()
	:GameObject(),player_(nullptr)
{
	AddGameObject(this); // ステージオブジェクトをゲームオブジェクト
	player_ = new Player(); // プレイヤーゲームオブジェクトの生成
	enemy_ = std::vector<Enemy*>(ENEMY_NUM); // 敵オブジェクトの生成

	for (int i = 0;i < ENEMY_NUM;i++)
	{
		int col = i % ENEMY_COL_SIZE;
		int row = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };

		enemy_[i] = new Enemy(i,enemyType[row]);
		enemy_[i]->SetPos(col * 50 , row * 50 );
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update(); // プレイヤーの更新
	for (auto& elm : enemy_) // 敵の更新
	{
		elm->Update();
	}
}

void Stage::Draw()
{
	player_->Draw(); // プレイヤーの描画
	for (auto& elm : enemy_) // 敵の描画
	{
		elm->Draw();
	}
}
