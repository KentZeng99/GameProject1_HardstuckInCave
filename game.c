#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "easing.h"
#include "cprocessing.h"
#include "level.h"
#include "player.h"
#include "Tiles.h"
#include "enemy.h"

#define COLOR_RED CP_Color_Create(255, 0, 0, 255)
#define COLOR_GREEN CP_Color_Create(0, 255, 0, 255)
#define COLOR_BLUE CP_Color_Create(0, 0, 255, 255)
#define COLOR_CYAN CP_Color_Create(0,255,255,255)
#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

#define SWAP(type, lhs, rhs) { \
	type temp = lhs; \
	lhs = rhs; \
    rhs = temp; \
}

CP_Image playerSprite;
CP_Image dirtSprite;
CP_Image stoneSprite;
CP_Image healthSprite1;
CP_Image healthSprite2;
CP_Image healthSprite3;
CP_Image inventorySprite;
CP_Image inventoryblock1;
CP_Image inventoryblock2;
CP_Image inventoryblock3;
CP_Image inventoryblock4;
CP_Image inventoryblock5;
CP_Image bag;
CP_Image loseScreen;
CP_Image winScreen;
CP_Image gemSprite;
CP_Image ghostSprite;
CP_Image tutScreenSprite;
CP_Image backstorySprite;
CP_Image playerskins[3];
CP_Image mutedSprite;

float spriteDegrees;
float startX, startY;
float mousePosX, mousePosY;
float selectorPosX, selectorPosY;
bool colorSet;
int tileTypeCount;      //Cycle thru the tile types
CP_Vector mousePos;
float mouseDiffplayer;
Tiles* selectedTile;    //Pointer
Tiles* currPlayerTile;  //Pointer
Tiles* closestGemTile;  //Pointer
float gemTileDist;
float currGemTileDist;

int alt;
int levelCounter;
int playercounter;
int gems;
int totalGems;
char gemBuffer[3] = { 0 };
char totalGemBuffer[3] = { 0 };

Player dood;    //Player
Player* pdood;  //Pointer
float damageTimer;
float invulDuration;
bool damaged;
bool pingGemTile;
bool pingEnemy;
bool startCooldown;
float pingTimer;
float pingDuration;
float pingcoolDown;
char coolDownBuffer[4] = { 0 };
int clickCount;

enemy Worm;    //Enemy
enemy* pWorm;   //Pointer
CP_Vector direction;
int behaviourSeed;
float enemyMinX, enemyMaxX;
float idleTimer;
float idleDuration;
float timer;
float chaseTimer;
float chaseDuration;
float duration;
float minX;
float maxX;

float screenTimer;
float screenDuration;
float centerScreenX;
float centerScreenY;
bool win;
bool showInsuffScreen;
bool showbackstoryscreen;

CP_Sound BGM = NULL;
CP_Sound Dirt = NULL;
CP_Sound Dirt2 = NULL;
CP_Sound Stone = NULL;
CP_Sound Stone2 = NULL;
CP_Sound PlaceDirt = NULL;
CP_Sound PlaceStone = NULL;
CP_Sound Oof = NULL;
bool mute;

int inventorystate;

//Foward declaration
void mainmenu_init(void);
void mainmenu_update(void);
void mainmenu_exit(void);

void checkCollision(Player* player, Tiles tile);
int internalCollision(Player player, Tiles tile);
int checkMouseCollision(float mouseX, float mouseY, float _x, float _y, int _width, int _height);
void saveLevel(int currLevel, int dstLevel);

void game_init(void)
{
    BGM = CP_Sound_Load("./Assets/ANCIENT_RUINS_NewAge_MSCNEW2_34.wav");
    Dirt = CP_Sound_Load("./Assets/SHOVEL-METAL_GEN-HDF-21102.wav");
    Dirt2 = CP_Sound_Load("./Assets/BAG-SAND_GEN-HDF-02863.wav");
    Stone = CP_Sound_Load("./Assets/BODYFALL-DIRT_GEN-HDF-04271.wav");
    Stone2 = CP_Sound_Load("./Assets/ROCK-FALL_GEN-HDF-20046.wav");
    PlaceDirt = CP_Sound_Load("./Assets/BAG-SAND_GEN-HDF-02864.wav");
    PlaceStone = CP_Sound_Load("./Assets/ROCK-FALL_GEN-HDF-20041.wav");
    Oof = CP_Sound_Load("./Assets/HUMAN-GRUNT_GEN-HDF-15085.wav");
    playerSprite = CP_Image_Load("./Assets/Avatar.png");
    dirtSprite = CP_Image_Load("./Assets/dirt.png");
    stoneSprite = CP_Image_Load("./Assets/stone.png");
    healthSprite1 = CP_Image_Load("./Assets/heart.png");
    healthSprite2 = CP_Image_Load("./Assets/heart.png");
    healthSprite3 = CP_Image_Load("./Assets/heart.png");
    inventorySprite = CP_Image_Load("./Assets/Inventory.png");
    inventoryblock1 = CP_Image_Load("./Assets/stone.png");
    inventoryblock2 = CP_Image_Load("./Assets/stone.png");
    inventoryblock3 = CP_Image_Load("./Assets/stone.png");
    inventoryblock4 = CP_Image_Load("./Assets/stone.png");
    inventoryblock5 = CP_Image_Load("./Assets/stone.png");
    bag = CP_Image_Load("./Assets/Bag.png");
    loseScreen = CP_Image_Load("./Assets/defeatscreen.png");
    winScreen = CP_Image_Load("./Assets/win_screen_placeholder.png");
    gemSprite = CP_Image_Load("./Assets/gem1.png");
    ghostSprite = CP_Image_Load("./Assets/EnemyGameForm.png");
    backstorySprite = CP_Image_Load("./Assets/Backstory_screen.png");
    tutScreenSprite = CP_Image_Load("./Assets/Tutorial_screen.png");
    playerskins[0] = CP_Image_Load("./Assets/Avatar1.png");
    playerskins[1] = CP_Image_Load("./Assets/Avatar2.png");
    playerskins[2] = CP_Image_Load("./Assets/Avatar3.png");
    mutedSprite = CP_Image_Load("./Assets/muted.png");

    spriteDegrees = 0;

    startX = 200;
    startY = 100;

    colorSet = false;
    tileTypeCount = 0;
    gems = 0;
    totalGems = 0;
    gemTileDist = 9999.f;   //Super high to detect the closest gem tile

    //3 HP, 10 speed multiplier
    dood = new_Player(3, 10, CP_Vector_Set(startX, startY));   //Player struct
    pdood = &dood;
    damageTimer = 0.f;
    invulDuration = 3.f;
    damaged = false;
    pingGemTile = false;
    pingEnemy = false;
    startCooldown = false;
    pingTimer = 0.f;
    pingDuration = 5.f;     //ping last for 5 seconds
    pingcoolDown = 3.5f;     //8 seconds cooldown
    clickCount = 0;
    alt = 0;
    mouseDiffplayer = 0;

    Worm = new_Enemy(CP_Vector_Set(800, 600), enemySpeed, neutral, patrolling, pdood);
    pWorm = &Worm;
    enemyMinX = pWorm->startPos.x;
    enemyMaxX = pWorm->startPos.x + enemyThresholdX;
    direction = CP_Vector_Set(0.f, 0.f);
    behaviourSeed = 0;
    //Add enemies into array
    enemyArray[0] = Worm;
    idleTimer = 0.f;
    idleDuration = 4.f;
    timer = 0.f;
    chaseTimer = 0.f;
    chaseDuration = 3.5f;
    duration = 2.f;
    minX = 0.f;
    maxX = 255.f;

    screenTimer = 0.f;
    screenDuration = 1.1f;
    centerScreenX = (float)(CP_System_GetWindowWidth() / 2);
    centerScreenY = (float)(CP_System_GetWindowHeight() / 2);

    win = false;
    showInsuffScreen = false;
    showbackstoryscreen = true;

    CP_Sound_StopAll();
    CP_Sound_PlayAdvanced(BGM, 1.0f, 1.0f, TRUE, CP_SOUND_GROUP_2);

    //CP_System_SetWindowSize(1366, 768);
    CP_System_Fullscreen();
    CP_System_SetWindowTitle("Hardstuck in cave");

    //Create new tiles and add them into array
    for (int rows = 0; rows < numOfTilesX; rows++)
    {
        for (int cols = 0; cols < numOfTilesY; cols++)
        {
            //For all borders set active
            if (rows == 0 || rows == numOfTilesX - 1 || cols == 0 || cols == numOfTilesY - 1)
            {
                //Set to bedrock
                tileSet[levelCounter][rows][cols] = new_Tile((float)(rows * TileWidth), (float)(cols * TileHeight), TileWidth, TileHeight, 1, 3);
            }
            else if (rows == 1 || rows == numOfTilesX - 2 || cols == 1 || cols == numOfTilesY - 2)
            {
                //Set to dirt
                tileSet[levelCounter][rows][cols] = new_Tile((float)(rows * TileWidth), (float)(cols * TileHeight), TileWidth, TileHeight, 1, 1);
            }
            else
            {
                tileSet[levelCounter][rows][cols] = new_Tile((float)(rows * TileWidth), (float)(cols * TileHeight), TileWidth, TileHeight, 0, 1);
            }
        }
    }

    setGameLevel(levelCounter);
    //Loop to generate some gems in stone blocks for player to mine
    for (int rows = 0; rows < numOfTilesX; rows++)
    {
        for (int cols = 0; cols < numOfTilesY; cols++)
        {
            if (tileSet[levelCounter][rows][cols].type == 2)
            {
                int randGemSeed = CP_Random_RangeInt(0, 100);
                if (randGemSeed >= 0 && randGemSeed < 4)    //4% chance of gem tile
                {
                    tileSet[levelCounter][rows][cols].hasGem = true;
                    if (CP_Vector_Distance(tileSet[levelCounter][rows][cols].tPos, pdood->Pos) < gemTileDist)
                    {
                        closestGemTile = &tileSet[levelCounter][rows][cols];
                        gemTileDist = CP_Vector_Distance(tileSet[levelCounter][rows][cols].tPos, pdood->Pos);
                    }
                    totalGems++;
                }
            }
        }
    }
    if (totalGems != 0)
    {
        currGemTileDist = CP_Vector_Distance(closestGemTile->tPos, pdood->Pos);
    }
    sprintf_s(totalGemBuffer, _countof(totalGemBuffer), "%i", totalGems);
}

void game_update(void)
{
    //mute audio
    if (mute) {
        CP_Sound_PauseAll();
    }
    else {
        CP_Sound_ResumeAll();
    }

    mousePosX = CP_Input_GetMouseX();
    mousePosY = CP_Input_GetMouseY();
    mousePos = CP_Vector_Set(mousePosX, mousePosY);
    mouseDiffplayer = CP_Vector_Distance(dood.Pos, mousePos);

    CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
    CP_Settings_Stroke(CP_Color_Create(41, 41, 41, 255));

    //Sets collision for enemy to be zero at the start of every frame
    Worm.isCollidingDown = 0;
    Worm.isCollidingLeft = 0;
    Worm.isCollidingRight = 0;
    Worm.isCollidingUp = 0;

    //Sets collision for player to be zero at the start of every frame
    dood.isCollidingUp = 0;
    dood.isCollidingDown = 0;
    dood.isCollidingLeft = 0;
    dood.isCollidingRight = 0;

    //Collision check between all active tiles and the player
    //And additional stuff
    for (int x = 0; x < numOfTilesX; x++)
    {
        for (int y = 0; y < numOfTilesY; y++)
        {
            if (tileSet[levelCounter][x][y].isOn == 1)
            {
                checkCollision(pdood, tileSet[levelCounter][x][y]);   
                if (tileSet[levelCounter][x][y].hasGem)               //Find the closest tile that contains a gem
                {
                    gemTileDist = CP_Vector_Distance(tileSet[levelCounter][x][y].tPos, pdood->Pos);
                    currGemTileDist = CP_Vector_Distance(closestGemTile->tPos, pdood->Pos);
                    if (gemTileDist < currGemTileDist)
                    {
                        closestGemTile = &tileSet[levelCounter][x][y];  //Store in pointer
                    }
                }
            }
            if (checkMouseCollision(mousePosX, mousePosY, tileSet[levelCounter][x][y].x, tileSet[levelCounter][x][y].y, TileWidth, TileHeight))
            {
                //Sets selector render position
                selectorPosX = tileSet[levelCounter][x][y].x;
                selectorPosY = tileSet[levelCounter][x][y].y;
                selectedTile = &tileSet[levelCounter][x][y];  //Sets pointer to point to address of selected tile
                if (tileSet[levelCounter][x][y].isOn == 1)
                {
                    colorSet = true;
                }
                else
                {
                    colorSet = false;
                }
            }
            if (internalCollision(dood, tileSet[levelCounter][x][y]))
            {
                //Sets current tile the player is on
                currPlayerTile = &tileSet[levelCounter][x][y];
            }
        }
    }

    //Cycle inventory
    if (CP_Input_KeyTriggered('Q'))
    {
        tileTypeCount++;
        if (tileTypeCount >= 2)
        {
            tileTypeCount = 0;
        }
    }

    //Ping enemy
    if (CP_Input_KeyTriggered('R'))
    {
        if (!startCooldown && !pingGemTile)
        {
            pingEnemy = true;
        }
    }
    //Ping closest gem tile
    else if (CP_Input_KeyTriggered('E'))
    {
        if (!startCooldown && !pingEnemy)
        {
            pingGemTile = true;
        }
    }
    if (pingEnemy)
    {
        pingTimer += CP_System_GetDt();
        if (pingTimer >= pingDuration)
        {
            pingEnemy = false;
            startCooldown = true;
            pingTimer = 0.f;
        }
    }

    //Cooldown for scans
    if (pingGemTile)
    {
        pingTimer += CP_System_GetDt();
        if (pingTimer >= pingDuration)
        {
            pingGemTile = false;
            startCooldown = true;
            pingTimer = 0.f;
        }
    }
    if (startCooldown)
    {
        pingcoolDown -= CP_System_GetDt();
        sprintf_s(coolDownBuffer, _countof(coolDownBuffer), "%i", (int)pingcoolDown);
        if (pingcoolDown <= 0)
        {
            pingcoolDown = 3.5f;
            startCooldown = false;
        }
    }

    //Mouseclick detection
    if (CP_Input_MouseClicked())
    {
        if (checkMouseCollision(mousePosX, mousePosY, 5.f, 300.f, 250, 45) && CP_Input_KeyDown(KEY_ESCAPE)) //Quit button in help menu
        {
            CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
        }
        if (checkMouseCollision(mousePosX, mousePosY, centerScreenX + 400, centerScreenY + 100, 50, 50))
        {
            showbackstoryscreen = false;
        }
        if (checkMouseCollision(mousePosX, mousePosY, centerScreenX - 400, centerScreenY + 150, 400, 50))   //Quit game when win
        {
            CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
        }
        if (checkMouseCollision(mousePosX, mousePosY, centerScreenX + 200, centerScreenY + 150, 250, 45))     //Restart game when win
        {
            CP_Engine_SetNextGameState(game_init, game_update, NULL);
        }
        if (checkMouseCollision(mousePosX, mousePosY, 500, 510, 250, 45) && !pdood->isAlive) //Quit game when lose
        {
            CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
        }
        if (checkMouseCollision(mousePosX, mousePosY, 500, 470, 250, 45) && !pdood->isAlive) //Restart game
        {
            CP_Engine_SetNextGameState(game_init, game_update, NULL);
        }
        //Check if mouse is clicking on the selected tile and the player is not on the selected tile
        if (selectedTile != currPlayerTile && mouseDiffplayer < 55.f && pdood->isAlive)   //range of 55.f from mouse to player
        {
            //If selected tile is on then set to off, else set to on
            if ((*selectedTile).isOn)
            {
                clickCount++;
                if ((*selectedTile).type == 1)
                {
                    CP_Sound_Play(Dirt);
                    if (clickCount == 3 && pdood->inventory[0] != 5)    //Takes 3 hits to remove dirt block && player inventory is not full
                    {
                        CP_Sound_Play(Dirt2);
                        (*selectedTile).isOn = 0;
                        if (pdood->inventory[0] < 5)    //Only add block if not more than 5 == only can store 5 blocks
                        {
                            pdood->inventory[0]++;  //Player inventory at slot 0 increase for each dirt block mined
                        }
                        clickCount = 0;     //Reset click count
                    }
                }
                else if ((*selectedTile).type == 2)
                {
                    CP_Sound_Play(Stone);
                    if (clickCount == 6 && pdood->inventory[1] != 5)    //Takes 6 hits to remove stone block && player inventory is not full
                    {
                        CP_Sound_Play(Stone2);
                        (*selectedTile).isOn = 0;
                        if (pdood->inventory[1] < 5)    //Only add block if not more than 5 == only can store 5 blocks
                        {
                            pdood->inventory[1]++;  //Player inventory at slot 1 increase for each stone block mined
                            if ((*selectedTile).hasGem) //If mined block contains gem, increment gems
                            {
                                gems++;
                            }
                        }
                        clickCount = 0;     //Reset click count
                    }
                }
                else if ((*selectedTile).type == 4 && gems == totalGems)    //Win condition is here
                {
                    win = true;
                    clickCount = 0;
                }
                else if ((*selectedTile).type == 4 && gems != totalGems)
                {
                    showInsuffScreen = true;
                }
                else
                {
                    clickCount = 0;
                }
            }
            else
            {
                if (pdood->inventory[tileTypeCount] != 0)   //Check if amount of blocks is not empty
                {
                    if (tileTypeCount == 0)
                    {
                        (*selectedTile).type = 1;           //inventory[0] stores int number of dirt blocks
                        CP_Sound_Play(PlaceDirt);
                    }
                    else if (tileTypeCount == 1)
                    {
                        (*selectedTile).type = 2;           //inventory[1] stores int number of stone blocks
                        CP_Sound_Play(PlaceStone);
                    }
                    (*selectedTile).isOn = 1;               //"Place block" by setting it to on
                    pdood->inventory[tileTypeCount]--;      //Minus count after placing one block
                    clickCount = 0;                         //Reset click count
                }
            }
        }
    }

    if (damaged)
    {
        damageTimer += CP_System_GetDt();       //So player cannot take damage repeatedly
        if (damageTimer >= invulDuration)
        {
            damageTimer = 0.f;                  //Reset damage timer
            damaged = false;
        }
    }

    //Only start when player closes tutorial screen
    if (showbackstoryscreen)
    {
        pWorm->currState = idle;
    }

    //Chase if close range
    if (CP_Vector_Distance(pdood->Pos, pWorm->enemyPos) < 100)
    {
        pWorm->currState = hunting;
    }

    //Switch enemy states
    if (pWorm->currState == idle)
    {
        idleTimer += CP_System_GetDt();
        if (idleTimer >= idleDuration)
        {
            pWorm->currState = patrolling;
            idleTimer = 0.f;
        }
    }
    //State machine for enemy
    else if (pWorm->currState == patrolling)
    {
        //move randomly

        idleTimer += CP_System_GetDt();
        if (idleTimer >= idleDuration)
        {
            direction = CP_Vector_Set(CP_Random_RangeFloat(-1.f, 1.f), CP_Random_RangeFloat(-1.f, 1.f));
            behaviourSeed = CP_Random_RangeInt(0, 100);
            if (behaviourSeed >= 0 && behaviourSeed < 30)   //30% chance to go idle state
            {
                pWorm->currState = idle;
            }
            else if (behaviourSeed >= 30 && behaviourSeed < 35) //5% chance to go hunting state
            {
                pWorm->currState = hunting;
            }
            idleTimer = 0.f;
        }
        CP_Vector_Normalize(direction);
        CP_Vector velocity = CP_Vector_Scale(direction, pWorm->speed * CP_System_GetDt());
        pWorm->enemyPos = CP_Vector_Add(pWorm->enemyPos, velocity);
        //So ghost dont go out of bounds
        pWorm->enemyPos.x = CP_Math_ClampFloat(pWorm->enemyPos.x, 30, CP_System_GetDisplayWidth() - 30.f);
        pWorm->enemyPos.y = CP_Math_ClampFloat(pWorm->enemyPos.y, 30, CP_System_GetDisplayHeight() - 30.f);
    }
    else if (pWorm->currState == hunting)
    {
        chaseTimer += CP_System_GetDt();
        if (chaseTimer >= chaseDuration)
        {
            pWorm->currState = idle;
            chaseTimer = 0.f;
        }
        pWorm->enemyPos = CP_Vector_Add(pWorm->enemyPos, calculateDampedDisplacement(pdood, pWorm));
    }

    for (int i = 0; i < numOfEnemies; i++)
    {
        //enemyMovement(pdood, (enemyArray + i), timer, duration, chaseTimer, chaseDuration);
        //Deal 1 point of damage if enemy is 10.f away from player
        if (CP_Vector_Distance(pdood->Pos, pWorm->enemyPos) < 10.f)
        {
            if (dood.health != 0 && !damaged && !win)
            {
                //Minus 1 heart, 2 hearts left
                dood.health--;
                CP_Sound_Play(Oof);
                damaged = true;
                if (dood.health == 2) {
                    healthSprite3 = NULL;
                }
                //Minus 1 heart, 1 heart left
                if (dood.health == 1) {
                    healthSprite2 = NULL;
                }
                //At health 0, Game ends.
                if (dood.health == 0) {
                    healthSprite1 = NULL;
                    pdood->isAlive = false;
                    //CP_Engine_Terminate();
                }
            }
        }
    }

    //Movement is here
    //Can only move once tutorial screen is off
    if (pdood->isAlive && !showbackstoryscreen)
    {
        if (CP_Input_KeyDown('W'))
        {
            if (dood.isCollidingUp == 0)
            {
                //direction.y += -1.f;
                dood.Pos.y -= 1 * dood.speed;
            }
            spriteDegrees = 0;
        }
        else if (CP_Input_KeyDown('A'))
        {
            if (dood.isCollidingLeft == 0)
            {
                //direction.x += -1.f;
                dood.Pos.x -= 1 * dood.speed;
            }
            spriteDegrees = 270;
        }
        else if (CP_Input_KeyDown('S'))
        {
            if (dood.isCollidingDown == 0)
            {
                //direction.y += 1.f;
                dood.Pos.y += 1 * dood.speed;
            }
            spriteDegrees = 180;
        }
        else if (CP_Input_KeyDown('D'))
        {
            if (dood.isCollidingRight == 0)
            {
                //direction.x += 1.f;
                dood.Pos.x += 1 * dood.speed;
            }
            spriteDegrees = 90;
        }
    }

    //Clear background before rendering
    CP_Graphics_ClearBackground(CP_Color_Create(50, 50, 50, 255));
    //Render map, set color depending on activity
    for (int rows = 0; rows < numOfTilesX; rows++)
    {
        for (int cols = 0; cols < numOfTilesY; cols++)
        {
            if (tileSet[levelCounter][rows][cols].isOn == 1)
            {
                CP_Settings_StrokeWeight((float)0.8);
                if (tileSet[levelCounter][rows][cols].type == 0)  //Start point color
                {
                    CP_Settings_Fill(COLOR_CYAN);
                    CP_Graphics_DrawRect(tileSet[levelCounter][rows][cols].x, tileSet[levelCounter][rows][cols].y, tileSet[levelCounter][rows][cols].tileWidth, tileSet[levelCounter][rows][cols].tileHeight);
                }
                if (tileSet[levelCounter][rows][cols].type == 1)  //Dirt Sprite
                {
                    //CP_Settings_Fill(CP_Color_Create(61, 41, 22, 255));
                    CP_Image_Draw(dirtSprite, tileSet[levelCounter][rows][cols].x + 15, tileSet[levelCounter][rows][cols].y + 15, tileSet[levelCounter][rows][cols].tileWidth, tileSet[levelCounter][rows][cols].tileHeight, 255);
                }
                else if (tileSet[levelCounter][rows][cols].type == 2) //Stone sprite
                {
                    //CP_Settings_Fill(CP_Color_Create(113, 108, 100, 255));
                    CP_Image_Draw(stoneSprite, tileSet[levelCounter][rows][cols].x + 15, tileSet[levelCounter][rows][cols].y + 15, tileSet[levelCounter][rows][cols].tileWidth, tileSet[levelCounter][rows][cols].tileHeight, 255);
                }
                else if (tileSet[levelCounter][rows][cols].type == 3) //Bedrock color
                {
                    CP_Settings_Fill(CP_Color_Create(30, 27, 24, 255));
                    CP_Graphics_DrawRect(tileSet[levelCounter][rows][cols].x, tileSet[levelCounter][rows][cols].y, tileSet[levelCounter][rows][cols].tileWidth, tileSet[levelCounter][rows][cols].tileHeight);
                }
                else if (tileSet[levelCounter][rows][cols].type == 4) //End point color
                {
                    CP_Settings_Fill(COLOR_RED);
                    CP_Graphics_DrawRect(tileSet[levelCounter][rows][cols].x, tileSet[levelCounter][rows][cols].y, tileSet[levelCounter][rows][cols].tileWidth, tileSet[levelCounter][rows][cols].tileHeight);
                }
                if (tileSet[levelCounter][rows][cols].hasGem)
                {
                    //CP_Image_Draw(gemSprite, tileSet[levelCounter][rows][cols].x + 15, tileSet[levelCounter][rows][cols].y + 15, tileSet[levelCounter][rows][cols].tileWidth - 15, tileSet[levelCounter][rows][cols].tileHeight - 15, 255);
                }
            }
            else
            {
                CP_Settings_StrokeWeight((float)0.2);
                CP_Settings_Fill(CP_Color_Create(68, 68, 68, 140));
                CP_Graphics_DrawRect(tileSet[levelCounter][rows][cols].x, tileSet[levelCounter][rows][cols].y, tileSet[levelCounter][rows][cols].tileWidth, tileSet[levelCounter][rows][cols].tileHeight);
            }
        }
    }

    //Color is here lol
    CP_Settings_StrokeWeight((float)1);
    if (dood.isCollidingUp || dood.isCollidingDown || dood.isCollidingLeft || dood.isCollidingRight)
    {
        CP_Settings_Fill(CP_Color_Create(0, 200, 89, 255));
    }
    else
    {
        CP_Settings_Fill(CP_Color_Create(89, 89, 89, 255));
    }
    //Render player with HP bar
    CP_Graphics_DrawRect(dood.Pos.x, dood.Pos.y, PlayerWidth, PlayerHeight);
    CP_Image_DrawAdvanced(playerskins[playercounter], dood.Pos.x + (PlayerWidth / 2), dood.Pos.y + (PlayerHeight / 2), 50, 50, 255, spriteDegrees);
    if (pWorm->currState == hunting)
    {
        CP_Settings_TextSize(60);
        CP_Settings_Fill(COLOR_RED);
        CP_Font_DrawText("!", dood.Pos.x - 10, dood.Pos.y);
    }
    if (damaged)    //Show smth when damaged
    {
        CP_Settings_Fill(CP_Color_Create(250, 0, 0, 30));
        CP_Graphics_DrawRect(0, 0, (float)CP_System_GetDisplayWidth(), (float)CP_System_GetDisplayHeight());
    }

    /***************************_Health bar_********************************/
    CP_Image_Draw(healthSprite1, 30, 1050, 60, 60, 255);
    CP_Image_Draw(healthSprite2, 70, 1050, 60, 60, 255);
    CP_Image_Draw(healthSprite3, 110, 1050, 60, 60, 255);
    /***********************************************************************/

    /***********************_Player inventory_******************************/
    inventorystate = 0;
    CP_Image_Draw(bag, (float)(CP_System_GetWindowWidth() / 2), 1050, 50, 50, 240);
    if (checkMouseCollision(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 960, 1050, 50, 50)) {
        inventorystate++;
        if (inventorystate > 1) {
            inventorystate = 0;
        }
        if (inventorystate == 1) {
            CP_Image_Draw(inventorySprite, (float)(CP_System_GetWindowWidth() / 2), 1050, 282, 58, 240);
            if (pdood->inventory[0]) {
                CP_Image_Draw(inventoryblock1, (float)((CP_System_GetWindowWidth() / 2) - 112), 1050, 50, 50, 255);
            }
            if (pdood->inventory[1]) {
                CP_Image_Draw(inventoryblock2, (float)((CP_System_GetWindowWidth() / 2) - 56), 1050, 50, 50, 255);
            }
            if (pdood->inventory[2]) {
                CP_Image_Draw(inventoryblock3, (float)(CP_System_GetWindowWidth() / 2), 1050, 50, 50, 255);
            }
            if (pdood->inventory[3]) {
                CP_Image_Draw(inventoryblock4, (float)((CP_System_GetWindowWidth() / 2) + 56), 1050, 50, 50, 255);
            }
            if (pdood->inventory[4]) {
                CP_Image_Draw(inventoryblock5, (float)((CP_System_GetWindowWidth() / 2) + 112), 1050, 50, 50, 255);
            }
        }
    }


    CP_Settings_Fill(COLOR_CYAN);
    CP_Settings_TextSize(30);
    if (tileTypeCount == 0)
    {
        CP_Font_DrawText("Dirt", dood.Pos.x, dood.Pos.y - 10);
        switch (pdood->inventory[0])
        {
        case 1:
            CP_Font_DrawText("1", dood.Pos.x + 50, dood.Pos.y - 10);
            break;
        case 2:
            CP_Font_DrawText("2", dood.Pos.x + 50, dood.Pos.y - 10);
            break;
        case 3:
            CP_Font_DrawText("3", dood.Pos.x + 50, dood.Pos.y - 10);
            break;
        case 4:
            CP_Font_DrawText("4", dood.Pos.x + 50, dood.Pos.y - 10);
            break;
        case 5:
            CP_Font_DrawText("5", dood.Pos.x + 50, dood.Pos.y - 10);
            break;
        default:
            CP_Font_DrawText("0", dood.Pos.x + 50, dood.Pos.y - 10);
            break;
        }

    }
    else if (tileTypeCount == 1)
    {
        CP_Font_DrawText("Stone", dood.Pos.x, dood.Pos.y - 10);
        switch (pdood->inventory[1])
        {
        case 1:
            CP_Font_DrawText("1", dood.Pos.x + 70, dood.Pos.y - 10);
            break;
        case 2:
            CP_Font_DrawText("2", dood.Pos.x + 70, dood.Pos.y - 10);
            break;
        case 3:
            CP_Font_DrawText("3", dood.Pos.x + 70, dood.Pos.y - 10);
            break;
        case 4:
            CP_Font_DrawText("4", dood.Pos.x + 70, dood.Pos.y - 10);
            break;
        case 5:
            CP_Font_DrawText("5", dood.Pos.x + 70, dood.Pos.y - 10);
            break;
        default:
            CP_Font_DrawText("0", dood.Pos.x + 70, dood.Pos.y - 10);
            break;
        }
    }
    /***********************************************************************/
    CP_Settings_StrokeWeight((float)1);
    /***************************_Render enemies_****************************/
    //Invisible enemy
    if (behaviourSeed >= 60 && behaviourSeed < 88)  //Chance of the ghost showing up on screen
    {
        timer += CP_System_GetDt();
        if (timer >= duration)
        {
            timer = 0.f;
            SWAP(float, minX, maxX);
        }
        CP_Image_Draw(ghostSprite, pWorm->enemyPos.x + 15, pWorm->enemyPos.y + 15, enemySizeX + 30, enemySizeY + 30, (int)Linear(minX, maxX, timer / duration));
    }
    /****************************_Ping enemy_*******************************/
    if (pingEnemy)
    {
        CP_Settings_StrokeWeight(3.f);
        CP_Settings_Stroke(COLOR_RED);
        CP_Settings_Fill(COLOR_RED);
        CP_Settings_TextSize(20);
        CP_Font_DrawText("Scanning...", dood.Pos.x - 30, dood.Pos.y);
        CP_Settings_Fill(CP_Color_Create(89, 89, 89, 2));
        CP_Graphics_DrawRect(pWorm->enemyPos.x, pWorm->enemyPos.y, enemySizeX, enemySizeY);
        CP_Graphics_DrawLine(pWorm->enemyPos.x, pWorm->enemyPos.y, pdood->Pos.x, pdood->Pos.y);
    }
    /***********************************************************************/

    /************************_Closest Gem Tile_*****************************/
    else if (pingGemTile)
    {
        CP_Settings_StrokeWeight(3.f);
        CP_Settings_Stroke(COLOR_CYAN);
        CP_Settings_Fill(COLOR_CYAN);
        CP_Settings_TextSize(20);
        CP_Font_DrawText("Scanning...", dood.Pos.x - 30, dood.Pos.y);
        CP_Settings_Fill(CP_Color_Create(89, 89, 89, 2));
        CP_Graphics_DrawRect(closestGemTile->tPos.x, closestGemTile->tPos.y, TileWidth, TileHeight);
        CP_Graphics_DrawLine(closestGemTile->tPos.x, closestGemTile->tPos.y, pdood->Pos.x, pdood->Pos.y);
    }
    /************************************************************************/
    /***************************_Ping Cooldown_******************************/
    else
    {
        CP_Settings_TextSize(45);
        CP_Settings_Stroke(COLOR_BLACK);
        CP_Settings_Fill(COLOR_WHITE);
        if (startCooldown)
        {
            CP_Font_DrawText(coolDownBuffer, 145, 1055);
        }
        else
        {
            CP_Font_DrawText("Scan Ready", 145, 1055);
        }
    }

    /************************_Mouse selector_********************************/
    CP_Settings_StrokeWeight((float)3);
    if (colorSet)
    {
        CP_Settings_Stroke(CP_Color_Create(255, 255, 0, 255));
    }
    else
    {
        CP_Settings_Stroke(CP_Color_Create(41, 41, 41, 255));
    }
    CP_Settings_Fill(CP_Color_Create(89, 89, 89, 2));
    CP_Graphics_DrawRect(selectorPosX, selectorPosY, TileWidth, TileHeight);
    /************************************************************************/

    //"Level 1-1" text
    CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
    CP_Settings_TextSize(50);
    if (levelCounter == 0)
    {
        CP_Font_DrawText("Level 1-1", 10, 30);
    }
    else if (levelCounter == 1)
    {
        CP_Font_DrawText("Level 1-2", 10, 30);
    }
    else if (levelCounter == 2)
    {
        CP_Font_DrawText("Level 1-3", 10, 30);
    }
    CP_Font_DrawText("Find the gems, they are in the stones!", 1000, 30);
    CP_Settings_TextSize(30);
    CP_Font_DrawText("Hold down Esc for controls", 10, 80);

    /***************************_Gem Counter_********************************/
    CP_Image_Draw(gemSprite, centerScreenX, 30, 50, 50, 255);
    sprintf_s(gemBuffer, _countof(gemBuffer), "%i", gems);
    CP_Font_DrawText(gemBuffer, centerScreenX + 50, 50);
    CP_Font_DrawText("/", centerScreenX + 90, 50);
    CP_Font_DrawText(totalGemBuffer, centerScreenX + 130, 50);
    /************************************************************************/
    if (mute)
    {
        CP_Image_Draw(mutedSprite, 230, 30, 80, 80, 255);
    }
    /*************************_Tutorial_screen_******************************/
    CP_Settings_Stroke(COLOR_BLACK);
    if (showbackstoryscreen)
    {
            CP_Image_Draw(backstorySprite, centerScreenX, centerScreenY, centerScreenX, centerScreenY, 255);
            CP_Settings_Fill(COLOR_GREEN);
            if (checkMouseCollision(mousePosX, mousePosY, centerScreenX + 400, centerScreenY + 100, 50, 50))
            {
                CP_Settings_Stroke(COLOR_CYAN);
            }
            CP_Graphics_DrawRect(centerScreenX + 400, centerScreenY + 100, 50, 50);
    }

    /************************************************************************/

    //"WASD to move" text
    if (CP_Input_KeyDown(KEY_ESCAPE))
    {
        CP_Settings_Stroke(COLOR_BLACK);
        CP_Settings_Fill(CP_Color_Create(166, 166, 166, 100));
        CP_Graphics_DrawRect(5.f, 80.f, 910, 220);
        CP_Settings_Fill(CP_Color_Create(80, 220, 220, 255));
        CP_Settings_TextSize(50);
        CP_Font_DrawText("'WASD' to move.", 10.f, 120.f);
        CP_Font_DrawText("Left click to mine.", 10.f, 160.f);
        CP_Font_DrawText("'Q' to cycle thru tile types.", 10.f, 200.f);
        CP_Font_DrawText("'E' to scan for Gem blocks, 'R' to scan for enemy.", 10.f, 240.f);
        CP_Settings_Fill(COLOR_RED);
        if (checkMouseCollision(mousePosX, mousePosY, 5.f, 300.f, 250, 45))
        {
            CP_Settings_Stroke(COLOR_CYAN);
        }
        CP_Graphics_DrawRect(5.f, 300.f, 250, 45);
        CP_Settings_TextSize(30);
        CP_Settings_Fill(COLOR_BLACK);
        CP_Font_DrawText("Back to Main Menu", 5.f, 335.f);
    }

    //Render something when player dies and when reached endpoint
    CP_Settings_Stroke(COLOR_BLACK);
    if (pdood->health == 0)
    {
        CP_Settings_Fill(CP_Color_Create(54, 34, 0, 100));
        CP_Graphics_DrawRect(0, 0, (float)CP_System_GetDisplayWidth(), (float)CP_System_GetDisplayHeight());
        if (screenTimer < screenDuration)
        {
            screenTimer += CP_System_GetDt();
        }
        CP_Image_Draw(loseScreen, centerScreenX, centerScreenY, Linear(0, (float)(CP_System_GetWindowWidth() / 2), screenTimer / screenDuration), Linear(0, (float)(CP_System_GetWindowHeight() / 2), screenTimer / screenDuration), 255);
        CP_Settings_TextSize(50);
        CP_Settings_Fill(COLOR_RED);
        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
        CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 0));
        if (checkMouseCollision(mousePosX, mousePosY, 500, 510, 250, 45))   //Quit
        {
            CP_Settings_Stroke(COLOR_CYAN);
        }
        CP_Graphics_DrawRect(500, 510, 250, 45);
        CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 0));
        if (checkMouseCollision(mousePosX, mousePosY, 500, 470, 250, 45))   //Restart
        {
            CP_Settings_Stroke(COLOR_CYAN);
        }
        CP_Graphics_DrawRect(500, 470, 250, 45);
    }
    if (win)
    {
        CP_Settings_Fill(CP_Color_Create(170, 181, 130, 100));
        CP_Graphics_DrawRect(0, 0, (float)CP_System_GetDisplayWidth(), (float)CP_System_GetDisplayHeight());
        if (screenTimer < screenDuration)
        {
            screenTimer += CP_System_GetDt();
        }
        CP_Image_Draw(winScreen, centerScreenX, centerScreenY, Linear(0, (float)(CP_System_GetWindowWidth() / 2), screenTimer / screenDuration), Linear(0, (float)(CP_System_GetWindowHeight() / 2), screenTimer / screenDuration), 255);
        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
        CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 0));
        if (checkMouseCollision(mousePosX, mousePosY, centerScreenX - 400, centerScreenY + 150, 400, 45))   //Quit button
        {
            CP_Settings_Stroke(COLOR_CYAN);
        }
        CP_Graphics_DrawRect(centerScreenX - 400, centerScreenY + 150, 400, 45);
        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
        CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 0));
        if (checkMouseCollision(mousePosX, mousePosY, centerScreenX + 200, centerScreenY + 150, 250, 45))   //Restart button
        {
            CP_Settings_Stroke(COLOR_CYAN);
        }
        CP_Graphics_DrawRect(centerScreenX + 200, centerScreenY + 150, 250, 45);
    }
    if (showInsuffScreen)
    {
        screenTimer += CP_System_GetDt();
        if (screenTimer >= screenDuration)
        {
            screenTimer = 0.f;
            showInsuffScreen = false;
        }
        else
        {
            CP_Settings_TextSize(30);
            CP_Font_DrawText("Collect all the gems first!", pdood->Pos.x - 200, pdood->Pos.y - 40);
        }
    }
    //draw_level1();
}

void game_exit(void)
{

}

//Checks up, down, left, right
/*
Function is not updating dood obj, but updating the argument Player player?
Current bandaid fix = directly changeing dood variables
Update ==== Issue fixed, changed function to take in pointer instead of the struct straightaway
*/
void checkCollision(Player* player, Tiles tile)
{
    //Check for collision on the left
    if (player->Pos.x == tile.tPos.x + TileWidth && tile.tPos.y < player->Pos.y + PlayerHeight && player->Pos.y < tile.tPos.y + TileHeight)
    {
        player->isCollidingLeft = 1;
    }
    //Check for collision on the right
    if (player->Pos.x + PlayerWidth == tile.tPos.x && tile.tPos.y < player->Pos.y + PlayerHeight && player->Pos.y < tile.tPos.y + TileHeight)
    {
        player->isCollidingRight = 1;
    }
    //Check for collision on top
    if (player->Pos.y == tile.tPos.y + TileHeight && tile.tPos.x < player->Pos.x + PlayerWidth && player->Pos.x < tile.tPos.x + TileWidth)
    {
        player->isCollidingUp = 1;
    }
    //Check for collision below
    if (tile.tPos.y == player->Pos.y + PlayerHeight && tile.tPos.x < player->Pos.x + PlayerWidth && player->Pos.x < tile.tPos.x + TileWidth)
    {
        player->isCollidingDown = 1;
    }
}

//Check for mouse on any object
int checkMouseCollision(float mouseX, float mouseY, float _x, float _y, int _width, int _height)
{
    return mouseX >= _x && mouseX <= _x + _width && mouseY >= _y && mouseY <= _y + _height;
}

//Check for which tile the player is on, returns 1 if player is on _tile
int internalCollision(Player player, Tiles _tile)
{
    return (player.Pos.x >= _tile.x && (player.Pos.x + PlayerWidth) <= (_tile.x + TileWidth)
        && player.Pos.y >= _tile.y && (player.Pos.y + PlayerHeight) <= (_tile.y + TileHeight));
}

//Useless
void saveLevel(int currLevel, int dstLevel)
{
    for (int rows = 0; rows < numOfTilesX; rows++)
    {
        for (int cols = 0; cols < numOfTilesY; cols++)
        {
            tileSet[currLevel][rows][cols] = tileSet[dstLevel][rows][cols];
        }
    }
}