#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include "Bullet.h"

namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; // �v���C���[�̏����ړ����x 
	const int PLAYER_IMAGE_WIDTH = 48;    // �v���C���[�̉�ʂ̕�
	const int PLAYER_IMAGE_HEIGHT = 48;	  // �v���C���[�̉�ʂ̍���
	const int PLAYER_BACE_MARGIN = 32;

	const float PLAYER_INIT_X = (WIN_WIDTH - PLAYER_IMAGE_WIDTH) / 2;  // �v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BACE_MARGIN; // �v���C���[�̏���Y���W
	const int BULLET_IMAGE_MAGIN = 17; // P_I_W - B_I_W )/2
	const float BULLET_INTERVAL = 0.5f; // �e�̔��ˊ��o
	const int PLAYER_BULLET_NUM = 5; // �v���C���[�������ɔ��˂ł��鐔
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0),speed_(0),imageSize_({PLAYER_IMAGE_WIDTH,PLAYER_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // �v���C���[�̉摜��ǂݍ���
	if (hImage_ == -1)
	{

	}
	x_ = PLAYER_INIT_X; // �������W
	y_ = PLAYER_INIT_Y; // �������W
	speed_ = PLAYER_INIT_SPEED; // �������x
	for (int i = 0;i < PLAYER_BULLET_NUM;i++)
	{
		bullets_.push_back(new Bullet(-10,-10)); // �e�̃x�N�^�[��������
	}
	AddGameObject(this); // �v���C���[�I�u�W�F�N�g���Q�[���I�u�W�F�N�g�ɒǉ����������g��ǉ��I��
}

Player::~Player()
{
}

void Player::Update()
{
	Point nextP = { x_,y_ };
	float dt = GetDeltaTiem();
	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		nextP.x = x_ - speed_ * dt; // �E�Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		nextP.x = x_ + speed_ * dt; // ���Ɉړ�
	}

	if (nextP.x >= 0 && (nextP.x + PLAYER_IMAGE_WIDTH) <= WIN_WIDTH)
	{
		x_ = nextP.x;
		y_ = nextP.y;
	}

	static float bulletTimer = 0.0f; // �e�̔��˃^�C�}�[
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot(); // �e�̔���
			//new Bullet(x_ + BULLET_IMAGE_MAGIN, y_); // �e�̔���
			bulletTimer = BULLET_INTERVAL; // �e�̔��ˊԊu�̃��Z�b�g
		}
	}
}

void Player::Draw()
{
	// �v���C���[�̉摜��`��i�摜�̒��_�͍���j
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}

void Player::Shoot()
{
	/*for (auto& itr : bullets_)
	{
		if (itr->IsFired() == false)
		{
			itr->SetPos(x_ + BULLET_IMAGE_MAGIN, y_);
			itr->SetFired(true);
			break;
		}
	}*/

	Bullet* blt = GetActiveBullet();
	if (blt != nullptr)
	{
		blt->SetPos(x_ + BULLET_IMAGE_MAGIN, y_); // �e�̈ʒu������
		blt->SetFired(true); // ���ˏ�Ԃɂ���
	}
}

Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr; // ���˂���Ă��Ȃ��e��Ԃ�
		}
	}
	return nullptr;
}

