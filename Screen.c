#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

#include <windows.h>

#define SCREEN_X_START_LIMIT 			0
#define SCREEN_X_END_LIMIT 				80
#define SCREEN_Y_START_LIMIT 			0
#define SCREEN_Y_END_LIMIT 				25
#define ERASE_SHAPE						' '


/*****************************************************************************/
/********************* Public functions prototypes ***************************/
/*****************************************************************************/
void Screen_GotoXY(u32 Copy_u32XPos,u32 Copy_u32YPos);



/*
void main(void)
{
	system("cls") ;
	Screen_GotoXY(0,0);
	printf("Hello World !\n") ;
}

*/





/*****************************************************************************/
/******************** Public functions Implementation ************************/
/* ***************************************************************************/

void Screen_GotoXY(u32 Copy_u32XPos,u32 Copy_u32YPos)
{
    /* Initialize the coordinates of the screen */
	COORD coord;
	coord.X = Copy_u32XPos;
	coord.Y = Copy_u32YPos;
	/* Get the console handle */
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(consoleHandle,coord);
}



