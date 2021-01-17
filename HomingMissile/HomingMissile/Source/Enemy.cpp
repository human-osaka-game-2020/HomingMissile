
#include <math.h>

#include "DxLib.h"
#include "Function.h"
#include "Enemy.h"

double PI = 3.14;

Enemy::Enemy() :
	x( 1000 ),
	y( 500 ),
	speed( 3 ),
	angle( 0 ),
	turningPower( 10 )
{

}

void Enemy::Exec( Player* target_ ){
	Move( target_ );
	Draw();
}

void Enemy::Move( Player* target_ ){
	// 現在の進行方向
	double currentAngleX = cos( angle );
	double currentAngleY = sin( angle );

	// 行き先
	double destinationX = target_->GetX() - x;
	double destinationY = target_->GetY() - y;

	angle += ( destinationX * currentAngleY - destinationY * currentAngleX < 0.0 ) ? PI / 180 * turningPower : -PI / 180 * turningPower;

	// 移動
	x += cos( angle ) * speed;
	y += sin( angle ) * speed;
}

void Enemy::Draw(){
	DrawCircle( x, y, 16, GetColor( 0, 255, 255 ), true );
}
