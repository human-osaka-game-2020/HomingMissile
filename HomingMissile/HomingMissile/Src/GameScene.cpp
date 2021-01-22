#include"GameScene.h"
#include"DxLib.h"
#include"Missile.h"
#include"Target.h"

static Missile missile;
static Target target;

GameScene::GameScene()
{
	missile.InitTexture();
	target.InitTexture();
}

GameScene::~GameScene()
{
	missile.ReleaseTexture();
}

void GameScene::Exec()
{
	target.Exec();
	missile.GetPoston(target.PosX, target.PosY);
	missile.Exec();
}

void GameScene::Draw()
{
	target.Draw();
	missile.Draw();
}
