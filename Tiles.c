#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cprocessing.h"
#include "Tiles.h"

//Constructor function or declaring new Tiles obj
Tiles new_Tile(float _x, float _y, float _width, float _height, int isActive, int _type)
{
    /*
    * x, y = tile position
    * tPos = vector position
    * width, height = tile wdith height
    * isOn = activity, if it is active in the scene
    * type  = Type of tile, 1 = dirt, 2 = stone, 3 = bedrock, 0  = start point, 4 = end point
    */
    Tiles A;
    A.x = _x;
    A.y = _y;
    A.tPos = CP_Vector_Set(_x, _y);
    A.tileWidth = _width;
    A.tileHeight = _height;
    A.isOn = isActive;
    A.type = _type;
    A.hasGem = false;

    return A;
}

void setGameLevel(int levelCounter)
{
    switch (levelCounter)
    {
    case 0:
        //Map sets for level 0

        //Row 1
        tileSet[0][2][2].isOn = 1;
        tileSet[0][3][2].isOn = 1;
        for (int i = 12; i <= numOfTilesX - 2; i++)
        {
            if (i == 20 || i == 21 || i == 22 || i == 37 || i == 38 ||
                i == 50 || i == 51 || i == 52 || i == 58 || i == 59 || i == 60)
            {
                tileSet[0][i][2].type = 1;
                tileSet[0][i][2].isOn = 0;
            }
            else if (i == 61)
            {
                tileSet[0][i][2].isOn = 1;
                tileSet[0][i][2].type = 4;
            }
            else
            {
                tileSet[0][i][2].type = 1;
                tileSet[0][i][2].isOn = 1;
            }
        }

        //Row 2
        tileSet[0][2][3].isOn = 1;
        for (int i = 13; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 19 && i <= 23) || (i >= 29 && i <= 33) || i == 36 || i == 37 || i == 38 ||
                (i >= 49 && i <= 53) || (i >= 57 && i <= 61))
            {
                tileSet[0][i][3].isOn = 0;
            }
            else
            {
                tileSet[0][i][3].type = 1;
                tileSet[0][i][3].isOn = 1;
            }
        }

        //Row 3
        tileSet[0][2][4].isOn = 1;
        tileSet[0][3][4].isOn = 1;
        for (int i = 14; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 18 && i <= 25) || (i >= 26 && i <= 32) || i == 36 || i == 37 || i == 38 || i == 39 ||
                (i >= 48 && i <= 54) || (i >= 57 && i <= 61))
            {
                tileSet[0][i][4].isOn = 0;
            }
            else
            {
                tileSet[0][i][4].type = 1;
                tileSet[0][i][4].isOn = 1;
            }
        }

        //Row 4
        tileSet[0][2][5].isOn = 1;
        tileSet[0][3][5].isOn = 1;
        tileSet[0][4][5].isOn = 1;
        tileSet[0][5][5].isOn = 1;
        tileSet[0][6][5].isOn = 1;
        tileSet[0][7][5].isOn = 1;
        tileSet[0][8][5].isOn = 1;
        tileSet[0][9][5].isOn = 1;
        tileSet[0][10][5].isOn = 1;
        tileSet[0][14][5].isOn = 1;
        tileSet[0][15][5].isOn = 1;
        tileSet[0][16][5].isOn = 1;
        tileSet[0][20][5].isOn = 1;
        tileSet[0][28][5].isOn = 1;
        tileSet[0][29][5].isOn = 1;
        tileSet[0][32][5].isOn = 1;
        tileSet[0][33][5].isOn = 1;
        tileSet[0][34][5].isOn = 1;
        tileSet[0][35][5].isOn = 1;
        tileSet[0][56][5].isOn = 1;

        tileSet[0][41][5].isOn = 1;
        tileSet[0][42][5].isOn = 1;
        tileSet[0][43][5].isOn = 1;
        tileSet[0][44][5].isOn = 1;
        tileSet[0][45][5].isOn = 1;
        tileSet[0][46][5].isOn = 1;

        tileSet[0][3][5].type = 2;
        tileSet[0][4][5].type = 2;
        tileSet[0][5][5].type = 2;
        tileSet[0][20][5].type = 2;
        tileSet[0][28][5].type = 2;
        tileSet[0][29][5].type = 2;

        //Row 5
        for (int i = 4; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 12 && i <= 19) || (i >= 22 && i <= 31) || (i >= 37 && i <= 41) || (i >= 46 && i <= 58) || (i == 61))
            {
                tileSet[0][i][6].isOn = 0;
            }
            else
            {
                tileSet[0][i][6].type = 1;
                tileSet[0][i][6].isOn = 1;
            }
        }

        tileSet[0][2][6].isOn = 1;
        tileSet[0][3][6].isOn = 1;
        tileSet[0][15][6].isOn = 1;
        tileSet[0][16][6].isOn = 1;
        tileSet[0][26][6].isOn = 1;
        tileSet[0][27][6].isOn = 1;
        tileSet[0][28][6].isOn = 1;
        tileSet[0][29][6].isOn = 1;
        tileSet[0][30][6].isOn = 1;
        tileSet[0][31][6].isOn = 1;


        tileSet[0][2][6].type = 2;
        tileSet[0][3][6].type = 2;
        tileSet[0][4][6].type = 2;
        tileSet[0][18][6].type = 2;
        tileSet[0][20][6].type = 2;
        tileSet[0][21][6].type = 2;
        tileSet[0][28][6].type = 2;
        tileSet[0][29][6].type = 2;
        tileSet[0][30][6].type = 2;
        tileSet[0][31][6].type = 2;





        for (int i = 28; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 38 && i <= 43) || (i >= 46 && i <= 57) || (i >= 60 && i <= 61))
            {
                tileSet[0][i][7].isOn = 0;
            }
            else
            {
                tileSet[0][i][7].type = 1;
                tileSet[0][i][7].isOn = 1;
            }
        }
        //Row 6
        tileSet[0][2][7].isOn = 1;
        tileSet[0][3][7].isOn = 1;
        tileSet[0][4][7].isOn = 1;
        tileSet[0][5][7].isOn = 1;
        tileSet[0][6][7].isOn = 1;
        tileSet[0][7][7].isOn = 1;
        tileSet[0][10][7].isOn = 1;
        tileSet[0][11][7].isOn = 1;
        tileSet[0][12][7].isOn = 1;
        tileSet[0][15][7].isOn = 1;
        tileSet[0][16][7].isOn = 1;
        tileSet[0][20][7].isOn = 1;
        tileSet[0][21][7].isOn = 1;
        tileSet[0][22][7].isOn = 1;
        tileSet[0][26][7].isOn = 1;
        tileSet[0][27][7].isOn = 1;
        tileSet[0][28][7].isOn = 1;
        tileSet[0][29][7].isOn = 1;


        tileSet[0][2][7].type = 2;
        tileSet[0][3][7].type = 2;
        tileSet[0][21][7].type = 2;
        tileSet[0][22][7].type = 2;
        tileSet[0][28][7].type = 2;

        for (int i = 19; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 33 && i <= 35) || i == 19 || (i >= 24 && i <=26) || (i >= 39 && i <= 49) || (i >= 53 && i <= 55) || (i >= 60 && i <= 61))
            {
                tileSet[0][i][8].isOn = 0;
            }
            else
            {
                tileSet[0][i][8].type = 1;
                tileSet[0][i][8].isOn = 1;
            }
        }

        //Row 7
        tileSet[0][5][8].isOn = 1;
        tileSet[0][11][8].isOn = 1;
        tileSet[0][12][8].isOn = 1;
        tileSet[0][13][8].isOn = 1;
        tileSet[0][16][8].isOn = 1;
        tileSet[0][45][8].isOn = 1;

  

        
        for (int i = 14; i <= numOfTilesX - 2; i++)
        {
            if (i == 14 || i == 15 || i == 19 || (i >= 20 && i <= 21) || (i >= 25 && i <= 27) || (i >= 32 && i <= 36) || (i >= 40 && i <= 48) || (i >= 53 && i <= 56) || (i >= 59 && i <= 61))
            {
                tileSet[0][i][9].isOn = 0;
            }
            else
            {
                tileSet[0][i][9].type = 1;
                tileSet[0][i][9].isOn = 1;
            }
        }
        //Row 8
        tileSet[0][13][9].isOn = 1;

        tileSet[0][16][9].type = 2;
        tileSet[0][17][9].type = 2;
        tileSet[0][18][9].type = 2;

        //Row 9
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 6 && i <= 8) || (i >= 10 && i <= 14)|| (i >= 19 && i <= 23) || (i >= 26 && i <= 28) ||
                (i >= 31 && i <= 37) || (i >= 42 && i <= 47) || (i >= 54 && i <= 56) || i == 59 || i == 60 || i == 61)
            {
                tileSet[0][i][10].isOn = 0;
            }
            else
            {
                tileSet[0][i][10].type = 1;
                tileSet[0][i][10].isOn = 1;
            }
        }
        tileSet[0][15][10].type = 2;
        tileSet[0][16][10].type = 2;
        tileSet[0][17][10].type = 2;

        //Row 10
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 10 && i <= 12) || i == 13 || (i >= 19 && i <= 29) ||
                (i >= 31 && i <= 37) || (i >= 43 && i <= 45) || i == 55 || i == 59 || i == 60 || i == 61)
            {
                tileSet[0][i][11].isOn = 0;
            }
            else
            {
                tileSet[0][i][11].type = 1;
                tileSet[0][i][11].isOn = 1;
            }
        }

        //Row 11
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 2 || i == 3 || i == 9 || i == 10 || (i >= 18 && i <= 34) || (i >= 36 && i <= 38) ||
                i == 40 || i == 41 || i == 45 || i == 51 || i == 52 || (i >= 58 && i <= 61))
            {
                tileSet[0][i][12].isOn = 0;
            }
            else
            {
                tileSet[0][i][12].type = 1;
                tileSet[0][i][12].isOn = 1;
            }
        }

        tileSet[0][30][12].isOn = 1;
        tileSet[0][31][12].isOn = 1;
        tileSet[0][32][12].isOn = 1;

        tileSet[0][30][12].type = 2;
        tileSet[0][31][12].type = 2;
        tileSet[0][32][12].type = 2;
        tileSet[0][42][12].type = 2;
        tileSet[0][43][12].type = 2;
        tileSet[0][44][12].type = 2;

        //Row 12
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 2 || (i >= 7 && i <= 11) || i == 17 || i == 18 || (i >= 20 && i <= 23) || (i >= 27 && i <= 33) ||
                (i >= 36 && i <= 41) || i == 51 || i == 52 || i == 53 || i == 58 || i == 59)
            {
                tileSet[0][i][13].isOn = 0;
            }
            else
            {
                tileSet[0][i][13].type = 1;
                tileSet[0][i][13].isOn = 1;
            }
        }
        tileSet[0][29][13].isOn = 1;
        tileSet[0][30][13].isOn = 1;
        tileSet[0][31][13].isOn = 1;
        tileSet[0][32][13].isOn = 1;
        tileSet[0][33][13].isOn = 1;

        tileSet[0][29][13].type = 2;
        tileSet[0][30][13].type = 2;
        tileSet[0][31][13].type = 2;
        tileSet[0][32][13].type = 2;
        tileSet[0][33][13].type = 2;
        tileSet[0][42][13].type = 2;
        tileSet[0][43][13].type = 2;
        tileSet[0][44][13].type = 2;
        tileSet[0][45][13].type = 2;
        tileSet[0][46][13].type = 2;
        tileSet[0][57][13].type = 2;

        //Row 13
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 5 || (i >= 7 && i <= 14) || (i >= 16 && i <= 18) || (i >= 21 && i <= 24) || i == 31 || i == 32 || (i >= 37 && i <= 40) ||
                (i >= 50 && i <= 54))
            {
                tileSet[0][i][14].isOn = 0;
            }
            else
            {
                tileSet[0][i][14].type = 1;
                tileSet[0][i][14].isOn = 1;
            }
        }
        tileSet[0][12][14].isOn = 1;
        tileSet[0][13][14].isOn = 1;
        tileSet[0][14][14].isOn = 1;
        tileSet[0][30][14].isOn = 1;
        tileSet[0][31][14].isOn = 1;

        tileSet[0][12][14].type = 2;
        tileSet[0][13][14].type = 2;
        tileSet[0][14][14].type = 2;
        tileSet[0][30][14].type = 2;
        tileSet[0][31][14].type = 2;

        tileSet[0][41][14].type = 2;
        tileSet[0][42][14].type = 2;
        tileSet[0][45][14].type = 2;
        tileSet[0][46][14].type = 2;
        tileSet[0][47][14].type = 2;
        tileSet[0][57][14].type = 2;
        tileSet[0][58][14].type = 2;

        //Row 14
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 4 || i == 5 || (i >= 8 && i <= 17) || (i >= 22 && i <= 25) || (i >= 29 && i <= 33) || i == 38 || i == 39 || (i >= 50 && i <= 53))
            {
                tileSet[0][i][15].isOn = 0;
            }
            else
            {
                tileSet[0][i][15].type = 1;
                tileSet[0][i][15].isOn = 1;
            }
        }

        tileSet[0][11][15].isOn = 1;
        tileSet[0][12][15].isOn = 1;
        tileSet[0][13][15].isOn = 1;
        tileSet[0][29][15].isOn = 1;
        tileSet[0][30][15].isOn = 1;


        tileSet[0][11][15].type = 2;
        tileSet[0][12][15].type = 2;
        tileSet[0][13][15].type = 2;

        tileSet[0][29][15].type = 2;
        tileSet[0][30][15].type = 2;

        tileSet[0][40][15].type = 2;
        tileSet[0][41][15].type = 2;
        tileSet[0][45][15].type = 2;
        tileSet[0][46][15].type = 2;
        tileSet[0][47][15].type = 2;
        tileSet[0][48][15].type = 2;
        tileSet[0][56][15].type = 2;
        tileSet[0][57][15].type = 2;
        tileSet[0][58][15].type = 2;
        tileSet[0][59][15].type = 2;

        //Row 15
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 4 || i == 5 || i == 8 || i == 9 || (i >= 14 && i <= 18) || i == 23 || i == 24 ||
                (i >= 28 && i <= 35) || (i >= 38 && i <= 40) || i == 48 || (i >= 50 && i <= 53) || i == 57)
            {
                tileSet[0][i][16].isOn = 0;
            }
            else
            {
                tileSet[0][i][16].type = 1;
                tileSet[0][i][16].isOn = 1;
            }
        }

        tileSet[0][41][16].type = 2;
        tileSet[0][42][16].type = 2;
        tileSet[0][46][16].type = 2;
        tileSet[0][47][16].type = 2;
        tileSet[0][58][16].type = 2;
        tileSet[0][59][16].type = 2;

        //Row 16
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 8 && i <= 10) || (i >= 15 && i <= 18) || i == 22 || i == 23 ||
                (i >= 27 && i <= 31) || (i >= 33 && i <= 35) || (i >= 39 && i <= 42) || (i >= 47 && i <= 52) || i == 56 || i == 57 || i == 58)
            {
                tileSet[0][i][17].isOn = 0;
            }
            else
            {
                tileSet[0][i][17].type = 1;
                tileSet[0][i][17].isOn = 1;
            }
        }
        tileSet[0][19][17].type = 2;
        tileSet[0][20][17].type = 2;
        tileSet[0][36][17].type = 2;
        tileSet[0][46][17].type = 2;
        tileSet[0][59][17].type = 2;
        tileSet[0][60][17].type = 2;

        //Row 17
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 9 && i <= 12) || (i >= 17 && i <= 19) || (i >= 22 && i <= 24) || i == 28 || i == 29 ||
                (i >= 33 && i <= 43) || (i >= 47 && i <= 52) || (i >= 55 && i <= 61))
            {
                tileSet[0][i][18].isOn = 0;
            }
            else
            {
                tileSet[0][i][18].type = 1;
                tileSet[0][i][18].isOn = 1;
            }
        }
        tileSet[0][35][18].isOn = 1;
        tileSet[0][36][18].isOn = 1;
        tileSet[0][37][18].isOn = 1;



        tileSet[0][20][18].type = 2;
        tileSet[0][21][18].type = 2;
        tileSet[0][35][18].type = 2;
        tileSet[0][36][18].type = 2;
        tileSet[0][37][18].type = 2;


        //Row 18
        tileSet[0][2][19].isOn = 1;
        for (int i = 3; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 6) || (i >= 10 && i <= 14) || (i >= 18 && i <= 19) || (i >= 23 && i <= 25) ||
                (i >= 32 && i <= 35) || (i >= 37 && i <= 44) || i == 47 || i == 48 || (i >= 55 && i <= 60))
            {
                tileSet[0][i][19].isOn = 0;
            }
            else
            {
                tileSet[0][i][19].type = 1;
                tileSet[0][i][19].isOn = 1;
            }
        }

        tileSet[0][35][19].isOn = 1;
        tileSet[0][37][19].isOn = 1;

        tileSet[0][2][19].type = 2;
        tileSet[0][21][19].type = 2;
        tileSet[0][22][19].type = 2;
        tileSet[0][28][19].type = 3;
        tileSet[0][35][19].type = 2;
        tileSet[0][37][19].type = 2;


        for (int i = 4; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 7) || (i >= 13 && i <= 19) || (i >= 23 && i <= 26) ||
                (i >= 31 && i <= 33) || (i >= 39 && i <= 43) || (i >= 54 && i <= 59))
            {
                tileSet[0][i][20].isOn = 0;
            }
            else
            {
                tileSet[0][i][20].type = 1;
                tileSet[0][i][20].isOn = 1;
            }
        }
        //Row 19
        tileSet[0][2][20].isOn = 1;
        tileSet[0][3][20].isOn = 1;
        tileSet[0][16][20].isOn = 1;

        tileSet[0][2][20].type = 2;
        tileSet[0][3][20].type = 2;
        tileSet[0][22][20].type = 2;
        tileSet[0][44][20].type = 2;
        tileSet[0][45][20].type = 2;
        tileSet[0][46][20].type = 2;
        tileSet[0][47][20].type = 2;
        tileSet[0][48][20].type = 2;
        tileSet[0][49][20].type = 2;

        //Row 20
        tileSet[0][2][21].isOn = 1;
        tileSet[0][3][21].isOn = 1;
        tileSet[0][4][21].isOn = 1;

        for (int i = 5; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 5 && i <= 10) || (i >= 14 && i <= 18) || (i >= 23 && i <= 27) || (i >= 23 && i <= 26) ||
                (i >= 30 && i <= 32) || (i >= 38 && i <= 42) || (i >= 48 && i <= 50) || (i >= 54 && i <= 59))
            {
                tileSet[0][i][21].isOn = 0;
            }
            else
            {
                tileSet[0][i][21].type = 1;
                tileSet[0][i][21].isOn = 1;
            }
        }

        tileSet[0][2][21].type = 2;
        tileSet[0][3][21].type = 2;
        tileSet[0][4][21].type = 2;
        tileSet[0][44][21].type = 2;
        tileSet[0][45][21].type = 2;
        tileSet[0][46][21].type = 2;
        tileSet[0][47][21].type = 2;
        
        //Row 21
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 7 && i <= 12) || (i >= 16 && i <= 20) || (i >= 24 && i <= 28) || (i >= 30 && i <= 34) ||
                (i >= 37 && i <= 41) || (i >= 46 && i <= 50) || i == 55 || i == 56)
            {
                tileSet[0][i][22].isOn = 0;
            }
            else
            {
                tileSet[0][i][22].type = 1;
                tileSet[0][i][22].isOn = 1;
            }
        }
        tileSet[0][4][22].type = 2;
        tileSet[0][5][22].type = 2;
        tileSet[0][44][22].type = 2;
        tileSet[0][45][22].type = 2;
        //Row 22
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 8 || (i >= 12 && i <= 21) || (i >= 25 && i <= 40) || (i >= 44 && i <= 46) || (i >= 48 && i <= 51) ||
                (i >= 55 && i <= 57))
            {
                tileSet[0][i][23].isOn = 0;
            }
            else
            {
                tileSet[0][i][23].type = 1;
                tileSet[0][i][23].isOn = 1;
            }
        }

        //Row 23
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 2 || i == 7 || i == 8 || (i >= 12 && i <= 16) || (i >= 21 && i <= 40) || (i >= 42 && i <= 45) || (i >= 48 && i <= 52) ||
                (i >= 55 && i <= 58))
            {
                tileSet[0][i][24].isOn = 0;
            }
            else
            {
                tileSet[0][i][24].type = 1;
                tileSet[0][i][24].isOn = 1;
            }
        }

        //Row 24
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 2 || i == 7 || i == 8 || (i >= 11 && i <= 16) || (i >= 20 && i <= 25) || (i >= 27 && i <= 31) || (i >= 38 && i <= 45) ||
                (i >= 48 && i <= 50) || (i >= 56 && i <= 59))
            {
                tileSet[0][i][25].isOn = 0;
            }
            else
            {
                tileSet[0][i][25].type = 1;
                tileSet[0][i][25].isOn = 1;
            }
        }
        tileSet[0][33][25].type = 2;

        //Row 25
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if (i == 2 || (i >= 4 && i <= 15) || (i >= 20 && i <= 25) || i == 29 || (i >= 40 && i <= 41) || (i >= 43 && i <= 44) ||
                (i >= 47 && i <= 50) || (i >= 57 && i <= 60))
            {
                tileSet[0][i][26].isOn = 0;
            }
            else
            {
                tileSet[0][i][26].type = 1;
                tileSet[0][i][26].isOn = 1;
            }
        }
        tileSet[0][32][26].type = 2;
        tileSet[0][33][26].type = 2;
        tileSet[0][34][26].type = 2;

        //Row 26
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 8 && i <= 10) || (i >= 19 && i <= 26) || i == 29 || (i >= 33 && i <= 36) || (i >= 40 && i <= 41) ||
                (i >= 46 && i <= 49) || (i >= 56 && i <= 60))
            {
                tileSet[0][i][27].isOn = 0;
            }
            else
            {
                tileSet[0][i][27].type = 1;
                tileSet[0][i][27].isOn = 1;
            }
        }
        tileSet[0][31][27].type = 2;
        tileSet[0][32][27].type = 2;

        //Row 27
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || i == 8 || (i >= 12 && i <= 15) || (i >= 18 && i <= 21) || (i >= 24 && i <= 27) || (i >= 32 && i <= 38) ||
                i == 41 || i == 42 || (i >= 45 && i <= 48) || (i >= 54 && i <= 59))
            {
                tileSet[0][i][28].isOn = 0;
            }
            else
            {
                tileSet[0][i][28].type = 1;
                tileSet[0][i][28].isOn = 1;
            }
        }
        tileSet[0][22][28].type = 2;
        tileSet[0][23][28].type = 2;
        tileSet[0][31][28].type = 2;
        tileSet[0][39][28].type = 2;

        //Row 28
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || (i >= 11 && i <= 15) || (i >= 18 && i <= 20) || (i >= 25 && i <= 28) || (i >= 30 && i <= 38) ||
                (i >= 41 && i <= 48) || (i >= 53 && i <= 57))
            {
                tileSet[0][i][29].isOn = 0;
            }
            else
            {
                tileSet[0][i][29].type = 1;
                tileSet[0][i][29].isOn = 1;
            }
        }
        tileSet[0][8][29].type = 2;
        tileSet[0][21][29].type = 2;
        tileSet[0][22][29].type = 2;
        tileSet[0][23][29].type = 2;
        tileSet[0][24][29].type = 2;
        tileSet[0][39][29].type = 2;
        tileSet[0][40][29].type = 2;

        //Row 29
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 10 && i <= 12) || (i >= 15 && i <= 16) || (i >= 18 && i <= 19) || (i >= 26 && i <= 37) || (i >= 42 && i <= 45) ||
                (i >= 47 && i <= 50) || (i >= 52 && i <= 55))
            {
                tileSet[0][i][30].isOn = 0;
            }
            else
            {
                tileSet[0][i][30].type = 1;
                tileSet[0][i][30].isOn = 1;
            }
        }
        tileSet[0][7][30].type = 2;
        tileSet[0][8][30].type = 2;
        tileSet[0][20][30].type = 2;
        tileSet[0][21][30].type = 2;
        tileSet[0][23][30].type = 2;
        tileSet[0][24][30].type = 2;
        tileSet[0][25][30].type = 2;
        tileSet[0][38][30].type = 2;
        tileSet[0][39][30].type = 2;
        tileSet[0][40][30].type = 2;
        tileSet[0][41][30].type = 2;

        //Row 30
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 10 && i <= 12) || (i >= 15 && i <= 19) || (i >= 18 && i <= 19) || (i >= 27 && i <= 36) || (i >= 43 && i <= 44) ||
                (i >= 48 && i <= 54))
            {
                tileSet[0][i][31].isOn = 0;
            }
            else
            {
                tileSet[0][i][31].type = 1;
                tileSet[0][i][31].isOn = 1;
            }
        }
        tileSet[0][6][31].type = 2;
        tileSet[0][7][31].type = 2;
        tileSet[0][8][31].type = 2;
        tileSet[0][9][31].type = 2;
        tileSet[0][20][31].type = 2;
        tileSet[0][21][31].type = 2;
        tileSet[0][24][31].type = 2;
        tileSet[0][25][31].type = 2;
        tileSet[0][26][31].type = 2;
        tileSet[0][37][31].type = 2;
        tileSet[0][38][31].type = 2;
        tileSet[0][39][31].type = 2;
        tileSet[0][41][31].type = 2;
        tileSet[0][42][31].type = 2;

        //Row 31
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 11 && i <= 13) || (i >= 15 && i <= 18) || (i >= 18 && i <= 19) || (i >= 28 && i <= 29) || (i >= 32 && i <= 35) ||
                (i >= 49 && i <= 52))
            {
                tileSet[0][i][32].isOn = 0;
            }
            else
            {
                tileSet[0][i][32].type = 1;
                tileSet[0][i][32].isOn = 1;
            }
        }
        tileSet[0][19][32].type = 2;
        tileSet[0][20][32].type = 2;
        tileSet[0][25][32].type = 2;
        tileSet[0][26][32].type = 2;
        tileSet[0][27][32].type = 2;
        tileSet[0][36][32].type = 2;
        tileSet[0][37][32].type = 2;
        tileSet[0][38][32].type = 2;
        tileSet[0][42][32].type = 2;
        tileSet[0][43][32].type = 2;

        //Row 32
        for (int i = 2; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 12 && i <= 16) || (i >= 28 && i <= 29) || (i >= 50 && i <= 51))
            {
                tileSet[0][i][33].isOn = 0;
            }
            else
            {
                tileSet[0][i][33].type = 1;
                tileSet[0][i][33].isOn = 1;
            }
        }

        break;

    case 1:

        //row 1
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 5 && i <= 11) || (i >= 17 && i <= 20) || (i >= 28 && i <= 30) || (i >= 35 && i <= 38) || (i >= 41 && i <= 44) || (i >= 51 && i <= 56))
            {
                tileSet[1][i][2].type = 1;
                tileSet[1][i][2].isOn = 0;
            }
            else
            {
                tileSet[1][i][2].type = 1;
                tileSet[1][i][2].isOn = 1;
            }
        }

        //row 2
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 12) || (i >= 16 && i <= 21) || (i >= 27 && i <= 31) || (i >= 34 && i <= 37) || (i >= 41 && i <= 45) || (i >= 50 && i <= 57))
            {
                tileSet[1][i][3].type = 1;
                tileSet[1][i][3].isOn = 0;
            }
            else
            {
                tileSet[1][i][3].type = 1;
                tileSet[1][i][3].isOn = 1;
            }
        }

        //row 3
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 12) || (i >= 15 && i <= 22) || (i >= 27 && i <= 32) || (i >= 34 && i <= 37) || (i >= 41 && i <= 45) || (i >= 49 && i <= 56))
            {
                tileSet[1][i][4].type = 1;
                tileSet[1][i][4].isOn = 0;
            }
            else
            {
                tileSet[1][i][4].type = 1;
                tileSet[1][i][4].isOn = 1;
            }
        }

        //row 4
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 12) || (i >= 15 && i <= 23) || (i >= 26 && i <= 32) || (i >= 34 && i <= 36) || (i >= 40 && i <= 46) || (i >= 49 && i <= 55))
            {
                tileSet[1][i][5].type = 1;
                tileSet[1][i][5].isOn = 0;
            }
            else
            {
                tileSet[1][i][5].type = 1;
                tileSet[1][i][5].isOn = 1;
            }
        }
        tileSet[1][13][5].type = 2;

        //row 5
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 12) || (i >= 15 && i <= 23) || (i >= 26  && i <= 36) || (i >= 40 && i <= 47) || (i >= 49 && i <= 53) || (i >= 59 && i <= 60))
            {
                tileSet[1][i][6].type = 1;
                tileSet[1][i][6].isOn = 0;
            }
            else
            {
                tileSet[1][i][6].type = 1;
                tileSet[1][i][6].isOn = 1;
            }
        }
        tileSet[1][13][6].type = 2;
        tileSet[1][14][6].type = 2;

        //row 6
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 11) || (i >= 16 && i <= 24) || (i >= 26 && i <= 36) || (i >= 40 && i <= 52) || (i >= 56 && i <= 61))
            {
                tileSet[1][i][7].type = 1;
                tileSet[1][i][7].isOn = 0;
            }
            else
            {
                tileSet[1][i][7].type = 1;
                tileSet[1][i][7].isOn = 1;
            }
        }
        tileSet[1][12][7].type = 2;
        tileSet[1][13][7].type = 2;
        tileSet[1][14][7].type = 2;
        tileSet[1][15][7].type = 2;
        tileSet[1][38][7].type = 2;

        //row 7
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 11) || (i >= 16 && i <= 28) || (i >= 31 && i <= 34) || (i >= 42 && i <= 49) || (i >= 51 && i <= 61))
            {
                tileSet[1][i][8].type = 1;
                tileSet[1][i][8].isOn = 0;
            }
            else
            {
                tileSet[1][i][8].type = 1;
                tileSet[1][i][8].isOn = 1;
            }
        }
        tileSet[1][12][8].type = 2;
        tileSet[1][15][8].type = 2;
        tileSet[1][38][8].type = 2;
        tileSet[1][39][8].type = 2;

        //row 8
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 5 && i <= 11) || (i >= 16 && i <= 20) || (i >= 22 && i <= 27) || (i >= 30 && i <= 33) || i == 38 || (i >= 43 && i <= 49) || (i >= 51 && i <= 56) || (i >= 58 && i <= 61))
            {
                tileSet[1][i][9].type = 1;
                tileSet[1][i][9].isOn = 0;
            }
            else
            {
                tileSet[1][i][9].type = 1;
                tileSet[1][i][9].isOn = 1;
            }
        }
        tileSet[1][15][9].type = 2;
        tileSet[1][36][9].type = 2;
        tileSet[1][37][9].type = 2;
        tileSet[1][39][9].type = 2;
        tileSet[1][40][9].type = 2;

        //row 9
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ( i == 2 || (i >= 6 && i <= 10) || (i >= 14 && i <= 18) || (i >= 22 && i <= 26) || (i >= 30 && i <= 32) || (i >= 37 && i <= 38) || (i >= 43 && i <= 48) || (i >= 51 && i <= 54) || (i >= 58 && i <= 61))
            {
                tileSet[1][i][10].type = 1;
                tileSet[1][i][10].isOn = 0;
            }
            else
            {
                tileSet[1][i][10].type = 1;
                tileSet[1][i][10].isOn = 1;
            }
        }
        tileSet[1][15][10].type = 2;
        tileSet[1][35][10].type = 2;
        tileSet[1][36][10].type = 2;
        tileSet[1][39][10].type = 2;
        tileSet[1][40][10].type = 2;
        tileSet[1][41][10].type = 2;

        //row 10
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || i == 7 || (i >= 13 && i <= 17) || (i >= 20 && i <= 24) || (i >= 29 && i <= 31) || (i >= 37 && i <= 39) || (i >= 42 && i <= 46) || (i >= 51 && i <= 53) || (i >= 59 && i <= 61))
            {
                tileSet[1][i][11].type = 1;
                tileSet[1][i][11].isOn = 0;
            }
            else
            {
                tileSet[1][i][11].type = 1;
                tileSet[1][i][11].isOn = 1;
            }
        }
        tileSet[1][8][11].type = 2;
        tileSet[1][9][11].type = 2;
        tileSet[1][40][11].type = 2;
        tileSet[1][41][11].type = 2;

        //row 11
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || (i >= 12 && i <= 16) || (i >= 20 && i <= 23) || (i >= 27 && i <= 33) || (i >= 36 && i <= 39) || (i >= 42 && i <= 45) || (i >= 49 && i <= 55) || (i >= 59 && i <= 61))
            {
                tileSet[1][i][12].type = 1;
                tileSet[1][i][12].isOn = 0;
            }
            else
            {
                tileSet[1][i][12].type = 1;
                tileSet[1][i][12].isOn = 1;
            }
        }
        tileSet[1][5][12].type = 2;
        tileSet[1][6][12].type = 2;
        tileSet[1][7][12].type = 2;
        tileSet[1][8][12].type = 2;
        tileSet[1][41][12].type = 2;

        //row 12
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 12 && i <= 15) || (i >= 19 && i <= 22) || (i >= 25 && i <= 34) || (i >= 36 && i <= 38) || (i >= 41 && i <= 45) || (i >= 49 && i <= 56) || (i >= 59 && i <= 61))
            {
                tileSet[1][i][13].type = 1;
                tileSet[1][i][13].isOn = 0;
            }
            else
            {
                tileSet[1][i][13].type = 1;
                tileSet[1][i][13].isOn = 1;
            }
        }
        tileSet[1][6][13].type = 2;
        tileSet[1][7][13].type = 2;
        tileSet[1][8][13].type = 2;

        //row 13
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 13 && i <= 15) || (i >= 17 && i <= 21) || (i >= 25 && i <= 29) || (i >= 32 && i <= 37) || (i >= 41 && i <= 44) || (i >= 49 && i <= 56) || (i >= 59 && i <= 61))
            {
                tileSet[1][i][14].type = 1;
                tileSet[1][i][14].isOn = 0;
            }
            else
            {
                tileSet[1][i][14].type = 1;
                tileSet[1][i][14].isOn = 1;
            }
        }
        tileSet[1][7][14].type = 2;
        tileSet[1][8][14].type = 2;

        //row 14
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || (i >= 14 && i <= 20) || (i >= 25 && i <= 30) || (i >= 34 && i <= 36) || (i >= 40 && i <= 43) || (i >= 48 && i <= 57) || (i >= 60 && i <= 61))
            {
                tileSet[1][i][15].type = 1;
                tileSet[1][i][15].isOn = 0;
            }
            else
            {
                tileSet[1][i][15].type = 1;
                tileSet[1][i][15].isOn = 1;
            }
        }
        tileSet[1][8][15].type = 2;
        tileSet[1][9][15].type = 2;
        tileSet[1][10][15].type = 2;

        //row 15
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 8 && i <= 12) || (i >= 15 && i <= 19) || (i >= 25 && i <= 31)|| i == 35 || (i >= 39 && i <= 43) || (i >= 48 && i <= 53) || (i >= 55 && i <= 58) || (i >= 60 && i <= 61))
            {
                tileSet[1][i][16].type = 1;
                tileSet[1][i][16].isOn = 0;
            }
            else
            {
                tileSet[1][i][16].type = 1;
                tileSet[1][i][16].isOn = 1;
            }
        }
        tileSet[1][22][16].type = 2;
        tileSet[1][23][16].type = 2;
        tileSet[1][24][16].type = 2;
        tileSet[1][44][16].type = 2;
        tileSet[1][47][16].type = 2;

        //row 16
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 5) || (i >= 9 && i <= 12) || (i >= 16 && i <= 19) || (i >= 24 && i <= 32) || (i >= 38 && i <= 43) || (i >= 48 && i <= 52) || (i >= 56 && i <= 61))
            {
                tileSet[1][i][17].type = 1;
                tileSet[1][i][17].isOn = 0;
            }
            else
            {
                tileSet[1][i][17].type = 1;
                tileSet[1][i][17].isOn = 1;
            }
        }
        tileSet[1][20][17].type = 2;
        tileSet[1][21][17].type = 2;
        tileSet[1][22][17].type = 2;
        tileSet[1][23][17].type = 2;
        tileSet[1][44][17].type = 2;
        tileSet[1][45][17].type = 2;
        tileSet[1][47][17].type = 2;
        tileSet[1][55][17].type = 2;

        //row 17
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 6) || (i >= 10 && i <= 14) || (i >= 17 && i <= 20) || (i >= 23 && i <= 30) || (i >= 38 && i <= 44) || (i >= 48 && i <= 51) || (i >= 58 && i <= 61))
            {
                tileSet[1][i][18].type = 1;
                tileSet[1][i][18].isOn = 0;
            }
            else
            {
                tileSet[1][i][18].type = 1;
                tileSet[1][i][18].isOn = 1;
            }
        }
        tileSet[1][21][18].type = 2;
        tileSet[1][22][18].type = 2;
        tileSet[1][45][18].type = 2;
        tileSet[1][46][18].type = 2;
        tileSet[1][47][18].type = 2;
        tileSet[1][55][18].type = 2;
        tileSet[1][56][18].type = 2;

        //row 18
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 7) || (i >= 11 && i <= 14) || (i >= 18 && i <= 21) || (i >= 24 && i <= 28) || (i >= 33 && i <= 34) || (i >= 37 && i <= 44) || (i >= 47 && i <= 51) || (i >= 60 && i <= 61))
            {
                tileSet[1][i][19].type = 1;
                tileSet[1][i][19].isOn = 0;
            }
            else
            {
                tileSet[1][i][19].type = 1;
                tileSet[1][i][19].isOn = 1;
            }
        }
        tileSet[1][22][19].type = 2;
        tileSet[1][29][19].type = 3;
        tileSet[1][45][19].type = 2;
        tileSet[1][46][19].type = 2;
        tileSet[1][54][19].type = 2;
        tileSet[1][55][19].type = 2;
        tileSet[1][56][19].type = 2;

        //row 19
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 5 && i <= 8) || (i >= 12 && i <= 15) || (i >= 18 && i <= 20) || (i >= 25 && i <= 27) || (i >= 32 && i <= 35) || (i >= 37 && i <= 45) || (i >= 47 && i <= 50) || i == 55 ||  i == 61)
            {
                tileSet[1][i][20].type = 1;
                tileSet[1][i][20].isOn = 0;
            }
            else
            {
                tileSet[1][i][20].type = 1;
                tileSet[1][i][20].isOn = 1;
            }
        }
        tileSet[1][46][20].type = 2;
        tileSet[1][54][20].type = 2;
        tileSet[1][56][20].type = 2;
        tileSet[1][57][20].type = 2;

        //row 20
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 6 && i <= 9) || (i >= 13 && i <= 16) || (i >= 18 && i <= 21) || (i >= 25 && i <= 28) || (i >= 33 && i <= 42) || (i >= 47 && i <= 49) || (i >= 54 && i <= 56))
            {
                tileSet[1][i][21].type = 1;
                tileSet[1][i][21].isOn = 0;
            }
            else
            {
                tileSet[1][i][21].type = 1;
                tileSet[1][i][21].isOn = 1;
            }
        }
        tileSet[1][46][21].type = 2;
        tileSet[1][53][21].type = 2;
        tileSet[1][57][21].type = 2;

        //row 21
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 7 && i <= 10) || (i >= 12 && i <= 22) || (i >= 26 && i <= 29) || (i >= 34 && i <= 38) || (i >= 53 && i <= 59))
            {
                tileSet[1][i][22].type = 1;
                tileSet[1][i][22].isOn = 0;
            }
            else
            {
                tileSet[1][i][22].type = 1;
                tileSet[1][i][22].isOn = 1;
            }
        }
        tileSet[1][41][22].type = 2;
        tileSet[1][42][22].type = 2;
        tileSet[1][43][22].type = 2;

        //row 22
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 5 && i <= 8) || (i >= 12 && i <= 23) || (i >= 27 && i <= 31) || (i >= 35 && i <= 37) || (i >= 53 && i <= 60))
            {
                tileSet[1][i][23].type = 1;
                tileSet[1][i][23].isOn = 0;
            }
            else
            {
                tileSet[1][i][23].type = 1;
                tileSet[1][i][23].isOn = 1;
            }
        }
        tileSet[1][40][23].type = 2;
        tileSet[1][41][23].type = 2;
        tileSet[1][42][23].type = 2;
        tileSet[1][43][23].type = 2;
        tileSet[1][44][23].type = 2;

        //row 23
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 7) || (i >= 11 && i <= 16) || (i >= 19 && i <= 25) || (i >= 29 && i <= 32) || (i >= 36 && i <= 38) || (i >= 52 && i <= 56) || i == 57 || (i >= 58 && i <= 61))
            {
                tileSet[1][i][24].type = 1;
                tileSet[1][i][24].isOn = 0;
            }
            else
            {
                tileSet[1][i][24].type = 1;
                tileSet[1][i][24].isOn = 1;
            }
        }
        tileSet[1][41][24].type = 2;
        tileSet[1][42][24].type = 2;
        tileSet[1][43][24].type = 2;
        tileSet[1][44][24].type = 2;
        tileSet[1][45][24].type = 2;

        //row 24
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 6) || (i >= 10 && i <= 14) || (i >= 21 && i <= 38) || (i >= 45 && i <= 47) || (i >= 51 && i <= 56) || (i >= 59 && i <= 61))
            {
                tileSet[1][i][25].type = 1;
                tileSet[1][i][25].isOn = 0;
            }
            else
            {
                tileSet[1][i][25].type = 1;
                tileSet[1][i][25].isOn = 1;
            }
        }
        tileSet[1][42][25].type = 2;
        tileSet[1][43][25].type = 2;
        tileSet[1][44][25].type = 2;

        //row 25
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 9 && i <= 13) || (i >= 22 && i <= 39) || (i >= 45 && i <= 48) || (i >= 51 && i <= 55) || (i >= 59 && i <= 61))
            {
                tileSet[1][i][26].type = 1;
                tileSet[1][i][26].isOn = 0;
            }
            else
            {
                tileSet[1][i][26].type = 1;
                tileSet[1][i][26].isOn = 1;
            }
        }
        tileSet[1][44][26].type = 2;

        //row 26
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 9 && i <= 16) || (i >= 21 && i <= 39) || (i >= 43 && i <= 49) || (i >= 51 && i <= 57) || (i >= 60 && i <= 61))
            {
                tileSet[1][i][27].type = 1;
                tileSet[1][i][27].isOn = 0;
            }
            else
            {
                tileSet[1][i][27].type = 1;
                tileSet[1][i][27].isOn = 1;
            }
        }

        //row 27
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 10 && i <= 18) || (i >= 20 && i <= 27) || (i >= 31 && i <= 32) || (i >= 36 && i <= 38) || (i >= 42 && i <= 58) || i == 61)
            {
                tileSet[1][i][28].type = 1;
                tileSet[1][i][28].isOn = 0;
            }
            else
            {
                tileSet[1][i][28].type = 1;
                tileSet[1][i][28].isOn = 1;
            }
        }

        //row 28
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 7) || (i >= 11 && i <= 15) || (i >= 17 && i <= 26) || (i >= 30 && i <= 33) || i == 37 || (i >= 41 && i <= 59))
            {
                tileSet[1][i][29].type = 1;
                tileSet[1][i][29].isOn = 0;
            }
            else
            {
                tileSet[1][i][29].type = 1;
                tileSet[1][i][29].isOn = 1;
            }
        }
        tileSet[1][16][29].type = 2;

        //row 29
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 8) || (i >= 12 && i <= 15) || (i >= 18 && i <= 25) || (i >= 29 && i <= 34) || (i >= 40 && i <= 46) || (i >= 48 && i <= 60))
            {
                tileSet[1][i][30].type = 1;
                tileSet[1][i][30].isOn = 0;
            }
            else
            {
                tileSet[1][i][30].type = 1;
                tileSet[1][i][30].isOn = 1;
            }
        }
        tileSet[1][16][30].type = 2;

        //row 30
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 3 && i <= 9) || (i >= 13 && i <= 14) || (i >= 19 && i <= 25) || (i >= 28 && i <= 34) || (i >= 39 && i <= 46) || (i >= 48 && i <= 60))
            {
                tileSet[1][i][31].type = 1;
                tileSet[1][i][31].isOn = 0;
            }
            else
            {
                tileSet[1][i][31].type = 1;
                tileSet[1][i][31].isOn = 1;
            }
        }
        tileSet[1][15][31].type = 2;
        tileSet[1][16][31].type = 2;
        tileSet[1][17][31].type = 2;

        //row 31
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 13) || (i >= 20 && i <= 24) || (i >= 29 && i <= 35) || (i >= 39 && i <= 45) || (i >= 48 && i <= 55 ) || ( i >= 57 && i <= 59))
            {
                tileSet[1][i][32].type = 1;
                tileSet[1][i][32].isOn = 0;
            }
            else if (i == 56){
                tileSet[1][i][32].isOn = 1;
                tileSet[1][i][32].type = 4;
            }
            else
            {
                tileSet[1][i][32].type = 1;
                tileSet[1][i][32].isOn = 1;
            }
        }
        tileSet[1][14][32].type = 2;
        tileSet[1][15][32].type = 2;
        tileSet[1][17][32].type = 2;

        //row 32
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 6 && i <= 12) || (i >= 21 && i <= 23) || (i >= 30 && i <= 36) || (i >= 40 && i <= 44) || (i >= 49 && i <= 57))
            {
                tileSet[1][i][33].type = 1;
                tileSet[1][i][33].isOn = 0;
            }
            else
            {
                tileSet[1][i][33].type = 1;
                tileSet[1][i][33].isOn = 1;
            }
        }
        tileSet[1][13][33].type = 2;
        tileSet[1][14][33].type = 2;
        tileSet[1][18][33].type = 2;

        break;

    case 2:

        //row 1
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 6 && i <= 10) || (i >= 16 && i <= 17) || (i >= 25 && i <= 42) || (i >= 52 && i <= 54))
            {
                tileSet[2][i][2].type = 1;
                tileSet[2][i][2].isOn = 0;
            }
            else
            {
                tileSet[2][i][2].type = 1;
                tileSet[2][i][2].isOn = 1;
            }
        }

        tileSet[2][43][2].type = 2;
        tileSet[2][44][2].type = 2;
        tileSet[2][51][2].type = 2;

        //row 2
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 6 && i <= 11) || (i >= 15 && i <= 18) || (i >= 25 && i <= 43) || (i >= 52 && i <= 54) || (i >= 57 && i <= 60))
            {
                tileSet[2][i][3].type = 1;
                tileSet[2][i][3].isOn = 0;
            }
            else
            {
                tileSet[2][i][3].type = 1;
                tileSet[2][i][3].isOn = 1;
            }
        }

        tileSet[2][44][3].type = 2;
        tileSet[2][45][3].type = 2;
        tileSet[2][50][3].type = 2;
        tileSet[2][51][3].type = 2;

        //row 3
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 7 && i <= 11) || (i >= 15 && i <= 17) || (i >= 24 && i <= 30)|| i == 33 || (i >= 36 && i <= 44) || (i >= 52 && i <= 53) || (i >= 56 && i <= 58) || (i >= 60 && i <= 61))
            {
                tileSet[2][i][4].type = 1;
                tileSet[2][i][4].isOn = 0;
            }
            else if (i == 59) {
                tileSet[2][i][4].isOn = 1;
                tileSet[2][i][4].type = 4;
            }
            else
            {
                tileSet[2][i][4].type = 1;
                tileSet[2][i][4].isOn = 1;
            }
        }

        tileSet[2][34][4].type = 2;
        tileSet[2][35][4].type = 2;
        tileSet[2][45][4].type = 2;
        tileSet[2][46][4].type = 2;
        tileSet[2][50][4].type = 2;
        tileSet[2][51][4].type = 2;

        //row 4
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 22 && i <= 29) || (i >= 24 && i <= 30) || (i >= 38 && i <= 45) || (i >= 51 && i <= 53) || (i >= 56 && i <= 61))
            {
                tileSet[2][i][5].type = 1;
                tileSet[2][i][5].isOn = 0;
            }
            else
            {
                tileSet[2][i][5].type = 1;
                tileSet[2][i][5].isOn = 1;
            }
        }

        tileSet[2][9][5].type = 2;
        tileSet[2][10][5].type = 2;
        tileSet[2][11][5].type = 2;
        tileSet[2][15][5].type = 2;
        tileSet[2][17][5].type = 2;
        tileSet[2][35][5].type = 2;
        tileSet[2][36][5].type = 2;
        tileSet[2][37][5].type = 2;
        tileSet[2][46][5].type = 2;
        tileSet[2][47][5].type = 2;
        tileSet[2][49][5].type = 2;
        tileSet[2][50][5].type = 2;


        //row 5
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 8 && i <= 12) || (i >= 15 && i <= 19) || (i >= 21 && i <= 25) || (i >= 27 && i <= 29) || i == 33 || (i >= 39 && i <= 46) || (i >= 50 && i <= 53) || (i >= 56 && i <= 61))
            {
                tileSet[2][i][6].type = 1;
                tileSet[2][i][6].isOn = 0;
            }
            else
            {
                tileSet[2][i][6].type = 1;
                tileSet[2][i][6].isOn = 1;
            }
        }

        tileSet[2][37][6].type = 2;
        tileSet[2][38][6].type = 2;
        tileSet[2][47][6].type = 2;
        tileSet[2][48][6].type = 2;
        tileSet[2][49][6].type = 2;

        //row 6
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 9 && i <= 13) || (i >= 15 && i <= 19) || (i >= 21 && i <= 24) || (i >= 27 && i <= 28) || (i >= 32 && i <= 34) || i == 36 || (i >= 41 && i <= 47) || (i >= 50 && i <= 52) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][7].type = 1;
                tileSet[2][i][7].isOn = 0;
            }
            else
            {
                tileSet[2][i][7].type = 1;
                tileSet[2][i][7].isOn = 1;
            }
        }

        tileSet[2][37][7].type = 2;
        tileSet[2][38][7].type = 2;
        tileSet[2][39][7].type = 2;
        tileSet[2][40][7].type = 2;
        tileSet[2][48][7].type = 2;
        tileSet[2][49][7].type = 2;

        //row 7
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 10 && i <= 23) || (i >= 28 && i <= 38) || (i >= 42 && i <= 43) || (i >= 45 && i <= 48) || (i >= 50 && i <= 52) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][8].type = 1;
                tileSet[2][i][8].isOn = 0;
            }
            else
            {
                tileSet[2][i][8].type = 1;
                tileSet[2][i][8].isOn = 1;
            }
        }

        tileSet[2][24][8].type = 2;
        tileSet[2][39][8].type = 2;
        tileSet[2][41][8].type = 2;
        tileSet[2][49][8].type = 2;

        //row 8
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 7) || (i >= 11 && i <= 22) || (i >= 27 && i <= 38) || (i >= 42 && i <= 43) || (i >= 47 && i <= 52) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][9].type = 1;
                tileSet[2][i][9].isOn = 0;
            }
            else
            {
                tileSet[2][i][9].type = 1;
                tileSet[2][i][9].isOn = 1;
            }
        }

        tileSet[2][23][9].type = 2;
        tileSet[2][24][9].type = 2;
        tileSet[2][25][9].type = 2;

        //row 9
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 9) || (i >= 12 && i <= 21) || (i >= 25 && i <= 39) || (i >= 42 && i <= 44) || (i >= 48 && i <= 52) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][10].type = 1;
                tileSet[2][i][10].isOn = 0;
            }
            else
            {
                tileSet[2][i][10].type = 1;
                tileSet[2][i][10].isOn = 1;
            }
        }

        tileSet[2][22][10].type = 2;
        tileSet[2][23][10].type = 2;

        //row 10
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 21) || (i >= 24 && i <= 28) || (i >= 36 && i <= 39) || (i >= 43 && i <= 45) || (i >= 49 && i <= 51) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][11].type = 1;
                tileSet[2][i][11].isOn = 0;
            }
            else
            {
                tileSet[2][i][11].type = 1;
                tileSet[2][i][11].isOn = 1;
            }
        }

        //row 11
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || (i >= 6 && i <= 13) || (i >= 18 && i <= 20) || (i >= 24 && i <= 27) || (i >= 30 && i <= 34) || (i >= 37 && i <= 45) || (i >= 50 && i <= 51) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][12].type = 1;
                tileSet[2][i][12].isOn = 0;
            }
            else
            {
                tileSet[2][i][12].type = 1;
                tileSet[2][i][12].isOn = 1;
            }
        }

        //row 12
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 7 && i <= 12) || (i >= 17 && i <= 20) || (i >= 23 && i <= 26) || (i >= 29 && i <= 35) || (i >= 38 && i <= 41) || (i >= 43 && i <= 45) || (i >= 50 && i <= 51) || (i >= 54 && i <= 61))
            {
                tileSet[2][i][13].type = 1;
                tileSet[2][i][13].isOn = 0;
            }
            else
            {
                tileSet[2][i][13].type = 1;
                tileSet[2][i][13].isOn = 1;
            }
        }

        //row 13
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 8 && i <= 11) || (i >= 17 && i <= 19) || (i >= 23 && i <= 26) || (i >= 28 && i <= 36) || (i >= 38 && i <= 41) || (i >= 44 && i <= 46) || (i >= 49 && i <= 51) || (i >= 54 && i <= 60))
            {
                tileSet[2][i][14].type = 1;
                tileSet[2][i][14].isOn = 0;
            }
            else
            {
                tileSet[2][i][14].type = 1;
                tileSet[2][i][14].isOn = 1;
            }
        }
        tileSet[2][53][14].type = 2;

        //row 14
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 8 && i <= 10) || (i >= 16 && i <= 19) || (i >= 23 && i <= 26) || (i >= 30 && i <= 32) || (i >= 35 && i <= 36) || ( i >= 38 && i <= 41) || (i >= 44 && i <= 47) || (i >= 49 && i <= 51) || (i >= 54 && i <= 59))
            {
                tileSet[2][i][15].type = 1;
                tileSet[2][i][15].isOn = 0;
            }
            else
            {
                tileSet[2][i][15].type = 1;
                tileSet[2][i][15].isOn = 1;
            }
        }
        tileSet[2][21][15].type = 2;
        tileSet[2][22][15].type = 2;
        tileSet[2][52][15].type = 2;
        tileSet[2][53][15].type = 2;

        //row 15
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || (i >= 7 && i <= 11) || (i >= 16 && i <= 19) || (i >= 23 && i <= 26) || i == 30 || i == 32 || (i >= 35 && i <= 36) || (i >= 38 && i <= 41) || (i >= 44 && i <= 50) || (i >= 54 && i <= 56))
            {
                tileSet[2][i][16].type = 1;
                tileSet[2][i][16].isOn = 0;
            }
            else
            {
                tileSet[2][i][16].type = 1;
                tileSet[2][i][16].isOn = 1;
            }
        }

        tileSet[2][20][16].type = 2;
        tileSet[2][21][16].type = 2;
        tileSet[2][31][16].type = 3;
        tileSet[2][51][16].type = 2;
        tileSet[2][52][16].type = 2;
        tileSet[2][53][16].type = 2;

        //row 16
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 4) || (i >= 7 && i <= 12) || (i >= 16 && i <= 19) || (i >= 23 && i <= 26) || ( i >= 28 && i <= 36) || (i >= 38 && i <= 41) || (i >= 44 && i <= 50))
            {
                tileSet[2][i][17].type = 1;
                tileSet[2][i][17].isOn = 0;
            }
            else
            {
                tileSet[2][i][17].type = 1;
                tileSet[2][i][17].isOn = 1;
            }
        }
        tileSet[2][20][17].type = 2;
        tileSet[2][21][17].type = 2;
        tileSet[2][22][17].type = 2;
        tileSet[2][51][17].type = 2;

        //row 17
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 7 && i <= 13) || (i >= 16 && i <= 19) || (i >= 24 && i <= 26) || (i >= 28 && i <= 35) || (i >= 38 && i <= 41) || (i >= 44 && i <= 50))
            {
                tileSet[2][i][18].type = 1;
                tileSet[2][i][18].isOn = 0;
            }
            else
            {
                tileSet[2][i][18].type = 1;
                tileSet[2][i][18].isOn = 1;
            }
        }
        tileSet[2][20][18].type = 2;
        tileSet[2][22][18].type = 2;
        tileSet[2][23][18].type = 2;

        //row 18
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 13) || (i >= 15 && i <= 20) || (i >= 24 && i <= 26) || (i >= 29 && i <= 33) || (i >= 38 && i <= 40) || (i >= 43 && i <= 47))
            {
                tileSet[2][i][19].type = 1;
                tileSet[2][i][19].isOn = 0;
            }
            else
            {
                tileSet[2][i][19].type = 1;
                tileSet[2][i][19].isOn = 1;
            }
        }

        tileSet[2][23][19].type = 2;

        //row 19
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 8) || (i >= 10 && i <= 20) || (i >= 23 && i <= 27) || i == 29 || i == 31 || i == 33 || (i >= 37 && i <= 49))
            {
                tileSet[2][i][20].type = 1;
                tileSet[2][i][20].isOn = 0;
            }
            else
            {
                tileSet[2][i][20].type = 1;
                tileSet[2][i][20].isOn = 1;
            }
        }

        //row 20
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 7) || (i >= 10 && i <= 21) || (i >= 24 && i <= 27) || i == 29 || i == 31 || i == 33 || (i >= 35 && i <= 51))
            {
                tileSet[2][i][21].type = 1;
                tileSet[2][i][21].isOn = 0;
            }
            else
            {
                tileSet[2][i][21].type = 1;
                tileSet[2][i][21].isOn = 1;
            }
        }

        //row 21
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 10 && i <= 16) || (i >= 19 && i <= 39) || (i >= 41 && i <= 45) || (i >= 47 && i <= 56))
            {
                tileSet[2][i][22].type = 1;
                tileSet[2][i][22].isOn = 0;
            }
            else
            {
                tileSet[2][i][22].type = 1;
                tileSet[2][i][22].isOn = 1;
            }
        }


        //row 22
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 6) || (i >= 9 && i <= 13) || (i >= 18 && i <= 23) || (i >= 25 && i <= 38) || (i >= 41 && i <= 43) || (i >= 47 && i <= 59))
            {
                tileSet[2][i][23].type = 1;
                tileSet[2][i][23].isOn = 0;
            }
            else
            {
                tileSet[2][i][23].type = 1;
                tileSet[2][i][23].isOn = 1;
            }
        }

        //row 23
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 9 && i <= 12) || (i >= 16 && i <= 23) || (i >= 26 && i <= 35) || (i >= 41 && i <= 43) || (i >= 46 && i <= 61))
            {
                tileSet[2][i][24].type = 1;
                tileSet[2][i][24].isOn = 0;
            }
            else
            {
                tileSet[2][i][24].type = 1;
                tileSet[2][i][24].isOn = 1;
            }
        }
        tileSet[2][36][24].type = 2;
        tileSet[2][37][24].type = 2;
        tileSet[2][40][24].type = 2;

        //row 24
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 9 && i <= 11) || (i >= 14 && i <= 26) || (i >= 30 && i <= 33) || (i >= 40 && i <= 42) || (i >= 46 && i <= 61))
            {
                tileSet[2][i][25].type = 1;
                tileSet[2][i][25].isOn = 0;
            }
            else
            {
                tileSet[2][i][25].type = 1;
                tileSet[2][i][25].isOn = 1;
            }
        }
        tileSet[2][37][25].type = 2;
        tileSet[2][38][25].type = 2;
        tileSet[2][39][25].type = 2;

        //row 25
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 13 && i <= 18) || (i >= 20 && i <= 27) || (i >= 38 && i <= 42) || (i >= 46 && i <= 50) || (i >= 52 && i <= 61))
            {
                tileSet[2][i][26].type = 1;
                tileSet[2][i][26].isOn = 0;
            }
            else
            {
                tileSet[2][i][26].type = 1;
                tileSet[2][i][26].isOn = 1;
            }
        }
        tileSet[2][36][26].type = 2;
        tileSet[2][37][26].type = 2;

        //row 26
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 5) || (i >= 12 && i <= 17) || (i >= 23 && i <= 30) || (i >= 35 && i <= 39) || (i >= 46 && i <= 50) || (i >= 52 && i <= 61))
            {
                tileSet[2][i][27].type = 1;
                tileSet[2][i][27].isOn = 0;
            }
            else
            {
                tileSet[2][i][27].type = 1;
                tileSet[2][i][27].isOn = 1;
            }
        }

        //row 27
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 9 && i <= 15) || (i >= 22 && i <= 40) || (i >= 45 && i <= 49) || (i >= 53 && i <= 61))
            {
                tileSet[2][i][28].type = 1;
                tileSet[2][i][28].isOn = 0;
            }
            else
            {
                tileSet[2][i][28].type = 1;
                tileSet[2][i][28].isOn = 1;
            }
        }

        //row 28
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 7 && i <= 16) || (i >= 21 && i <= 28) || (i >= 30 && i <= 42) || ( i >= 45 && i <= 49) || (i >= 53 && i <= 61))
            {
                tileSet[2][i][29].type = 1;
                tileSet[2][i][29].isOn = 0;
            }
            else
            {
                tileSet[2][i][29].type = 1;
                tileSet[2][i][29].isOn = 1;
            }
        }

        //row 29
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 2 && i <= 3) || (i >= 7 && i <= 12) || ( i >= 14 && i <= 16 ) || (i >= 21 && i <= 26) || (i >= 32 && i <= 43) || (i >= 45 && i <= 48) || (i >= 53 && i <= 61))
            {
                tileSet[2][i][30].type = 1;
                tileSet[2][i][30].isOn = 0;
            }
            else
            {
                tileSet[2][i][30].type = 1;
                tileSet[2][i][30].isOn = 1;
            }
        }

        //row 30
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ( i == 2 || (i >= 6 && i <= 11) || (i >= 15 && i <= 17) || (i >= 20 && i <= 25) || (i >= 36 && i <= 48) || (i >= 54 && i <= 61))
            {
                tileSet[2][i][31].type = 1;
                tileSet[2][i][31].isOn = 0;
            }
            else
            {
                tileSet[2][i][31].type = 1;
                tileSet[2][i][31].isOn = 1;
            }
        }
        tileSet[2][12][31].type = 2;

        //row 31
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 5 && i <= 10) || (i >= 16 && i <= 29) || (i >= 34 && i <= 47) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][32].type = 1;
                tileSet[2][i][32].isOn = 0;
            }
            else
            {
                tileSet[2][i][32].type = 1;
                tileSet[2][i][32].isOn = 1;
            }
        }
        tileSet[2][11][32].type = 2;
        tileSet[2][12][32].type = 2;

        //row 32
        for (int i = 1; i <= numOfTilesX - 2; i++)
        {
            if ((i >= 4 && i <= 9) || (i >= 17 && i <= 46) || (i >= 55 && i <= 61))
            {
                tileSet[2][i][33].type = 1;
                tileSet[2][i][33].isOn = 0;
            }
            else
            {
                tileSet[2][i][33].type = 1;
                tileSet[2][i][33].isOn = 1;
            }
        }
        tileSet[2][10][33].type = 2;
        tileSet[2][11][33].type = 2;
        tileSet[2][12][33].type = 2;
        tileSet[2][13][33].type = 2;

        break;
    }
}
