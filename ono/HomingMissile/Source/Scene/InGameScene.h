
#ifndef INGAME_SCENE_H
#define INGAME_SCENE_H

const int MissileMax = 5;

class InGameScene
{
public:
	InGameScene();
	~InGameScene();

	void Exec();
	void Draw();
};

#endif // !INGAME_SCENE_H
