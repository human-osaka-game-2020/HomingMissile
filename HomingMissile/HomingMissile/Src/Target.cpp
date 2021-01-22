#include "Target.h"
#include"DxLib.h"

Target::Target()
{
	PosX = 200;
	PosY = 200;
	CPosX = 112.5;
	CPosY = 112.5;
	Speed = 10.0;
}

Target::~Target()
{
	DeleteGraph(Texture);
}

void Target::Exec()
{
	if (CheckHitKey(KEY_INPUT_UP))
	{
		PosY -= Speed;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		PosY += Speed;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		PosX += Speed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		PosX -= Speed;
	}
}

void Target::Draw()
{
	DrawRotaGraph2(PosX, PosY, CPosX, CPosY, 0.7, Angle, Texture, TRUE);
}

void Target::InitTexture()
{
	Texture = LoadGraph("Res/Target.png");
}


