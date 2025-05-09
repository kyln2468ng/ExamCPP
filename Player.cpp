#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"

namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; // �v���C���[�̏����ړ����x 
	const int PLAYER_IMAGE_WIDTH = 48;    // �v���C���[�̉�ʂ̕�
	const int PLAYER_IMAGE_HEIGHT = 48;	  // �v���C���[�̉�ʂ̍���
	const int PLAYER_BACE_MARGIN = 32;

	const float PLAYER_INIT_X = (WIN_WIDTH - PLAYER_IMAGE_WIDTH) / 2;  // �v���C���[�̏���X���W
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BACE_MARGIN; // �v���C���[�̏���Y���W
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0),speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // �v���C���[�̉摜��ǂݍ���
	if (hImage_ == -1)
	{

	}
	x_ = PLAYER_INIT_X; // �������W
	y_ = PLAYER_INIT_Y; // �������W
	speed_ = PLAYER_INIT_SPEED; // �������x
}

Player::~Player()
{
}

void Player::Update()
{
	float dt = GetDeltaTiem();
	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		x_ = x_ - speed_ * dt; // �E�Ɉړ�
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		x_ = x_ + speed_ * dt; // ���Ɉړ�
	}
}

void Player::Draw()
{
	// �v���C���[�̉摜��`��i�摜�̒��_�͍���j
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
