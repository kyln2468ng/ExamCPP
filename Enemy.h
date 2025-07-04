#pragma once
#include "GameObject.h"
#include "globals.h"
#include "EnemyBeam.h"

enum ETYPE
{
    ZAKO, MID, KNIGHT, BOSS, MAX_ETYPE
};

class Enemy :
    public GameObject
{
public:
    Enemy(int id,ETYPE type);
    Enemy();
    ~Enemy();
    void Update() override;
    void Draw() override;
    void SetPos(float x, float y) { x_ = x;y_ = y; } // 敵の座標の設定
    //void Shoot(); // 弾を発射する関数
    // void SetID(int id) { ID_ = id; } // 敵のIDを設定
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // 敵の矩形を取得
    std::vector<EnemyBeam*> GetAllBullets() const { return beam_; }
protected:
private:
    int hImage_;   // 敵の画像ハンドル
    float x_, y_; // 敵の座標
    float speed_; // 敵の移動速度
    int ID_;       // 敵のID 
    float cTime;   // 敵を移動させる時間  
    ETYPE type_;   // 敵の種類
    Point imageSize_;
    std::vector<EnemyBeam*> beam_; // プレイヤーが発射した弾のベクター
    //EnemyBeam* GetActiveBullet();
};

