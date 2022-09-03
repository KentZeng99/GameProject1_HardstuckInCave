#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cprocessing.h"
#include "player.h"

//Constructor for player obj
Player new_Player(int _health, float _speed, CP_Vector _pos)
{
	Player player;
	player.health = _health;
	player.speed = _speed;
	player.Pos = _pos;
	player.playerWidth = PlayerWidth;
	player.playerHeight = PlayerHeight;
	player.isAlive = true;

	//Initialise array to zero for all elements
	for (int i = 0; i < InventorySize; i++)
	{
		player.inventory[i] = 0;
	}
	return player;
}