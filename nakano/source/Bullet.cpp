#include "common.h"

Bullet::Bullet()
{
	thetaSpeed = 5.0f;
}

void Bullet::Calculate(float posx_, float posy_)
{
	distanceX = posx_ - pos_x;
	distanceY = (posy_ - pos_y) * -1;
	atanTheta = atan2(distanceY, distanceX) * 180 / M_PI;

	if (atanTheta < 0)
	{
		atanTheta += 360.0f;
	}

	return;
}

void Bullet::Move(float posx_, float posy_)
{
	if (theta > 360.0f)
	{
		theta -= 360.0f;
	}

	if (theta < 0.0f)
	{
		theta += 360.0f;
	}

	Calculate(posx_, posy_);

	if (sqrt(pow(atanTheta - theta, 2.0f)) <= thetaSpeed &&
		sqrt(pow(atanTheta - theta, 2.0f)) >= 0.0f ||
		sqrt(pow(atanTheta - theta, 2.0f)) <= 360.0f &&
		sqrt(pow(atanTheta - theta, 2.0f)) >= 360.0f - thetaSpeed)
	{
		theta = atanTheta;
	}
	else if (atanTheta - theta > thetaSpeed &&
			 atanTheta - theta < 180.0f ||
			 atanTheta - theta <= -180.0f &&
			 atanTheta - theta > -360.0f + thetaSpeed)
	{
		theta += thetaSpeed;
	}
	else if (atanTheta - theta < thetaSpeed &&
			 atanTheta - theta > -180.0f ||
			 atanTheta - theta >= 180.0f &&
			 atanTheta - theta < 360.0f - thetaSpeed)
	{
		theta -= thetaSpeed;
	}

	pos_x += cos(theta / 180.0f * M_PI) * 10.0f;
	pos_y -= sin(theta / 180.0f * M_PI) * 10.0f;
	
	return;
}
