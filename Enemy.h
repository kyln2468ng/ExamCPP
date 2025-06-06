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
    void SetPos(float x, float y) { x_ = x;y_ = y; } // “G‚ÌÀ•W‚Ìİ’è
    // void SetID(int id) { ID_ = id; } // “G‚ÌID‚ğİ’è
    Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // “G‚Ì‹éŒ`‚ğæ“¾
protected:
private:
    int hImage_;   // “G‚Ì‰æ‘œƒnƒ“ƒhƒ‹
    float x_, y_; // “G‚ÌÀ•W
    float speed_; // “G‚ÌˆÚ“®‘¬“x
    int ID_;       // “G‚ÌID 
    float cTime;   // “G‚ğˆÚ“®‚³‚¹‚éŠÔ  
    ETYPE type_;   // “G‚Ìí—Ş
    Point imageSize_;
};

