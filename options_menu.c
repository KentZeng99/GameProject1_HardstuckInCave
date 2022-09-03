#include <stdlib.h>
#include <stdbool.h>
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

void game_init(void);
void game_update(void);
void game_exit(void);

CP_Image background;
CP_Image mutebutton;
CP_Image mutebuttonpressed;
CP_Image skinbutton1;
CP_Image skinbuttonpressed1;
CP_Image skinbutton2;
CP_Image skinbuttonpressed2;
CP_Image skinbutton3;
CP_Image skinbuttonpressed3;
CP_Image redskin;
CP_Image blueskin;
CP_Image yellowskin;
CP_Image backbutton;
CP_Image backbuttonpressed;

extern bool mute;
extern int playercounter;

static int is_btn_colliding(float x, float y, float buttonX, float buttonY) {
    return x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT;
}

void options_init()
{
    background = CP_Image_Load("./Assets/Background.png");
    backbuttonpressed = CP_Image_Load("./Assets/BackButtonPressed.png");
    backbutton = CP_Image_Load("./Assets/BackButton.png");
    mutebutton = CP_Image_Load("./Assets/MuteButton.png");
    mutebuttonpressed = CP_Image_Load("./Assets/MuteButtonPressed.png");
    skinbutton1 = CP_Image_Load("./Assets/ChangeSkinButton.png");
    skinbuttonpressed1 = CP_Image_Load("./Assets/ChangeSkinButtonPressed.png");
    skinbutton2 = CP_Image_Load("./Assets/ChangeSkinButton.png");
    skinbuttonpressed2 = CP_Image_Load("./Assets/ChangeSkinButtonPressed.png");
    skinbutton3 = CP_Image_Load("./Assets/ChangeSkinButton.png");
    skinbuttonpressed3 = CP_Image_Load("./Assets/ChangeSkinButtonPressed.png");
    redskin = CP_Image_Load("./Assets/Avatar1.png");
    blueskin = CP_Image_Load("./Assets/Avatar2.png");
    yellowskin = CP_Image_Load("./Assets/Avatar3.png");
    CP_System_Fullscreen();
}

void options_update()
{
    float width = (float)CP_System_GetWindowWidth();

    float MuteButtonPositionX = (width / 4) * 2;
    float MuteButtonPositionY = 300;

    float Skin1ButtonPositionX = (width / 4);
    float Skin1ButtonPositionY = 500;

    float Skin2ButtonPositionX = (width / 4) * 2;
    float Skin2ButtonPositionY = 500;

    float Skin3ButtonPositionX = (width / 4) * 3;
    float Skin3ButtonPositionY = 500;

    float BackButtonPositionX = (width / 4) * 2;
    float BackButtonPositionY = 1000;


    CP_Graphics_ClearBackground(CP_Color_Create(84, 84, 84, 255));
    CP_Image_Draw(background, (float)(CP_System_GetDisplayWidth() / 2), (float)(CP_System_GetDisplayHeight() / 2), 1920, 1080, 255);

    //back button
    if (CP_Input_MouseClicked())
    {
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY - 25))
        {
            CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
            CP_Engine_Run();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), MuteButtonPositionX - 100, MuteButtonPositionY - 25))
        {
            if (!mute) {
                mute = true;
            }
            else {
                mute = false;
            }
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), Skin1ButtonPositionX - 100, Skin1ButtonPositionY - 25))
        {
            playercounter = 0;
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), Skin2ButtonPositionX - 100, Skin2ButtonPositionY - 25))
        {
            playercounter = 1;
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), Skin3ButtonPositionX - 100, Skin3ButtonPositionY - 25))
        {
            playercounter = 2;
        }
    }

    //mute button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(MuteButtonPositionX - 100, MuteButtonPositionY - 25, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(mutebutton, (width / 4) * 2, 300, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), MuteButtonPositionX - 100, MuteButtonPositionY - 25))
    {
        CP_Image_Draw(mutebuttonpressed, (width / 4) * 2, 300, 200, 50, 255);
    }

    //Change skin 1
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(Skin1ButtonPositionX - 100, Skin1ButtonPositionY - 25, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(redskin, (width / 4), 650, 250, 250, 255);
    CP_Image_Draw(skinbutton1, (width / 4), 500, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), Skin1ButtonPositionX - 100, Skin1ButtonPositionY - 25))
    {
        CP_Image_Draw(skinbuttonpressed1, (width / 4), 500, 200, 50, 255);
    }

    //Change skin 2
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(Skin2ButtonPositionX - 100, Skin2ButtonPositionY - 25, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(blueskin, (width / 4)*2, 650, 250, 250, 255);
    CP_Image_Draw(skinbutton2, (width / 4)*2, 500, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), Skin2ButtonPositionX - 100, Skin2ButtonPositionY - 25))
    {
        CP_Image_Draw(skinbuttonpressed2, (width / 4)*2, 500, 200, 50, 255);
    }

    //Change skin 3
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(Skin3ButtonPositionX - 100, Skin3ButtonPositionY - 25, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(yellowskin, (width / 4)*3, 650, 250, 250, 255);
    CP_Image_Draw(skinbutton1, (width / 4)*3, 500, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), Skin3ButtonPositionX - 100, Skin3ButtonPositionY - 25))
    {
        CP_Image_Draw(skinbuttonpressed1, (width / 4)*3, 500, 200, 50, 255);
    }

    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(BackButtonPositionX - 100, BackButtonPositionY - 25, BUTTON_WIDTH, BUTTON_HEIGHT);
    CP_Image_Draw(backbutton, (width / 4) * 2, 1000, 200, 50, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY - 25))
    {
        CP_Image_Draw(backbuttonpressed, (width / 4) * 2, 1000, 200, 50, 255);
    }

}

void options_exit()
{

}
