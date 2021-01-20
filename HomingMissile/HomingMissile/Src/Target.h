#ifndef TARGET_H
#define TARGET_H

class Target
{
public:
	Target();
	~Target();
	void Exec();
	void Draw();
	void InitTexture();

public:
	float PosX;
	float PosY;
	float CPosX;
	float CPosY;
	float Angle;
	float Speed;

	//画像保存変数
	int Texture;
};

#endif // !TARGET_H

