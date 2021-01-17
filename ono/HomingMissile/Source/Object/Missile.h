
#ifndef MISSILE_H
#define MISSILE_H

class Missile
{
public:
	Missile();
	~Missile();

	void Exec(float x_, float y_);
	void Draw();

	void SetPos(float x_, float y_, float radius_);
	void SetMoveSpeed(float speed_);

	float GetPosX() const;
	float GetPosY() const;
	float GetMoveSpeed() const;
	float GetRadius() const;

private:
	float m_PosX;
	float m_PosY;
	float m_MoveSpeed;
	float m_Radius;
	float m_DistanceX;
	float m_DistanceY;
	float m_Angle;
	float m_Theta;
	float m_Radian;
	float m_HomingSpeed;
};


#endif // !MISSILE_H
