
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw();

	void SetPos(float x_, float y_);
	void SetMoveSpeed(float speed_);

	float GetPosX() const;
	float GetPosY() const;
	float GetMoveSpeed() const;

private:
	float m_PosX;
	float m_PosY;
	float m_MoveSpeed;
};

#endif // !PLAYER_H
