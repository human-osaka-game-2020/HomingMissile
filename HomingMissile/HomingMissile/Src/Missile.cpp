#include "Missile.h"
#include"DxLib.h"
#include<math.h>

Missile::Missile()
{
	PosX = 0;
	PosY = 0;
	CPosX = 55.0;
	CPosY = 33.5;
	Angle = 0.0;
	Speed = 2.0;
	Radian = 0.0;
}

Missile::~Missile()
{
	ReleaseTexture();
}

void Missile::Exec()
{
	float vecX = TargetPosX - PosX;
	float vecY = TargetPosY - PosY;
	float vec = sqrtf((vecX * vecX) + (vecY * vecY));
	float DistanceX = vecX / vec;
	float DistanceY = vecY / vec;

	Radian = atan2(TargetPosY - PosY, TargetPosX - PosX);
	
	PosX += DistanceX * Speed;
	PosY += DistanceY * Speed;
}

void Missile::Draw()
{
	DrawRotaGraph2(PosX, PosY, CPosX, CPosY, 1.0, Radian, Texture, TRUE);
}				   

void Missile::InitTexture()
{
	Texture = LoadGraph("Res/muki.png", TRUE);
}

void Missile::ReleaseTexture()
{
	DeleteGraph(Texture);
}

void Missile::GetPoston(float x_, float y_)
{
	TargetPosX = x_;
	TargetPosY = y_;
}
