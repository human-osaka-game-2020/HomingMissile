#include "Common.h"

Player player;
Bullet bullet[4];

enum
{
	kPlayer,
	kEnemy,

	kTextureMax,
};

int Texture[kTextureMax];

GameScene::GameScene()
{
	Texture[kPlayer] = LoadGraph("res/kao.png");
	Texture[kEnemy]  = LoadGraph("res/bullet.png");

	player.SetPos(Widht / 2, Height / 2);

	for (int i = 0; i < 4; i++)
	{

		bullet[i].SetPos(-50, -50 + i * 211);

		bullet[i].SetTheta(0);
	}
}

GameScene::~GameScene()
{
	for (int i = 0; i < kTextureMax; i++)
	{
		DeleteGraph(Texture[i]);
	}
}

void GameScene::Exec()
{
	player.Move();

	for (int i = 0; i < 4; i++)
	{
		bullet[i].Move(player.GetPosX(), player.GetPosY());
	}

	return;
}

void GameScene::Draw()
{
	DrawGraph(player.GetPosX()- 50, player.GetPosY() - 50, Texture[kPlayer], TRUE);

	for (int i = 0; i < 4; i++)
	{
		DrawRotaGraph2(bullet[i].GetPosX() - 32, bullet[i].GetPosY() - 32, 32, 0, 1.0f, (90.0f - bullet[i].GetTheta()) / 180.0f * M_PI, Texture[kEnemy], TRUE, FALSE);
	}

	return;
}

