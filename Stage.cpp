#include "DxLib.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

namespace
{
	const int ENEMY_NUM = 10*7; // 敵の数
	const int ENEMY_COL_SIZE = 10; // 敵の列
	const int ENEMY_ROW_SIZE = 7;  // 敵の行
	const float ENEMY_ALIGN_X = 55.0f; // 敵を並べる幅
	const float ENEMY_ALIGN_Y = 50.0f;// 敵を並べる高さ
	const int ENEMY_LEFT_MARGIN = (WIN_WIDTH - (ENEMY_ALIGN_X * ENEMY_COL_SIZE)) / 2;
	const int ENEMY_TOP_MARGIN = 75;

	bool IntersectRect(const Rect& _a, const Rect& _b)
	{
		// X軸方向の重なりを判定
		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);

		// Y軸方向の重なりを判定
		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);

		// X軸とY軸の両方で重なっていれば衝突している
		return xOverlap && yOverlap;
	}
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

		enemy_[i]->SetPos(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN, row * ENEMY_ALIGN_Y + ENEMY_TOP_MARGIN);
	}
	hBackGround = LoadGraph("Assets/bg.png");

}

Stage::~Stage()
{
}

void Stage::Update()
{
	//player_->Update(); // プレイヤーの更新
	//for (auto& elm : enemy_) // 敵の更新
	//{
	//	elm->Update();
	//}
	
	//ここに当たり判定を描きたい！
	std::vector<Bullet*> bullets = player_->GetAllBullets();
	for (auto& e : enemy_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFired() && e->IsAlive()) {
				if (IntersectRect(e->GetRect(), b->GetRect()))
				{
					// DrawText("atatta", 0, 0, GetColor(255, 0, 0));
					if (b->IsFired())
						b->SetFired(false);
					if (e->IsAlive())
						e->SetAlive(false);
				}
			}
		}
	}

}

void Stage::Draw()
{
	//player_->Draw(); // プレイヤーの描画
	//for (auto& elm : enemy_) // 敵の描画
	//{
	//	elm->Draw();
	//}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackGround, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
//#include <DxLib.h>
//#include "Stage.h"
//#include "Player.h"
//#include "Enemy.h"
//#include "Bullet.h"
//
//namespace
//{
//	const int ENEMY_NUM = 10 * 7; // 敵の数
//	const int ENEMY_COL_SIZE = 10; // 敵の列数
//	const int ENEMY_ROW_SIZE = 7; // 敵の行数
//	bool IntersectRect(const Rect& _a, const Rect& _b)
//	{
//		// X軸方向の重なりを判定
//		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);
//
//		// Y軸方向の重なりを判定
//		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);
//
//		// X軸とY軸の両方で重なっていれば衝突している
//		return xOverlap && yOverlap;
//	}
//}
//
//Stage::Stage()
//	:GameObject(), player_(nullptr), hBackGround(-1)
//{
//	AddGameObject(this); // ステージオブジェクトをゲームオブジェクトのベクターに追加
//	player_ = new Player(); // プレイヤーオブジェクトの生成
//	enemy_ = std::vector<Enemy*>(ENEMY_NUM); // 敵オブジェクトの生成
//	for (int i = 0; i < ENEMY_NUM; i++) {
//		int col = i % ENEMY_COL_SIZE; // 列
//		int row = i / ENEMY_COL_SIZE; // 行
//		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS, KNIGHT, MID, ZAKO, ZAKO, ZAKO, ZAKO }; // 敵の種類
//		enemy_[i] = new Enemy(i, enemyType[row]); // 敵オブジェクトの生成
//
//		enemy_[i]->SetPos(col * 55.0f, row * 50.0f); // 敵の初期位置を設定
//
//	}
//	hBackGround = LoadGraph("Assets\\bg.png");
//}
//
//Stage::~Stage()
//{
//}
//
//void Stage::Update()
//{
//	//ここに当たり判定を描きたい！
//	std::vector<Bullet*> bullets = player_->GetAllBullets();
//	for (auto& e : enemy_)
//	{
//		for (auto& b : bullets)
//		{
//			if (b->IsFired() && e->IsAlive()) {
//				if (IntersectRect(e->GetRect(), b->GetRect()))
//				{
//					if (b->IsFired())
//						b->SetFired(false);
//					if (e->IsAlive())
//						e->SetAlive(false);
//				}
//			}
//		}
//	}
//
//}
//
//void Stage::Draw()
//{
//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 200);
//	DrawExtendGraph(0, 0, WIN_WIDTH, WIN_HEIGHT, hBackGround, FALSE);
//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
//}