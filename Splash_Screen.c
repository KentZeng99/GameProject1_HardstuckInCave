#include <stdlib.h>
#include <stdbool.h>
#include "easing.h"
#include "cprocessing.h"

#define SWAP(type, lhs, rhs) { \
	type temp = lhs; \
	lhs = rhs; \
    rhs = temp; \
}

CP_Image splashScreen;
CP_Image teamScreen;

float alphaMin;
float alphaMax;

int count;	//Keeps track of how many times the timer has swapped

bool showSplash;
bool showTeam;

extern bool mute;

float timer;
float duration;

float splashTimer;
float splashDuration;

float teamTimer;
float teamDuration;

//Foward declaration
void mainmenu_init(void);
void mainmenu_update(void);
void mainmenu_exit(void);

void splash_init()
{
	CP_System_Fullscreen();
	CP_System_SetWindowTitle("Hardstuck in cave");

	mute = false;

	showSplash = true;
	showTeam = false;
	count = 0;

	alphaMin = 0.f;
	alphaMax = 255.f;

	timer = 0.f;
	duration = 2.f;

	splashTimer = 0.f;
	splashDuration = 3.f;

	teamTimer = 0.f;
	teamDuration = 3.f;

	splashScreen = CP_Image_Load("./Assets/Splash_Screen.png");
	teamScreen = CP_Image_Load("./Assets/teamScreen.png");
}

void splash_update()
{
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	if (count < 2)
	{
		splashTimer += CP_System_GetDt();
		if (splashTimer >= splashDuration)
		{
			SWAP(float, alphaMin, alphaMax);
			count++;
			splashTimer = 0.f;
		}
	}
	else if (count >= 2 && count < 4)
	{
		showSplash = false;
		showTeam = true;
		teamTimer += CP_System_GetDt();
		if (teamTimer >= teamDuration)
		{
			SWAP(float, alphaMin, alphaMax);
			count++;
			teamTimer = 0.f;
		}
	}
	if (count == 4)
	{
		CP_Engine_SetNextGameState(mainmenu_init, mainmenu_update, mainmenu_exit);
	}

	if (showSplash)
	{
		CP_Image_Draw(splashScreen, (float)(CP_System_GetWindowWidth() / 2), (float)(CP_System_GetWindowHeight() / 2), 1920, 1080, (int)Linear(alphaMin, alphaMax, splashTimer / splashDuration));
	}
	else if (showTeam)
	{
		CP_Image_Draw(teamScreen, (float)(CP_System_GetWindowWidth() / 2), (float)(CP_System_GetWindowHeight() / 2), 1920, 1080, (int)Linear(alphaMin, alphaMax, teamTimer / teamDuration));
	}
}

void splash_exit()
{

}
