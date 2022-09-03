#pragma once
#define PlayerWidth 20
#define PlayerHeight 20
#define InventorySize 5

//Unused due to mitigated production
typedef struct
{
	char name;

}powerups;

typedef struct
{
	int health;
	float speed;
	CP_Vector Pos;
	int playerWidth;
	int playerHeight;
	int isCollidingDown;
	int isCollidingLeft;
	int isCollidingUp;
	int isCollidingRight;
	bool isAlive;
	int inventory[InventorySize];
	powerups currPowerup;

}Player;

Player new_Player(int _health, float _speed, CP_Vector _pos);
