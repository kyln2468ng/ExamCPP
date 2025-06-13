#include "PlayScene.h"
#include "DxLib.h"
#include "globals.h"
#include "input.h"
#include <vector>
#include "Stage.h"

PlayScene::PlayScene()
{
	Stage* stage = new Stage(); // �X�e�[�W�I�u�W�F�N�g�̐���
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	//�Q�[���I�u�W�F�N�g�̒ǉ�
	if (newObjects.size() > 0) {
		for (auto& obj : newObjects) {
			gameObjects.push_back(obj); // �V�����Q�[���I�u�W�F�N�g��ǉ�	
		}
		newObjects.clear(); // �V�����Q�[���I�u�W�F�N�g�̃x�N�^�[���N���A
	}
	//gameObjects�̍X�V
	for (auto& obj : gameObjects) {
		obj->Update(); // �Q�[���I�u�W�F�N�g�̍X�V
	}
	//gameObjects�̕`��
	for (auto& obj : gameObjects) {
		obj->Draw(); // �Q�[���I�u�W�F�N�g�̕`��
	}

	for (auto it = gameObjects.begin(); it != gameObjects.end();) {
		if (!(*it)->IsAlive()) {
			delete* it; // �Q�[���I�u�W�F�N�g���폜
			it = gameObjects.erase(it); // �x�N�^�[����폜
		}
		else {
			++it; // ���̗v�f��
		}
	}
}

void PlayScene::Draw()
{
}
