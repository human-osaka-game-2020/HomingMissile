
#include "DxLib.h"
#include "Function.h"
#include "Player.h"

Player::Player() :
	x( 100 ),
	y( 100 ),
	speed( 5 )
{

}

void Player::Exec(){
	Move();
	Draw();
}

void Player::Move(){
	float tempX = x;
	float tempY = y;

	if( GetKeyStatus( KEY_INPUT_UP ) == InputState::Pressing ){
		y -= speed;
	}
	else if( GetKeyStatus( KEY_INPUT_DOWN ) == InputState::Pressing ){
		y += speed;
	}

	if( GetKeyStatus( KEY_INPUT_LEFT ) == InputState::Pressing ){
		x -= speed;
	}
	else if( GetKeyStatus( KEY_INPUT_RIGHT ) == InputState::Pressing ){
		x += speed;
	}

	if( x < 0 || y < 0 || x > 1280 || y > 720 ){
		x = tempX;
		y = tempY;
	}
}

void Player::Draw(){
	DrawCircle( x, y, 16, GetColor( 255, 0, 0 ), true );
}
