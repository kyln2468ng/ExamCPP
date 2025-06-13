#pragma once
#include "GameObject.h"

namespace
{

    //std::vector<GameObject*> gameObjects; // ゲームオブジェクトのベクター
    //std::vector<GameObject*> newObjects; // ゲームオブジェクトのベクター
}

class PlayScene : public GameObject
{
public:
    PlayScene();
    ~PlayScene();
    void Update() override;
    void Draw() override;
    //std::vector<GameObject*> gameObjects; // ゲームオブジェクトのベクター
    //std::vector<GameObject*> newObjects; // ゲームオブジェクトのベクター
};

