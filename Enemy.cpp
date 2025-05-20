#include "Enemy.h"
#include "DxLib.h"
#include <string>

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;    // ìGÇÃâÊñ ÇÃïù
	const int ENEMY_IMAGE_HEIGHT = 48;	  // ìGÇÃâÊñ ÇÃçÇÇ≥

	const float ENEMY_INIT_X = 100;  // ìGÇÃèâä˙Xç¿ïW
	const float ENEMY_INIT_Y = 100; // ìGÇÃèâä˙Yç¿ïW
	const float ENEMY_INIT_SPEED = 100.0f; // ìGÇÃèâä˙ë¨ìx 
}

Enemy::Enemy()
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	isAlive_(true),
	cTime(0),
	ID_(0),type_()
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	if (hImage_ == -1)
	{

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
}

Enemy::Enemy(int id, ETYPE type)
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	isAlive_(true),
	cTime(0),
	ID_(id),type_(type)
{
	//ETYPE::ZAKO;"Assets/tiny_ship10.png
	//ETYPE::MID;"Assets/tiny_ship18.png
	//ETYPE::KNIGHT;"Assets/tiny_ship16.png
	//ETYPE::BOSS;"Assets/tiny_ship9.png

	std::string imagePath[MAX_ETYPE] =
	{
		"Assets/tiny_ship10.png", // ZAKO
		"Assets/tiny_ship18.png", // MID
		"Assets/tiny_ship16.png", // KNIGHT
		"Assets/tiny_ship9.png"	  // BOSS

	};

	hImage_ = LoadGraph(imagePath[type_].c_str());
	if (hImage_ == -1)
	{

	}
	x_ = ENEMY_INIT_X;
	y_ = ENEMY_INIT_Y;
	speed_ = ENEMY_INIT_SPEED;
	AddGameObject(this);
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
	/*cTime += 0.06f;
	if (cTime < 5.0f)
	{
		x_ += 2.0f;
	}
	if (5.0f < cTime && cTime < 10.0f)
	{
		x_ -= 2.0f;
		if (cTime > 20.0f)
		{
			cTime = 0.0f;
		}
	}*/
}

void Enemy::Draw()
{
	DrawExtendGraph(x_, y_, x_ + ENEMY_IMAGE_WIDTH, y_ + ENEMY_IMAGE_HEIGHT, hImage_, TRUE);
}
