#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet; // 前方宣言

class Player :
    public GameObject
{
    int hImage_;  // プレイヤーの画像ハンドル
    float x_, y_; // プレイヤーの座標
    float speed_; // プレイヤーの移動速度
    std::vector<Bullet*> bullets_; // プレイヤーが発射した弾のベクター
    Bullet* GetActiveBullet();
public:
    Player();
    ~Player();
    void Update() override;
    void Draw() override;
    void Shoot(); // 弾を発射する関数
    Rect GetRect() const { return { x_,y_,PLAYER_IMAGE_WIDTH,PLAYER_IMAGE_HEIGHT }; }
    std::vector<Bullet*> GetAllBullets() const { return bullets_; }
};

