#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet :
    public GameObject
{
public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
    void SetFired(bool fired) { isFired_ = fired; }
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ x_,y_,imageSize_.x,imageSize_.y }; }
protected:
private:
    int hImage_;          // 弾の画像のハンドル
    float x_, y_;         // 弾の座標
    float speed_;         // 弾の移動速度
    // int isize_x, isize_y; // 弾の表示サイズ
    bool isFired_;         // 発射されてるかどうか true: 発射されてる 
    Point imageSize_;
};

