#include "Enemy.h"
#include "DxLib.h"
#include <string>
#include "Effect.h"
//#include "EnemyBeam.h"

namespace
{
	const int ENEMY_IMAGE_WIDTH = 48;    // “G‚Ì‰æ–Ê‚Ì•
	const int ENEMY_IMAGE_HEIGHT = 48;	  // “G‚Ì‰æ–Ê‚Ì‚‚³

	const float ENEMY_INIT_X = 100;  // “G‚Ì‰ŠúXÀ•W
	const float ENEMY_INIT_Y = 100; // “G‚Ì‰ŠúYÀ•W
	const float ENEMY_INIT_SPEED = 1.0f; // “G‚Ì‰Šú‘¬“x 
	float CENTER_X = WIN_WIDTH / 2;
	const float ENEMY_MOVE_DIS = 55.0 * 10 / 2;
	const int ENEMY_BULLET_NUM = 10;
	const int BEAM_IMAGE_MAGIN = 17;
}

Enemy::Enemy()
	:GameObject(),
	hImage_(-1),
	x_(0), y_(0),
	speed_(0),
	cTime(0),
	ID_(0),
	imageSize_({ENEMY_IMAGE_WIDTH,ENEMY_IMAGE_HEIGHT})
{
	hImage_ = LoadGraph("Assets\\tiny_ship10.png");
	if (hImage_ == -1)
	{

	}
	for (int i = 0;i < ENEMY_BULLET_NUM;i++)
	{
		beam_.push_back(new EnemyBeam(-10, -10)); // ’e‚ÌƒxƒNƒ^[‚ğ‰Šú‰»
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
	cTime(0),
	ID_(id),type_(type), imageSize_({ ENEMY_IMAGE_WIDTH, ENEMY_IMAGE_HEIGHT })
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
	new Effect({ x_,y_ });
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);
	}
}

void Enemy::Update()
{
	static float beamTimer = 3.0f;

	static float rTime = 3.0f;
	cTime += GetDeltaTiem();
	if (cTime <= rTime)
	{
		x_ += speed_;
	}
	else if (cTime >= rTime)
	{
		x_ -= speed_;
		if (cTime >= rTime * 2)
		{
			cTime = 0.0f;
		}
	}
	//float period = 10.0f; // ˆê‰•œ‚É‚©‚¯‚éŠÔ(•b)
	//float omega = 2.0f * 3.1445926535f / period; // Šp‘¬“x@ƒÖ = 2ƒÎ
	//cTime = cTime + GetDeltaTiem();
	//x_ = xorigin_ + xMoveMax_ / 2.0f * sinf(omega * moveTime_);
	//y_ = y_;

	if (beamTimer < 0)
	{
		new EnemyBeam(x_ + ENEMY_IMAGE_WIDTH / 2, y_ + ENEMY_IMAGE_HEIGHT);
		beamTimer = 3.0f;
	}
	beamTimer -= GetDeltaTiem();
}

void Enemy::Draw()
{
	DrawExtendGraph((int)x_, (int)y_, (int)(x_ + ENEMY_IMAGE_WIDTH), (int)(y_ + ENEMY_IMAGE_HEIGHT), hImage_, TRUE);
}

void Enemy::Shoot()
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

	EnemyBeam* bem = GetActiveBullet();
	if (bem != nullptr)
	{
		bem->SetPos(x_ + BEAM_IMAGE_MAGIN, y_); // ’e‚ÌˆÊ’u‚ğŒˆ’è
		bem->SetFired(true); // ”­Ëó‘Ô‚É‚·‚é
	}
}

EnemyBeam* Enemy::GetActiveBullet()
{
	for (auto& itr : beam_)
	{
		if (!itr->IsFired())
		{
			return itr; // ”­Ë‚³‚ê‚Ä‚¢‚È‚¢’e‚ğ•Ô‚·
		}
	}
	return nullptr;
}
