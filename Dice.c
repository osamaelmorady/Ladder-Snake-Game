#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

/*************************************************/
/************ Generate a Random Number ***********/
/*************************************************/
u8 ThrowDice(void) ;



/*
void main(void) 
{
	for (int i=0;i<20;i++)
	{
		printf("%d  ",ThrowDice()) ;
	}	
}

*/



/*****************************************************/
/************** Generate a Random Number *************/
/************** From ( 1 to 6 ) like Dice ************/
/*****************************************************/
u8 ThrowDice(void) 
{	
	//Get the Random Number
	u8 Generated_Num=1+rand()%6 ;
	
	return Generated_Num;
}