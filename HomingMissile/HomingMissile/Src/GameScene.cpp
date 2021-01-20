#include"GameScene.h"
#include"DxLib.h"
#include"Missile.h"
#include"Target.h"

static Missile missile;
static Target target;

GsmeScene::GsmeScene()
{
	missile.InitTexture();
	target.InitTexture();
}

GsmeScene::~GsmeScene()
{
	missile.ReleaseTexture();
}

void GsmeScene::Exec()
{
	target.Exec();
	missile.GetPoston(target.PosX, target.PosY);
	missile.Exec();
}

void GsmeScene::Draw()
{
	target.Draw();
	missile.Draw();
}
