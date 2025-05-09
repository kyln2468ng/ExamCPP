#include "Enemy.h"
#include "DxLib.h"

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;    // �G�̉�ʂ̕�
	const int ENEMY_IMAGE_HEIGHT = 48;	  // �G�̉�ʂ̍���

	const float ENEMY_INIT_X = 100;  // �G�̏���X���W
	const float ENEMY_INIT_Y = 100; // �G�̏���Y���W
	const float ENEMY_INIT_SPEED = 100.0f; // �G�̏������x 
}

Enemy::Enemy()
	:GameObject(),
	hImage_(-1),
	x_(0),y_(0),
	speed_(0),
	isAlive_(true)
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	if (hImage_ == -1)
	{

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
}

Enemy::~Enemy()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
