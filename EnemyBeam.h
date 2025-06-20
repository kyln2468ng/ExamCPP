#pragma once
#include "GameObject.h"
#include "globals.h"

class EnemyBeam :
    public GameObject
{
public:
    EnemyBeam();
    EnemyBeam(float x, float y);
    EnemyBeam(Point pos_);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

    //void SetPos_(float x, float y) { pos_.x = x;pos_.y = y; }
    void SetPos(const Point& pos) { pos_ = pos; }
    void SetFired(bool fired) { isFired_ = fired; }
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }
protected:
private:
    int hImage_;          // 弾の画像のハンドル
    Point pos_;            // 弾の座標を保持するためのpoint構造体
    float speed_;         // 弾の移動速度
    // int isize_x, isize_y; // 弾の表示サイズ
    bool isFired_;         // 発射されてるかどうか true: 発射されてる 
    Point imageSize_;
};

