#include "common.h"

void Player::Move()
{
	if (IsKeyHeld(KEY_INPUT_UP))
	{
		pos_y -= 8;
	}
	if (IsKeyHeld(KEY_INPUT_DOWN))
	{
		pos_y += 8;
	}
	if (IsKeyHeld(KEY_INPUT_LEFT))
	{
		pos_x -= 8;
	}
	if (IsKeyHeld(KEY_INPUT_RIGHT))
	{
		pos_x += 8;
	}

}
