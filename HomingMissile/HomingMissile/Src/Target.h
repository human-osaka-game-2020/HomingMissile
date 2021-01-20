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

	//�摜�ۑ��ϐ�
	int Texture;
};

#endif // !TARGET_H

