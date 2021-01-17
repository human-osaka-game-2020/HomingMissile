
#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

class Enemy{
public:
	Enemy();
	~Enemy(){};

	void Exec( Player* target_ );

private:
	void Move( Player* target_ );
	void Draw();

	double x;
	double y;
	double speed;
	double angle;
	double turningPower;

};

#endif // !ENEMY_H
