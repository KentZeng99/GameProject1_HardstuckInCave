#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "cprocessing.h"
#include "easing.h"
#include "Tiles.h"
#include "player.h"
#include "enemy.h"

#define SWAP(type, lhs, rhs) { \
	type temp = lhs; \
	lhs = rhs; \
    rhs = temp; \
}

//Enemy constructor
enemy new_Enemy(CP_Vector pos, float speed, enum enemyType type, enum enemyStates currState, Player *player)
{
	enemy newEnemy;
	newEnemy.enemyPos = pos;
	newEnemy.startPos = pos;
	newEnemy.speed = speed;
	newEnemy.enemyMinX = pos.x;
	newEnemy.enemyMaxX = pos.x + enemyThresholdX;
	newEnemy.type = type;
	newEnemy.currState = currState;
	newEnemy.player = player;
	newEnemy.isCollidingDown = 0;
	newEnemy.isCollidingLeft = 0;
	newEnemy.isCollidingUp = 0;
	newEnemy.isCollidingRight = 0;
	return newEnemy;
}

CP_Vector calculateDampedDisplacement(Player *player, enemy *enemy)
{
	CP_Vector displacement = CP_Vector_Subtract(player->Pos, enemy->enemyPos);
	CP_Vector dampedDisplacement = CP_Vector_Scale(displacement, 0.05f);
	return dampedDisplacement;
}

//Check for collision between player and enemy
//Unused due to mitigated enemies
int checkCollisionPlayer(Player* player, enemy *enemy)
{
	int touchedPlayer = 0;
	//Check for collision on the left
	if ((*player).Pos.x == enemy->enemyPos.x + enemySizeX && enemy->enemyPos.y < (*player).Pos.y + PlayerHeight && (*player).Pos.y < enemy->enemyPos.y + enemySizeY)
	{
		(*player).isCollidingLeft = 1;
		enemy->isCollidingRight = 1;
		touchedPlayer = 1;
	}
	//Check for collision on the right
	if ((*player).Pos.x + PlayerWidth == enemy->enemyPos.x && enemy->enemyPos.y < (*player).Pos.y + PlayerHeight && (*player).Pos.y < enemy->enemyPos.y + enemySizeY)
	{
		(*player).isCollidingRight = 1;
		enemy->isCollidingLeft = 1;
		touchedPlayer = 1;
	}
	//Check for collision on top
	if ((*player).Pos.y == enemy->enemyPos.y + enemySizeY && enemy->enemyPos.x < (*player).Pos.x + PlayerWidth && (*player).Pos.x < enemy->enemyPos.x + enemySizeX)
	{
		(*player).isCollidingUp = 1;
		enemy->isCollidingDown = 1;
		touchedPlayer = 1;
	}
	//Check for collision below
	if (enemy->enemyPos.y == (*player).Pos.y + PlayerHeight && enemy->enemyPos.x < (*player).Pos.x + PlayerWidth && (*player).Pos.x < enemy->enemyPos.x + enemySizeX)
	{
		(*player).isCollidingDown = 1;
		enemy->isCollidingUp = 1;
		touchedPlayer = 1;
	}
	return touchedPlayer;
}

//Check for collision between enemy and tiles
//Unused due to mitiagted enemies
int checkCollisionTile(Tiles* tile, enemy* enemy)
{
	int touchedTile = 0;
	//Check for collision on the left
	if (enemy->enemyPos.x == tile->tPos.x + TileWidth && tile->tPos.y < enemy->enemyPos.y + enemySizeY && enemy->enemyPos.y < tile->tPos.y + TileHeight)
	{
		enemy->isCollidingLeft = 1;
		touchedTile = 1;
	}
	//Check for collision on the right
	if (enemy->enemyPos.x + enemySizeX == tile->tPos.x && tile->tPos.y < enemy->enemyPos.y + enemySizeY && enemy->enemyPos.y < tile->tPos.y + TileHeight)
	{
		enemy->isCollidingRight = 1;
		touchedTile = 1;
	}
	//Check for collision on top
	if (enemy->enemyPos.y == tile->tPos.y + TileHeight && tile->tPos.x < enemy->enemyPos.x + enemySizeX && enemy->enemyPos.x < tile->tPos.x + TileWidth)
	{
		enemy->isCollidingUp = 1;
		touchedTile = 1;
	}
	//Check for collision below
	if (tile->tPos.y == enemy->enemyPos.y + enemySizeY && tile->tPos.x < enemy->enemyPos.x + enemySizeX && enemy->enemyPos.x < tile->tPos.x + TileWidth)
	{
		enemy->isCollidingDown = 1;
		touchedTile = 1;
	}
	return touchedTile;
}
