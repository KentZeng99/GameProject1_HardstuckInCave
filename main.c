#include <stdio.h>
#include "cprocessing.h"


/* Forward declarations */
void splash_init(void);
void splash_update(void);
void splash_exit(void);

/* Entry point */
int main(void)
{
    CP_System_SetWindowTitle("Hardstuck in cave");
    CP_Engine_SetNextGameState(splash_init, splash_update, splash_exit);
    CP_Engine_Run();
    return 0;
}
