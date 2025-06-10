#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include "Bullet.h"

namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; // プレイヤーの初期移動速度 
	const int PLAYER_IMAGE_WIDTH = 48;    // プレイヤーの画面の幅
	const int PLAYER_IMAGE_HEIGHT = 48;	  // プレイヤーの画面の高さ
	const int PLAYER_BACE_MARGIN = 32;

	const float PLAYER_INIT_X = (WIN_WIDTH - PLAYER_IMAGE_WIDTH) / 2;  // プレイヤーの初期X座標
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BACE_MARGIN; // プレイヤーの初期Y座標
	const int BULLET_IMAGE_MAGIN = 17; // P_I_W - B_I_W )/2
	const float BULLET_INTERVAL = 0.5f; // 弾の発射感覚
	const int PLAYER_BULLET_NUM = 5; // プレイヤーが同時に発射できる数
}

Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0),speed_(0),imageSize_({PLAYER_IMAGE_WIDTH,PLAYER_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // プレイヤーの画像を読み込む
	if (hImage_ == -1)
	{

	}
	x_ = PLAYER_INIT_X; // 初期座標
	y_ = PLAYER_INIT_Y; // 初期座標
	speed_ = PLAYER_INIT_SPEED; // 初期速度
	for (int i = 0;i < PLAYER_BULLET_NUM;i++)
	{
		bullets_.push_back(new Bullet(-10,-10)); // 弾のベクターを初期化
	}
	AddGameObject(this); // プレイヤーオブジェクトをゲームオブジェクトに追加※自分自身を追加的な
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
		nextP.x = x_ - speed_ * dt; // 右に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_D))
	{
		nextP.x = x_ + speed_ * dt; // 左に移動
	}

	if (nextP.x >= 0 && (nextP.x + PLAYER_IMAGE_WIDTH) <= WIN_WIDTH)
	{
		x_ = nextP.x;
		y_ = nextP.y;
	}

	static float bulletTimer = 0.0f; // 弾の発射タイマー
	if (bulletTimer > 0.0f)
	{
		bulletTimer -= dt;
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE))
	{
		if (bulletTimer <= 0.0f)
		{
			Shoot(); // 弾の発射
			//new Bullet(x_ + BULLET_IMAGE_MAGIN, y_); // 弾の発射
			bulletTimer = BULLET_INTERVAL; // 弾の発射間隔のリセット
		}
	}
}

void Player::Draw()
{
	// プレイヤーの画像を描画（画像の頂点は左上）
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
		blt->SetPos(x_ + BULLET_IMAGE_MAGIN, y_); // 弾の位置を決定
		blt->SetFired(true); // 発射状態にする
	}
}

Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr; // 発射されていない弾を返す
		}
	}
	return nullptr;
}

