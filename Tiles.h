#pragma once
#define numOfLevels 5
#define numOfTilesX 64
#define numOfTilesY 36
#define TileWidth 30
#define TileHeight 30

typedef struct
{
    //Postion of square
    float x;
    float y;
    CP_Vector tPos;
    //Activity
    int isOn;
    //Dimensions
    float tileWidth;
    float tileHeight;
    //Type of tile
    int type;
    bool hasGem;
}Tiles;

//Array of tiles
Tiles tileSet[numOfLevels][numOfTilesX][numOfTilesY];
//Constructor
Tiles new_Tile(float _x, float _y, float _width, float _height, int isActive, int _type);

void setGameLevel(int level);
