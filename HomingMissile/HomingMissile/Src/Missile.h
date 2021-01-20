#ifndef MISSILE_H
#define MISSILE_H

class Missile
{
public:
	Missile();
	~Missile();
	void Exec();
	void Draw();
	void InitTexture();
	void ReleaseTexture();
	void GetPoston(float x_, float y_);
	void CrossProduct();
	void InnerProduct();
private:
	float PosX;
	float PosY;
	float CPosX;
	float CPosY;
	float Angle;
	float Speed;
	float TargetPosX;
	float TargetPosY;
	float Radian;
	//‰æ‘œ•Û‘¶•Ï”
	int Texture;
	
};

#endif // !MISSILE_H

