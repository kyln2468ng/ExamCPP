#pragma once
#include "GameObject.h"
//#include "Player.h"
//#include "Enemy.h"
#include <vector>

class Player; // 前方宣言
class Enemy;  // 前方宣言

class Stage :
    public GameObject
{
private:
    Player* player_; // プレイヤーオブジェクト
    std::vector<Enemy*> enemy_; // 敵オブジェクト
    int hBackGround;
public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

