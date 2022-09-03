#include "cprocessing.h"
#include <stdio.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 200

#define COLOR_RED CP_Color_Create(255, 0, 0, 255)
#define COLOR_GREEN CP_Color_Create(0, 255, 0, 255)
#define COLOR_BLUE CP_Color_Create(0, 0, 255, 255)
#define COLOR_CYAN CP_Color_Create(0,255,255,255)
#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

CP_Image background;
CP_Image levelselectbutton;
CP_Image levelselectbuttonpressed;
CP_Image levelselect;
CP_Image backbutton;
CP_Image backbuttonpressed;
CP_Image level1;
CP_Image level2;
CP_Image level3;


extern int levelCounter;

int levelselection;

static int is_btn_colliding(float x, float y, float buttonX, float buttonY) {
	return x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT;
}
//Foward declarations
void game_init(void);
void game_update(void);
void game_exit(void);

void mainmenu_init(void);
void mainmenu_update(void);
void mainmenu_exit(void);

void level_select_init()
{
    level1 = CP_Image_Load("./Assets/Level1.png");
    level2 = CP_Image_Load("./Assets/Level2.png");
    level3 = CP_Image_Load("./Assets/Level3.png");
    backbuttonpressed = CP_Image_Load("./Assets/BackButtonPressed.png");
    backbutton = CP_Image_Load("./Assets/BackButton.png");
    levelselect = CP_Image_Load("./Assets/levelselect.png");
    levelselectbutton = CP_Image_Load("./Assets/levelselectbutton.png");
    levelselectbuttonpressed = CP_Image_Load("./Assets/levelselectbuttonpressed.png");
    background = CP_Image_Load("./Assets/Background.png");
}

void level_select_update()
{
    float height = (float)CP_System_GetWindowHeight();
    float width = (float)CP_System_GetWindowWidth();

    //1-1 button position
    float OnePositionX = (width / 4) - 50;
    float OnePositionY = (height / 2);

    //1-2 button position
    float TwoPositionX = ((width / 4) * 2) - 50;
    float TwoPositionY = (height / 2);

    //1-3 button position
    float ThreePositionX = ((width / 4) * 3) - 50;
    float ThreePositionY = (height / 2);

    //Quit button position
    float QuitButtonPositionX = ((width / 4) * 3) - 100;
    float QuitButtonPositionY = (height / 4) * 3;

    if (CP_Input_MouseClicked())
    {
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), OnePositionX - 100, OnePositionY - 100))
        {
            levelCounter = 0;
            CP_Engine_SetNextGameState(game_init, game_update, game_exit);
            CP_Engine_Run();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), TwoPositionX - 100, TwoPositionY - 100))
        {
            levelCounter = 1;
            CP_Engine_SetNextGameState(game_init, game_update, game_exit);
            CP_Engine_Run();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), ThreePositionX - 100, ThreePositionY - 100))
        {
            levelCounter = 2;
            CP_Engine_SetNextGameState(game_init, game_update, game_exit);
            CP_Engine_Run();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX, QuitButtonPositionY)) //Back to mainmenu
        {
            CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
            CP_Engine_Run();
        }
    }

    CP_Graphics_ClearBackground(CP_Color_Create(84, 84, 84, 255));
    CP_Image_Draw(background, (float)(CP_System_GetDisplayWidth() / 2), (float)(CP_System_GetDisplayHeight() / 2), 1920, 1080, 255);
    CP_Image_Draw(levelselect, (float)(CP_System_GetDisplayWidth() / 2), 300, 1200, 100, 255);

    //Level 1-1 Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(OnePositionX - 50, OnePositionY - 100, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(levelselectbuttonpressed, (width / 4), (height / 2), 360, 360, 255);

    CP_Image_Draw(level1, (width / 4), 700, 60, 44, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), OnePositionX - 50, OnePositionY - 100))
    {
        CP_Image_Draw(levelselectbutton, (width / 4), (height / 2) - 2, 380, 380, 255);
    }


    //Level 1-2 Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(TwoPositionX - 50, TwoPositionY - 100, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(levelselectbuttonpressed, ((width / 4) * 2), (height / 2), 360, 360, 255);

    CP_Image_Draw(level2, ((width / 4) * 2), 700, 60, 44, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), TwoPositionX - 50, TwoPositionY - 100))
    {
        CP_Image_Draw(levelselectbutton, ((width / 4) * 2), (height / 2) - 2, 380, 380, 255);
    }


    //Level 1-3 Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(ThreePositionX - 50, ThreePositionY - 100, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(levelselectbuttonpressed, ((width / 4) * 3), (height / 2), 360, 360, 255);

    CP_Image_Draw(level3, ((width / 4) * 3), 700, 60, 44, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), ThreePositionX - 50, ThreePositionY - 100))
    {
        CP_Image_Draw(levelselectbutton, ((width / 4) * 3), (height / 2) - 2, 380, 380, 255);
    }


    //Back Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(QuitButtonPositionX, QuitButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT - 150);
    CP_Image_Draw(backbutton, (width / 4) * 3, ((height / 4) * 3) + 25, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX, QuitButtonPositionY))
    {
        CP_Image_Draw(backbuttonpressed, (width / 4) * 3, ((height / 4) * 3) +25, 200, 50, 255);
    }
}

void level_select_exit()
{

}
