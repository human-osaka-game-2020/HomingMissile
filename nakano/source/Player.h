#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	void Move();
	void SetPos(int X, int Y) { pos_x = X; pos_y = Y; };

	int GetPosX() const { return pos_x; };
	int GetPosY() const { return pos_y; };

private:
	int pos_x;
	int pos_y;
};

#endif // !PLAYER_H

