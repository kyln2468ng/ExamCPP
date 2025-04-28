#include "Player.h"
#include "DxLib.h"

namespace
{
	const float PLAYER_INIT_X = 0.0f; // �v���C���[�̏���X���W
	const float PLAYER_INIT_Y = 0.0f;
	const float PLAYER_INIT_SPEED = 5.0f;
	const int PLAYER_IMAGE_WIDTH = 32;
	const int PLAYER_IMAGE_HEIGHT = 32;
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
}

void Player::Draw()
{
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
