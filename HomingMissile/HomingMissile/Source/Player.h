
#ifndef PLAYER_H
#define PLAYER_H

class Player{
public:
	Player();
	~Player(){};

	void Exec();

	double GetX() const { return x; }
	double GetY() const { return y; }

private:
	void Move();

	void Draw();

private:
	double x;
	double y;
	double speed;

};

#endif // !PLAYER_H
