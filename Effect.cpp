#include "Effect.h"
#include <DxLib.h>
#include "string"
#include <assert.h>

namespace {
	const float ANIME_TIME = { 1.0f };
	const int EFFECT_IMAGE_SIZE = 48;
	const std::string EIMG_PATH = "Assets/explosion.png";
	const int MAX_FRAME = 9;
	const int DIV_NAM = 3;
	const float FRAME_TIME = ANIME_TIME / MAX_FRAME;
}


Effect::Effect(Point _pos)
	:GameObject(), pos_({ _pos.x, _pos.y }),hImage_(std::vector<int>(MAX_FRAME,-1)), animeTimer_(ANIME_TIME),frameTimer_(FRAME_TIME),frame_(0)
{
	//hImage_ = LoadGraph("Assets\\explosion.png");
	LoadDivGraph(EIMG_PATH.c_str(), MAX_FRAME, DIV_NAM, DIV_NAM, EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE, hImage_.data());
	AddGameObject(this);
}

Effect::~Effect()
{
	//DeleteGraph(hImage_);
}

void Effect::Update()
{
	float dt = GetDeltaTiem();
	animeTimer_ = animeTimer_ - dt;
	if (animeTimer_ < 0)
	{
		this->isAlive_ = false;
	}

	frameTimer_ = frameTimer_ - dt;
	if (frameTimer_ < 0)
	{
		frame_++;
		frameTimer_ = FRAME_TIME - frameTimer_;
	}
}

void Effect::Draw()
{
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x + 48, pos_.y + 48,hImage_[frame_], TRUE);
}