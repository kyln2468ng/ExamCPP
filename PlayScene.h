#pragma once
#include "GameObject.h"

namespace
{

    //std::vector<GameObject*> gameObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
    //std::vector<GameObject*> newObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
}

class PlayScene : public GameObject
{
public:
    PlayScene();
    ~PlayScene();
    void Update() override;
    void Draw() override;
    //std::vector<GameObject*> gameObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
    //std::vector<GameObject*> newObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[
};

