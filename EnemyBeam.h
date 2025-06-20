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
    int hImage_;          // �e�̉摜�̃n���h��
    Point pos_;            // �e�̍��W��ێ����邽�߂�point�\����
    float speed_;         // �e�̈ړ����x
    // int isize_x, isize_y; // �e�̕\���T�C�Y
    bool isFired_;         // ���˂���Ă邩�ǂ��� true: ���˂���Ă� 
    Point imageSize_;
};

