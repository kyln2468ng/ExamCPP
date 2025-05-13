#include "Stage.h"
#include "Player.h"
#include "Enemy.h"

namespace
{
	const int ENEMY_NUM = 10*7; // �G�̐�
	const int ENEMY_COL_SIZE = 10; // �G�̗�
	const int ENEMY_ROW_SIZE = 7;  // �G�̍s
}

Stage::Stage()
	:GameObject(),player_(nullptr)
{
	player_ = new Player();
	enemy_ = std::vector<Enemy*>(ENEMY_NUM);

	for (int i = 0;i < ENEMY_NUM;i++)
	{
		int col = i % ENEMY_COL_SIZE;
		int row = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };

		enemy_[i] = new Enemy(i,enemyType[row]);
		enemy_[i]->SetPos(col * 50 + 100, row * 50 + 100);
	}
}

Stage::~Stage()
{
}

void Stage::Update()
{
	player_->Update(); // �v���C���[�̍X�V
	for (auto& elm : enemy_) // �G�̍X�V
	{
		elm->Update();
	}
}

void Stage::Draw()
{
	player_->Draw(); // �v���C���[�̕`��
	for (auto& elm : enemy_) // �G�̕`��
	{
		elm->Draw();
	}
}
