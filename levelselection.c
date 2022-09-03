#include "cprocessing.h"
#include <stdio.h>

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 200

#define COLOR_RED CP_Color_Create(255, 0, 0, 255)
#define COLOR_GREEN CP_Color_Create(0, 255, 0, 255)
#define COLOR_BLUE CP_Color_Create(0, 0, 255, 255)
#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

#define TEXT_ONEBUTTON "1-1"
#define TEXT_TWOBUTTON "1-2"
#define TEXT_THREEBUTTON "1-3"

CP_Image menubackground;

int levelselection;

int is_btn_colliding(float x, float y, float buttonX, float buttonY) {
    return x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT;
}

void levelselection_init(void)
{
    menubackground = CP_Image_Load("./Assets/Menubackground.png");

    CP_System_Fullscreen();
}

void levelselection_draw(void)
{
    float height = (float)CP_System_GetWindowHeight();
    float width = (float)CP_System_GetWindowWidth();

    //1-1 button position
    float OnePositionX = (width/4)-50;
    float OnePositionY = (height/2);
    //1-1 text position
    float OneTextPositionX = (width/4)-90;
    float OneTextPositionY = (height/2)+20;

    //1-2 button position
    float TwoPositionX = ((width/4)*2)-50;
    float TwoPositionY = (height/2);
    //1-2 text position
    float TwoTextPositionX = ((width/4)*2)-90;
    float TwoTextPositionY = (height/2)+20;

    //1-3 button position
    float ThreePositionX = ((width/4)*3)-50;
    float ThreePositionY = (height/2);
    //1-3 text position
    float ThreeTextPositionX = ((width/4)*3)-90;
    float ThreeTextPositionY = (height/2)+20;

switch (levelselection) {
    case 0:

        CP_Settings_TextSize(80);

        //Level 1-1 Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawEllipse(OnePositionX, OnePositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
        CP_Font_DrawText(TEXT_ONEBUTTON, OneTextPositionX, OneTextPositionY);

        //Level 1-2 Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawEllipse(TwoPositionX, TwoPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
        CP_Font_DrawText(TEXT_TWOBUTTON, TwoTextPositionX, TwoTextPositionY);

        //Level 1-3 Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawEllipse(ThreePositionX, ThreePositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

        CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
        CP_Font_DrawText(TEXT_THREEBUTTON, ThreeTextPositionX, ThreeTextPositionY);

        CP_Image_Draw(menubackground, 100, 100, 1920, 1080, 255);

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), OnePositionX, OnePositionY) && CP_Input_MouseTriggered(MOUSE_BUTTON_1)) {
            levelselection = 1;
        }

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), TwoPositionX, TwoPositionY) && CP_Input_MouseTriggered(MOUSE_BUTTON_1)) {
            levelselection = 2;
        }

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), ThreePositionX, ThreePositionY) && CP_Input_MouseTriggered(MOUSE_BUTTON_1)) {
            levelselection = 3;
        }
        break;

    case 1:
        //Play level 1-1
        break;

    case 2:
        //Play level 1-2
        break;

    case 3:
        //Play level 1-3
        break;

    default:
        break;
    }
}

void levelselection_exit(void)
{

}
