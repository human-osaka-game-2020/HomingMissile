
#include "Player.h"
#include "DxLib.h"
#include "../Function/Input.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Update()
{
	if (UpdateKeyState() != 0) return;

	if (GetKeyStatus(KEY_INPUT_LEFT) == InputState::Hold)
	{
		m_PosX -= m_MoveSpeed;
	}
	else if (GetKeyStatus(KEY_INPUT_RIGHT) == InputState::Hold)
	{
		m_PosX += m_MoveSpeed;
	}
	else if (GetKeyStatus(KEY_INPUT_UP) == InputState::Hold)
	{
		m_PosY -= m_MoveSpeed;
	}
	else if (GetKeyStatus(KEY_INPUT_DOWN) == InputState::Hold)
	{
		m_PosY += m_MoveSpeed;
	}
}

void Player::Draw()
{
	DrawBox(m_PosX, m_PosY, m_PosX + 64, m_PosY + 64, GetColor(180, 0, 255), TRUE);
}

void Player::SetPos(float x_, float y_)
{
	m_PosX = x_;
	m_PosY = y_;
}

void Player::SetMoveSpeed(float speed_)
{
	m_MoveSpeed = speed_;
}

float Player::GetPosX() const
{
	return m_PosX;
}

float Player::GetPosY() const
{
	return m_PosY;
}

float Player::GetMoveSpeed() const
{
	return m_MoveSpeed;
}
