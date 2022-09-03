#include "cprocessing.h"
#include <stdio.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50

#define COLOR_RED CP_Color_Create(255, 0, 0, 255)
#define COLOR_GREEN CP_Color_Create(0, 255, 0, 255)
#define COLOR_BLUE CP_Color_Create(0, 0, 255, 255)
#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

#define TEXT_PLAYBUTTON "PLAY"
#define TEXT_QUITBUTTON "QUIT"

CP_Image menubackground;

int lobbyselection;

int is_btn_colliding(float x, float y, float buttonX, float buttonY) {
    return x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT;
}

void mainmenu_init(void)
{
    menubackground = CP_Image_Load("./Assets/Menubackground.png");

    CP_System_Fullscreen();
}

void mainmenu_draw(void)
{
    float height = (float)CP_System_GetWindowHeight();
    float width = (float)CP_System_GetWindowWidth();

    //Play button position
    float PlayButtonPositionX = (width/4)-100;
    float PlayButtonPositionY = (height/4)*3;
    //Play text position
    float PlayTextPositionX = (width/4)-20;
    float PlayTextPositionY = ((height/4)*3)+25;

    //Quit button position
    float QuitButtonPositionX = ((width/4)*3)-100;
    float QuitButtonPositionY = (height/4)*3;
    //Quit text position
    float QuitTextPositionX = ((width/4)*3)-20;
    float QuitTextPositionY = ((height/4)*3)+25;


switch (lobbyselection) {
    case 0:
        //Play Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawRect(PlayButtonPositionX, PlayButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
        CP_Font_DrawText(TEXT_PLAYBUTTON, PlayTextPositionX, PlayTextPositionY);

        //Quit Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawRect(QuitButtonPositionX, QuitButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
        CP_Font_DrawText(TEXT_QUITBUTTON, QuitTextPositionX, QuitTextPositionY);

        CP_Image_Draw(menubackground, 100, 100, 1920, 1080, 255);

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), PlayButtonPositionX, PlayButtonPositionY) && CP_Input_MouseTriggered(MOUSE_BUTTON_1)) {
            lobbyselection = 1;
        }

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX, QuitButtonPositionY) && CP_Input_MouseTriggered(MOUSE_BUTTON_1)) {
            lobbyselection = 2;
        }
        break;

    case 1:
        //Play Game when play button is pressed
        break;

    case 2:
        //Quit Game when quit button is pressed
        CP_Engine_Terminate();
        break;

    default:
        break;
    }
}

void mainmenu_exit(void)
{

}
