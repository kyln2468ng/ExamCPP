#pragma once


namespace Input {
	//�L�[�{�[�h�擾�֘A
	void KeyStateUpdate(); // �L�[�̏�Ԃ��X�V
	bool IsKeyUp(int keyCode); // �L�[�������ꂽ�u��
	bool IsKeyDown(int keyCode); // �L�[�������ꂽ�u��
	int IsKeepKeyDown(int keyCode); // �L�[��������Ă����
}