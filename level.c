#include <stdio.h>
#include "cprocessing.h"
#include "level.h"

#define COLOR_BROWN CP_Color_Create(210,130,80,0)
#define COLOR_DARKBROWN CP_Color_Create(101,67,33,0)
#define COLOR_WHITE CP_Color_Create(255, 255, 255, 255)
#define UNIT_SIZE 100.F
#define UNIT_SIZE3 50.f


void draw_level1(){
	//level 1

	CP_Settings_Fill(COLOR_BROWN);
	CP_Graphics_DrawRect(10.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 103.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 303.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 503.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 803.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(10.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 103.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(110.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 503.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 803.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(210.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(110.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(310.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 103.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 303.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(310.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(410.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(310.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(510.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 303.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(710.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 103.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 303.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 503.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(710.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 503.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(510.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(510.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(610.f, 803.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(710.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(910.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1010.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1110.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1310.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1510.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1710.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 903.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 803.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 503.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 303.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 103.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1810.f, 3.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(810.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(910.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1010.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(910.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1110.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1310.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 503.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1510.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1010.f, 803.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 803.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 703.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1710.f, 403.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1110.f, 603.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 303.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1610.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1710.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1510.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1310.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1110.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1010.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(910.f, 03.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1010.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1110.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1210.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1310.f, 103.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1310.f, 203.f, UNIT_SIZE, UNIT_SIZE);
	CP_Graphics_DrawRect(1410.f, 203.f, UNIT_SIZE, UNIT_SIZE);
}

void draw_level3() {

	//in progress
	CP_Settings_Fill(COLOR_DARKBROWN);
	CP_Graphics_DrawRect(0.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(0.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(50.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(150.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(150.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(150.f, 100.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(150.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(50.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(100.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(0.f, 250.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(50.f, 250.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(150.f, 250.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(200.f, 250.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(200.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(250.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(300.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 100.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(300.f, 100.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(250.f, 100.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(250.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(250.f, 250.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(0.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(50.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(100.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(150.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(200.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(250.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(250.f, 300.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(300.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 350.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 300.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 250.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(350.f, 200.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(400.f, 200.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(450.f, 200.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(450.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(450.f, 100.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(450.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(500.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(550.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(650.f, 0.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(650.f, 50.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(650.f, 100.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(500.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
	CP_Graphics_DrawRect(550.f, 150.f, UNIT_SIZE3, UNIT_SIZE3);
}
