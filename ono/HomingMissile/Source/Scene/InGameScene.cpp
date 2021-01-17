
#include "InGameScene.h"
#include "../Object/Player.h"
#include "../Object/Missile.h"
#include "../Difinition.h"

Player g_player;
Missile g_missile[MissileMax];

InGameScene::InGameScene()
{
	g_player.SetPos(WindowWidth / 2, WindowHeight / 2);
	g_player.SetMoveSpeed(10.0f);

	for (int MissileNum = 0; MissileNum < MissileMax; MissileNum++)
	{
		g_missile[MissileNum].SetPos((MissileNum * (WindowWidth / MissileMax)) + 180, (WindowHeight / MissileMax), 10);
	}
}

InGameScene::~InGameScene()
{
}

void InGameScene::Exec()
{
	g_player.Update();

	for (int MissileNum = 0; MissileNum < MissileMax; MissileNum++)
	{
		g_missile[MissileNum].Exec(g_player.GetPosX(), g_player.GetPosY());
	}
}

void InGameScene::Draw()
{
	g_player.Draw();

	for (int MissileNum = 0; MissileNum < MissileMax; MissileNum++)
	{
		g_missile[MissileNum].Draw();
	}

}
