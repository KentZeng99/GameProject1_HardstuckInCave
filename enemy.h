#pragma once
#define numOfEnemies 4
#define enemySpeed 90
#define enemySizeX 40
#define enemySizeY 40
#define enemyThresholdX 200
#define enemyThresholdY 200

//Enemy states
enum enemyStates
{
	idle,
	patrolling,
	hunting
};

//Unused due to mitigated enemies
enum enemyType
{
	fast,
	neutral,
	mining
};

typedef struct
{
	CP_Vector enemyPos;
	CP_Vector startPos;
	float speed;
	float enemyMinX;
	float enemyMaxX;
	Player *player;
	enum enemyType type;
	enum enemyStates currState;
	int isCollidingDown;
	int isCollidingLeft;
	int isCollidingUp;
	int isCollidingRight;

}enemy;

enemy enemyArray[numOfEnemies];
enemy new_Enemy(CP_Vector pos, float speed, enum enemyType type, enum enemyStates currState, Player* player);

CP_Vector calculateDampedDisplacement(Player *player, enemy *enemy);
int checkCollisionPlayer(Player *player, enemy* enemy);
int checkCollisionTile(Tiles *tile, enemy* enemy);
