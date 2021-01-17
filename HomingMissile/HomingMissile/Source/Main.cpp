
#include "DxLib.h"
#include "Function.h"
#include "Player.h"
#include "Enemy.h"

Player player;
Enemy enemy;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ){
	SetOutApplicationLogValidFlag( false );
	SetGraphMode( 1280, 720, 32 );
	ChangeWindowMode( true );
	SetBackgroundColor( 255, 255, 255 );

	if( DxLib_Init() == -1 ) return -1;

	SetDrawScreen( DX_SCREEN_BACK );

	while( true )
	{
		ClearDrawScreen();

		if( UpdateKeyState() != 0 ) break;

		// ----------------

		player.Exec();
		enemy.Exec( &player );

		// ----------------

		if( ProcessMessage() < 0 ) break;
		if( CheckHitKey( KEY_INPUT_ESCAPE ) ) break;

		ScreenFlip();
	}

	DxLib_End();

	return 0;
}
