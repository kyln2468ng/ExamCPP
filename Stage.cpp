#include "DxLib.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EnemyBeam.h"
#include "Effect.h"

namespace
{
	const int ENEMY_NUM = 10*7; // �G�̐�
	const int ENEMY_COL_SIZE = 10; // �G�̗�
	const int ENEMY_ROW_SIZE = 7;  // �G�̍s
	const float ENEMY_ALIGN_X = 55.0f; // �G����ׂ镝
	const float ENEMY_ALIGN_Y = 50.0f;// �G����ׂ鍂��
	const int ENEMY_LEFT_MARGIN = (WIN_WIDTH - (ENEMY_ALIGN_X * ENEMY_COL_SIZE)) / 2;
	const int ENEMY_TOP_MARGIN = 75;
	const int ENEMY_BEAM_LIMIT = 10; // ��ʏ�ɏo���G�̒e��

	bool IntersectRect(const Rect& _a, const Rect& _b)
	{
		// X�������̏d�Ȃ�𔻒�
		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);

		// Y�������̏d�Ȃ�𔻒�
		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);

		// X����Y���̗����ŏd�Ȃ��Ă���ΏՓ˂��Ă���
		return xOverlap && yOverlap;
	}
}

Stage::Stage()
	:GameObject(),player_(nullptr)
{
	AddGameObject(this); // �X�e�[�W�I�u�W�F�N�g���Q�[���I�u�W�F�N�g
	player_ = new Player(); // �v���C���[�Q�[���I�u�W�F�N�g�̐���
	enemy_ = std::vector<Enemy*>(ENEMY_NUM); // �G�I�u�W�F�N�g�̐���
	bem_ = std::vector<EnemyBeam*>(ENEMY_BEAM_LIMIT);

	for (int i = 0;i < ENEMY_NUM;i++)
	{
		int col = i % ENEMY_COL_SIZE;
		int row = i / ENEMY_COL_SIZE;
		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS,KNIGHT,MID,ZAKO,ZAKO,ZAKO };

		enemy_[i] = new Enemy(i,enemyType[row]);

		enemy_[i]->SetPos(col * ENEMY_ALIGN_X + ENEMY_LEFT_MARGIN, row * ENEMY_ALIGN_Y + ENEMY_TOP_MARGIN);
	}
	hBackGround = LoadGraph("Assets/bg.png");

	for (int i = 0;i < ENEMY_BEAM_LIMIT;i++)
	{
		bem_[i] = new EnemyBeam(enemy_[i]->GetRect().x, enemy_[i]->GetRect().y);
	}
}

Stage::~Stage()
{
	//player_->~Player();
	//enemy_
}

void Stage::Update()
{
	//player_->Update(); // �v���C���[�̍X�V
	//for (auto& elm : enemy_) // �G�̍X�V
	//{
	//	elm->Update();
	//}

	//�����ɓ����蔻���`�������I
	// enemy�̓����蔻��
	std::vector<Bullet*> bullets = player_->GetAllBullets();
	for (auto& e : enemy_)
	{
		for (auto& b : bullets)
		{
			if (b->IsFired() && e->IsAlive())
			{
				if (IntersectRect(e->GetRect(), b->GetRect()))
				{
					// DrawText("atatta", 0, 0, GetColor(255, 0, 0));
					if (b->IsFired())
						b->SetFired(false);
					if (e->IsAlive())
					{
						e->SetAlive(false);
						new Effect({ e->GetRect().x,e->GetRect().y });
					}
				}
			}
		}
	}

	
	for (auto& bm : bem_)
	{
		if (bm->IsFired() && player_->IsAlive())
		{
			if (IntersectRect(bm->GetRect(), player_->GetRect()))
			{
				if (bm->IsFired())
					bm->SetFired(false);
				if (player_->IsAlive())
				{
					player_->SetAlive(false);
					isAlive_ = false;
					for (auto& e : enemy_)
					{
						e->SetAlive(false);
					}
				}
			}
		}
	}
	// player�̓����蔻��
	//std::vector<EnemyBeam*> beams = enemy->GetAllBullets();
	//for (auto& p : player)
	//{
	//	for (auto& b : beams)
	//	{
	//		if (b->IsFired() && p->IsAlive()) {
	//			if (IntersectRect(p->GetRect(), b->GetRect()))
	//			{
	//				// DrawText("atatta", 0, 0, GetColor(255, 0, 0));
	//				if (b->IsFired())
	//					b->SetFired(false);
	//				if (p->IsAlive())
	//					p->SetAlive(false);
	//			}
	//		}
	//	}
	//}



	static float beamTimer = 3.0f;
	if (beamTimer < 0)
	{
		beamTimer = 3.0f;
		for (int i = 0;i < ENEMY_BEAM_LIMIT;i++)
		{
			bem_[i] = new EnemyBeam(enemy_[i]->GetRect().x, enemy_[i]->GetRect().y);
		}
	}
	beamTimer -= GetDeltaTiem();
}

void Stage::Draw()
{
	//player_->Draw(); // �v���C���[�̕`��
	//for (auto& elm : enemy_) // �G�̕`��
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
//	const int ENEMY_NUM = 10 * 7; // �G�̐�
//	const int ENEMY_COL_SIZE = 10; // �G�̗�
//	const int ENEMY_ROW_SIZE = 7; // �G�̍s��
//	bool IntersectRect(const Rect& _a, const Rect& _b)
//	{
//		// X�������̏d�Ȃ�𔻒�
//		bool xOverlap = (_a.x < _b.x + _b.width) && (_b.x < _a.x + _a.width);
//
//		// Y�������̏d�Ȃ�𔻒�
//		bool yOverlap = (_a.y < _b.y + _b.height) && (_b.y < _a.y + _a.height);
//
//		// X����Y���̗����ŏd�Ȃ��Ă���ΏՓ˂��Ă���
//		return xOverlap && yOverlap;
//	}
//}
//
//Stage::Stage()
//	:GameObject(), player_(nullptr), hBackGround(-1)
//{
//	AddGameObject(this); // �X�e�[�W�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
//	player_ = new Player(); // �v���C���[�I�u�W�F�N�g�̐���
//	enemy_ = std::vector<Enemy*>(ENEMY_NUM); // �G�I�u�W�F�N�g�̐���
//	for (int i = 0; i < ENEMY_NUM; i++) {
//		int col = i % ENEMY_COL_SIZE; // ��
//		int row = i / ENEMY_COL_SIZE; // �s
//		ETYPE enemyType[ENEMY_ROW_SIZE] = { BOSS, KNIGHT, MID, ZAKO, ZAKO, ZAKO, ZAKO }; // �G�̎��
//		enemy_[i] = new Enemy(i, enemyType[row]); // �G�I�u�W�F�N�g�̐���
//
//		enemy_[i]->SetPos(col * 55.0f, row * 50.0f); // �G�̏����ʒu��ݒ�
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
//	//�����ɓ����蔻���`�������I
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