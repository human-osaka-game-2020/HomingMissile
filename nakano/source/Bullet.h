#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
	Bullet();

	void Move(float posx_, float posy_);

	void SetPos(int X, int Y) { pos_x = X; pos_y = Y; };
	void SetTheta(double theta_) { theta = theta_; };

	int GetPosX() const { return pos_x; };
	int GetPosY() const { return pos_y; };
	double GetTheta() const { return theta; };

private:
	//引数でもらった座標に対しての角度の算出
	void Calculate(float posx_, float posy_);

private:
	int pos_x;
	int pos_y;

	float distanceX;
	float distanceY;
	double atanTheta;

	double theta;
	//1フレームで回転できる角度の最大値
	double thetaSpeed;
};


#endif // !BULLET_H
