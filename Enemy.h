#pragma once
#include "GameObject.h"
#include "globals.h"

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
    void SetPos(float x, float y) { x_ = x;y_ = y; } // �G�̍��W�̐ݒ�
    // void SetID(int id) { ID_ = id; } // �G��ID��ݒ�
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // �G�̋�`���擾
protected:
private:
    int hImage_;   // �G�̉摜�n���h��
    float x_, y_; // �G�̍��W
    float speed_; // �G�̈ړ����x
    int ID_;       // �G��ID 
    float cTime;   // �G���ړ������鎞��  
    ETYPE type_;   // �G�̎��
    Point imageSize_;
};

