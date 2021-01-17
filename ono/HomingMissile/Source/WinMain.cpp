
#include <stdio.h>
#include "DxLib.h"
#include "../Source/Scene/InGameScene.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �c�w���C�u��������������
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(1800, 1000, 32);
	SetBackgroundColor(180, 180, 180);
	SetMainWindowText("�ف[�݂񂮂݂�����");
	if (DxLib_Init() == -1)
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetDrawScreen(DX_SCREEN_BACK);

	// ����������
	InGameScene* pInGameScene = new InGameScene();

	// ���C�����[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// �c�w���C�u�������g����ŁA�P�t���[�����̏������n�߂邽�߂̂���
		// ----------------------------------------------------
		ClearDrawScreen();
		clsDx();

		// ����
		pInGameScene->Exec();

		// �`��
		pInGameScene->Draw();

		ScreenFlip();
	}
	delete pInGameScene;
	pInGameScene = nullptr;

	DxLib_End();			// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}
