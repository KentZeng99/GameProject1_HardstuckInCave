#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "easing.h"
#include "cprocessing.h"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50

#define COLOR_RED CP_Color_Create(255, 0, 0, 255)
#define COLOR_GREEN CP_Color_Create(0, 255, 0, 255)
#define COLOR_BLUE CP_Color_Create(0, 0, 255, 255)
#define COLOR_CYAN CP_Color_Create(0,255,255,255)
#define COLOR_BLACK CP_Color_Create(0, 0, 0, 255)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)

void level_select_init(void);
void level_select_update(void);
void level_select_exit(void);

void options_init(void);
void options_update(void);
void options_exit(void);

void credits_init(void);
void credits_update(void);
void credits_exit(void);

CP_Image miner;
CP_Image background;
CP_Image gametitle;
CP_Image playbutton;
CP_Image playbuttonpressed;
CP_Image quitbutton;
CP_Image quitbuttonpressed;
CP_Image menubackground;
CP_Image optionbutton;
CP_Image optionbuttonpressed;
CP_Image creditsbutton;
CP_Image creditsbuttonpressed;
CP_Image tutorialbutton;
CP_Image tutorialbuttonpressed;
CP_Image backbutton;
CP_Image backbuttonpressed;
CP_Image nextButton;
CP_Image nextButtonpressed;
CP_Image tutScreenSprite;
CP_Image tutScreenSprite_2;
CP_Image tutScreenSprite_3;
CP_Image splashScreen;


int showtutorialscreen;
int lobbyselection;

int is_btn_colliding(float x, float y, float buttonX, float buttonY) {
	return x >= buttonX && x <= buttonX + BUTTON_WIDTH && y >= buttonY && y <= buttonY + BUTTON_HEIGHT;
}

void mainmenu_init()
{
    CP_System_SetWindowTitle("Hardstuck in cave");
    showtutorialscreen = 0;
    tutScreenSprite = CP_Image_Load("./Assets/Tutorial_screen.png");
    tutScreenSprite_2 = CP_Image_Load("./Assets/Tutorial_screen_2.png");
    tutScreenSprite_3 = CP_Image_Load("./Assets/Tutorial_screen_3.png");
    miner = CP_Image_Load("./Assets/miner.png");
    background = CP_Image_Load("./Assets/Background.png");
    gametitle = CP_Image_Load("./Assets/GameTitle.png");
    playbutton = CP_Image_Load("./Assets/PlayButton.png");
    playbuttonpressed = CP_Image_Load("./Assets/PlayButtonPressed.png");
    quitbutton = CP_Image_Load("./Assets/QuitButton.png");
    quitbuttonpressed = CP_Image_Load("./Assets/QuitButtonPressed.png");
    optionbutton = CP_Image_Load("./Assets/OptionsButton.png");
    optionbuttonpressed = CP_Image_Load("./Assets/OptionsButtonPressed.png");
    creditsbutton = CP_Image_Load("./Assets/CreditsButton.png");
    creditsbuttonpressed = CP_Image_Load("./Assets/CreditsButtonPressed.png");
	menubackground = CP_Image_Load("./Assets/Menubackground.png");
    tutorialbutton = CP_Image_Load("./Assets/ControlsButton.png");
    tutorialbuttonpressed = CP_Image_Load("./Assets/ControlsButtonPressed.png");
    backbuttonpressed = CP_Image_Load("./Assets/BackButtonPressed.png");
    backbutton = CP_Image_Load("./Assets/BackButton.png");
    nextButtonpressed = CP_Image_Load("./Assets/NextButtonPressed.png");
    nextButton = CP_Image_Load("./Assets/NextButton.png");
    splashScreen = CP_Image_Load("./Assets/Splash_Screen.png");

    CP_System_Fullscreen();

    CP_Settings_Stroke(COLOR_BLACK);
}

void mainmenu_update()
{
    float height = (float)CP_System_GetWindowHeight();
    float width = (float)CP_System_GetWindowWidth();

    //Play button position
    float PlayButtonPositionX = (width / 4);
    float PlayButtonPositionY = 400;

    //Options button Position
    float OptionButtonPositionX = (width / 4);
    float OptionButtonPositionY = 500;

    //Tutorial button Position
    float TutorialButtonPositionX = (width / 4);
    float TutorialButtonPositionY = 600;

    //Quit button position
    float QuitButtonPositionX = (width / 4);
    float QuitButtonPositionY = 700;

    //Credits button position
    float CreditsButtonPositionX = 1800;
    float CreditsButtonPositionY = 1000;

    //Back button position
    float BackButtonPositionX = 1720;
    float BackButtonPositionY = 100;

    //Next button position
    float NextButtonPositionX = 1720;
    float NextButtonPositionY = 50;


    if (CP_Input_MouseClicked())
    {
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), PlayButtonPositionX - 100, PlayButtonPositionY))
        {
            CP_Engine_SetNextGameState(level_select_init, level_select_update, level_select_exit);
            CP_Engine_Run();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), OptionButtonPositionX - 100, OptionButtonPositionY))
        {
            CP_Engine_SetNextGameState(options_init, options_update, options_exit);
            CP_Engine_Run();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), TutorialButtonPositionX - 100, TutorialButtonPositionY))
        {
            showtutorialscreen++;
            if (showtutorialscreen > 3)
            {
                showtutorialscreen = 0;
            }
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX - 100, QuitButtonPositionY))
        {
            CP_Engine_Terminate();
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CreditsButtonPositionX - 100, CreditsButtonPositionY))
        {
            CP_Engine_SetNextGameState(credits_init, credits_update, credits_exit);
            CP_Engine_Run();
        }
    }

    CP_Graphics_ClearBackground(CP_Color_Create(84, 84, 84, 255));
    CP_Image_Draw(background, (float)(CP_System_GetDisplayWidth() / 2), (float)(CP_System_GetDisplayHeight() / 2), 1920, 1080, 255);
    CP_Image_Draw(miner, (float)(CP_System_GetDisplayWidth() / 2), 550, 700, 700, 255);
    CP_Image_Draw(gametitle, (float)(CP_System_GetDisplayWidth() / 2), 200, 1500, 125, 255);

    //Play Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(PlayButtonPositionX - 100, PlayButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

    CP_Image_Draw(playbutton, (width / 4), 425, BUTTON_WIDTH, BUTTON_HEIGHT, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), PlayButtonPositionX - 100, PlayButtonPositionY))
    {
        CP_Image_Draw(playbuttonpressed, (width / 4), 425, BUTTON_WIDTH, BUTTON_HEIGHT, 255);
    }

    //Options Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(OptionButtonPositionX - 100, OptionButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

    CP_Image_Draw(optionbutton, (width / 4), 525, BUTTON_WIDTH, BUTTON_HEIGHT, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), OptionButtonPositionX - 100, OptionButtonPositionY))
    {
        CP_Image_Draw(optionbuttonpressed, (width / 4), 525, BUTTON_WIDTH, BUTTON_HEIGHT, 255);
    }

    //Tutorial Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(TutorialButtonPositionX - 100, TutorialButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

    CP_Image_Draw(tutorialbutton, (width / 4), 625, BUTTON_WIDTH, BUTTON_HEIGHT, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), TutorialButtonPositionX - 100, TutorialButtonPositionY))
    {
        CP_Image_Draw(tutorialbuttonpressed, (width / 4), 625, BUTTON_WIDTH, BUTTON_HEIGHT, 255);
    }

    //Quit Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(QuitButtonPositionX - 100, QuitButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

    CP_Image_Draw(quitbutton, (width / 4), 725, BUTTON_WIDTH, BUTTON_HEIGHT, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), QuitButtonPositionX - 100, QuitButtonPositionY))
    {
        CP_Image_Draw(quitbuttonpressed, (width / 4), 725, BUTTON_WIDTH, BUTTON_HEIGHT, 255);
    }

    //Credits Button
    CP_Settings_Fill(COLOR_WHITE);
    CP_Graphics_DrawRect(CreditsButtonPositionX - 100, CreditsButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);

    CP_Image_Draw(creditsbutton, 1800, 1025, BUTTON_WIDTH, BUTTON_HEIGHT, 255);

    if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), CreditsButtonPositionX - 100, CreditsButtonPositionY))
    {
        CP_Image_Draw(creditsbuttonpressed, 1800, 1025, BUTTON_WIDTH, BUTTON_HEIGHT, 255);
    }

    if (showtutorialscreen == 1)
    {
        CP_Image_Draw(tutScreenSprite, (width / 4) * 2, (height / 2), 1920, 1080, 255);
        //Back Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawRect(BackButtonPositionX - 100, BackButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);
        CP_Image_Draw(backbutton, 1720, 125, 200, 50, 255);

        //Next Button
        CP_Graphics_DrawRect(NextButtonPositionX - 100, NextButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);
        CP_Image_Draw(nextButton, 1720, 75, 200, 50, 255);

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), NextButtonPositionX - 100, NextButtonPositionY))
        {
            CP_Image_Draw(nextButtonpressed, 1720, 75, 200, 50, 255);
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), NextButtonPositionX - 100, NextButtonPositionY) && CP_Input_MouseClicked())
        {
            showtutorialscreen++;
            if (showtutorialscreen < 0)
            {
                showtutorialscreen = 0;
            }
        }

        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY))
        {
            CP_Image_Draw(backbuttonpressed, 1720, 125, 200, 50, 255);
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY) && CP_Input_MouseClicked())
        {
            showtutorialscreen--;
        }
    }
    else if (showtutorialscreen == 2)
    {
        CP_Image_Draw(tutScreenSprite_2, (width / 4) * 2, (height / 2), 1920, 1080, 255);
        //Back Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawRect(BackButtonPositionX - 100, BackButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);
        CP_Image_Draw(backbutton, 1720, 125, 200, 50, 255);

        //Next Button
        CP_Graphics_DrawRect(NextButtonPositionX - 100, NextButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);
        CP_Image_Draw(nextButton, 1720, 75, 200, 50, 255);

        //Back Button
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY))
        {
            CP_Image_Draw(backbuttonpressed, 1720, 125, 200, 50, 255);
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY) && CP_Input_MouseClicked())
        {
            showtutorialscreen--;
        }

        //Next Button
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), NextButtonPositionX - 100, NextButtonPositionY))
        {
            CP_Image_Draw(nextButtonpressed, 1720, 75, 200, 50, 255);
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), NextButtonPositionX - 100, NextButtonPositionY) && CP_Input_MouseClicked())
        {
            showtutorialscreen++;
        }
    }
    else if (showtutorialscreen == 3)
    {
        CP_Image_Draw(tutScreenSprite_3, (width / 4) * 2, (height / 2), 1920, 1080, 255);
        //Back Button
        CP_Settings_Fill(COLOR_WHITE);
        CP_Graphics_DrawRect(BackButtonPositionX - 100, BackButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);
        CP_Image_Draw(backbutton, 1720, 125, 200, 50, 255);

        //Next Button
        CP_Graphics_DrawRect(NextButtonPositionX - 100, NextButtonPositionY, BUTTON_WIDTH, BUTTON_HEIGHT);
        CP_Image_Draw(nextButton, 1720, 75, 200, 50, 255);

        //Back Button
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY))
        {
            CP_Image_Draw(backbuttonpressed, 1720, 125, 200, 50, 255);
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), BackButtonPositionX - 100, BackButtonPositionY) && CP_Input_MouseClicked())
        {
            showtutorialscreen--;
        }

        //Next Button
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), NextButtonPositionX - 100, NextButtonPositionY))
        {
            CP_Image_Draw(nextButtonpressed, 1720, 75, 200, 50, 255);
        }
        if (is_btn_colliding(CP_Input_GetMouseX(), CP_Input_GetMouseY(), NextButtonPositionX - 100, NextButtonPositionY) && CP_Input_MouseClicked())
        {
            showtutorialscreen++;
        }
    }
}

void mainmenu_exit()
{

}

