#include "Missile.h"
#include "DxLib.h"
#include <math.h>

const float PI = 3.14;

Missile::Missile()
	:m_PosX(0.0f)
	,m_PosY(0.0f)
	,m_MoveSpeed(0.0f)
	,m_Radius(0.0f)
	,m_DistanceX(0.0f)
	,m_DistanceY(0.0f)
	,m_Angle(0.0f)
	,m_Theta(0.0f)
	,m_Radian(0.0f)
	,m_HomingSpeed(2.0f)
{
}

Missile::~Missile()
{
}

void Missile::Exec(float x_, float y_)
{
	if (m_Theta < 0.0f)
	{
		m_Theta += 360.0f;
	}
	if (m_Theta > 360.0f)
	{
		m_Theta -= 360.0f;
	}

	if (m_Angle < 0)
	{
		m_Angle += 360.0f;
	}

	if ((m_Angle - m_Theta <= m_HomingSpeed && m_Angle - m_Theta >= 0.0f) ||
		(m_Angle - m_Theta <= 360.0f && m_Angle - m_Theta >= 360.0f - m_HomingSpeed))
	{
		m_Theta = m_Angle;
	}
	else if ((m_Angle - m_Theta > m_HomingSpeed && m_Angle - m_Theta < 180.0f) ||
			 (m_Angle - m_Theta <= -180.0f && m_Angle - m_Theta > -360.0f + m_HomingSpeed))
	{
		m_Theta += m_HomingSpeed;
	}
	else if ((m_Angle - m_Theta < m_HomingSpeed && m_Angle - m_Theta > -180.0f) ||
			 (m_Angle - m_Theta >= 180.0f && m_Angle - m_Theta < 360.0f - m_HomingSpeed))
	{
		m_Theta -= m_HomingSpeed;
	}

	m_DistanceX = x_ - m_PosX;
	m_DistanceY = (y_ - m_PosY) * -1;
	m_Angle = atan2(m_DistanceY, m_DistanceX) * 180 / PI;

	m_Radian = m_Theta / 180.0f * PI;

	m_PosX += cosf(m_Radian) * 10.0f;
	m_PosY -= sinf(m_Radian) * 10.0f;
}

void Missile::Draw()
{
	DrawCircle(m_PosX, m_PosY, m_Radius, GetColor(0, 0, 0), TRUE);
}

void Missile::SetPos(float x_, float y_, float radius_)
{
	m_PosX = x_;
	m_PosY = y_;
	m_Radius = radius_;
}

void Missile::SetMoveSpeed(float speed_)
{
	m_MoveSpeed = speed_;
}

float Missile::GetPosX() const
{
	return m_PosX;
}

float Missile::GetPosY() const
{
	return m_PosY;
}

float Missile::GetMoveSpeed() const
{
	return m_MoveSpeed;
}

float Missile::GetRadius() const
{
	return m_Radius;
}
