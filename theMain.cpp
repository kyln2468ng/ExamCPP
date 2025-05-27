#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "Stage.h"

// STL(Standard Template Library)�cvector,list,forward_list,queue,stack,array,set,map,pair...�Ȃǂ�STL�ɑ����Ă�
//                               �R���e�i(container)
namespace
{
	const int BGCOLOR[3] = { 0, 0, 0 }; // �w�i�F
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; // �Q�[���̃��u�W�F�N�g�̃x�N�^�[
std::vector<GameObject*> newObjects; // �Q�[���I�u�W�F�N�g�̃x�N�^�[

float gDeltaTime = 0.0f; // �t���[���Ԃ̎��ԍ��@

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

void MyGame()
{

	DrawFormatString(100, 100, GetColor(0, 0, 0), "�E�B���h�E�̃e�X�g");
	static int timer = 0;
	timer++;
	DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	crrTime = GetNowCount();
	prevTime = GetNowCount();

	Stage* stage = new Stage();

	//const int ENEMY_NUM = 10; // �G�̐�
	//Player* player = new Player();
	//Enemy* enemy = new Enemy[ENEMY_NUM];
	//for (int i = 0;i < 10;i++)
	//{
	//	enemy[i].SetPos(100 + i * 50, 100);
	//}
	//std::vector<Enemy> enemy(ENEMY_NUM); // std::vector���g�p���ēG�̔z����
	//for (int i = 0;i < ENEMY_NUM;i++)
	//{
	//	enemy[i].SetPos(100 + i * 50, 100);
	//}
	//int i = 0;
	//for (auto& e : enemy)
	//{
	//	e.SetPos(100 + i * 50, 100);
	//	i++;
	//}


	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate(); // �L�[�̏�Ԃ��X�V

		crrTime = GetNowCount(); // ���݂̎��Ԃ��擾
		// �O��̍������v�Z
		float delatTime = (crrTime - prevTime) / 1000.0f;
		gDeltaTime = delatTime;

		if (newObjects.size() > 0)
		{
			for (auto& obj : newObjects)
			{
				gameObjects.push_back(obj);
			}
		}

		for (auto& obj : newObjects)
		{
			gameObjects.push_back(obj); // �V�����Q�[���I�u�W�F�N�g��ǉ�
		}
		newObjects.clear();			// �V�����Q�[���I�u�W�F�N�g�̃x�N�^�[���N���A

		// gameobjects�̍X�V
		for (auto& obj : gameObjects)
		{
			obj->Update(); // �Q�[���I�u�W�F�N�g�̍X�V
		}
		// gameObjects�̕`��
		for (auto& obj : gameObjects)
		{
			obj->Draw(); // �Q�[���I�u�W�F�N�g�̕`��
		}

		//for (auto it = gameObjects.begin(); it != gameObjects.end();) 
		//{
		//	if (!(*it)->IsAlive()) 
		//	{
		//		delete* it; // �Q�[���I�u�W�F�N�g���폜
		//		it = gameObjects.erase(it); // �x�N�^�[����폜
		//	}
		//	else 
		//	{
		//		++it; // ���̗v�f��
		//	}
		//}

		////�����ɂ�肽������������
		//player->Update();
		//player->Draw();

		//// �S���̗v�f(�R���e�i)�ɂȂ񂩂��炷��
		//for (auto& elm : enemy) // &������ƎQ�ƂɂȂ�B�Ȃ�����Ȃ���R�s�[���ł���
		//{
		//	elm.Update();
		//	elm.Draw();
		//}
		//for (int i = 0;i < 10;i++ )
		//{
		//	(enemy+i)->Update();
		//	(enemy+i)->Draw();
		//}
		// ����ʂ̕`��

		/*stage->Update();
		stage->Draw();*/

		ScreenFlip();
		WaitTimer(16);

		prevTime = crrTime; // ���݂̎��ԑO��̎��ԂƂ��ĕۑ�

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}