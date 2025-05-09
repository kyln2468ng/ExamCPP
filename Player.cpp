#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"

namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; // プレイヤーの初期移動速度 
	const int PLAYER_IMAGE_WIDTH = 48;    // プレイヤーの画面の幅
	const int PLAYER_IMAGE_HEIGHT = 48;	  // プレイヤーの画面の高さ
	const int PLAYER_BACE_MARGIN = 32;

	const float PLAYER_INIT_X = (WIN_WIDTH - PLAYER_IMAGE_WIDTH) / 2;  // プレイヤーの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BACE_MARGIN; // プレイヤーの初期Y座標
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0),speed_(0)
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // プレイヤーの画像を読み込む
	if (hImage_ == -1)
	{

	}
	x_ = PLAYER_INIT_X; // 初期座標
	y_ = PLAYER_INIT_Y; // 初期座標
	speed_ = PLAYER_INIT_SPEED; // 初期速度
}

Player::~Player()
{
}

void Player::Update()
{
	float dt = GetDeltaTiem();
	if (Input::IsKeepKeyDown(KEY_INPUT_A))
	{
		x_ = x_ - speed_ * dt; // 右に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		x_ = x_ + speed_ * dt; // 左に移動
	}
}

void Player::Draw()
{
	// プレイヤーの画像を描画（画像の頂点は左上）
	DrawExtendGraph(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT, hImage_, TRUE);
}
