#include <stdlib.h>
#include <stdio.h>
#include "cprocessing.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50

#define COLOR_RED CP_Color_Create(255, 0, 0, 255)
#define COLOR_GREEN CP_Color_Create(0, 255, 0, 255)
#define COLOR_BLUE CP_Color_Create(0, 0, 255, 255)
#define COLOR_CYAN CP_Color_Create(0,255,255,255)
#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

void mainmenu_init(void);
void mainmenu_update(void);
void mainmenu_exit(void);

CP_Image credits;
CP_Image backbutton;
CP_Image backbuttonpressed;

static int is_btn_colliding(float x, float y, float buttonX, float buttonY) {
    return x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT;
}

void credits_init()
{
    backbuttonpressed = CP_Image_Load("./Assets/BackButtonPressed.png");
    backbutton = CP_Image_Load("./Assets/BackButton.png");
    credits = CP_Image_Load("./Assets/Credits.png");
    CP_System_Fullscreen();
}

void credits_update()
{
    float QuitButtonPositionX = 1800;
    float QuitButtonPositionY = 1025;

    if (CP_Input_MouseClicked())
    {
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX - 100, QuitButtonPositionY - 25))
        {
            CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
            CP_Engine_Run();
        }
    }

    CP_Graphics_ClearBackground(CP_Color_Create(84, 84, 84, 255));
    CP_Image_Draw(credits, (float)(CP_System_GetDisplayWidth() / 2), (float)(CP_System_GetDisplayHeight() / 2), 1920, 1080, 255);
    

    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(QuitButtonPositionX-100, QuitButtonPositionY-25, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(backbutton, 1800, 1025, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX - 100, QuitButtonPositionY - 25))
    {
        CP_Image_Draw(backbuttonpressed, 1800, 1025, 200, 50, 255);
    }
}

void credits_exit()
{

}

