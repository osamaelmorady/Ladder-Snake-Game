#include<stdio.h>
#include<stdlib.h>
#include "STD_TYPES.h"

/*****************************************************************/
/******************* Ladder and Snake Shape **********************/
/*****************************************************************/
#define LADDER_SYM '+'
#define SNAKE_SYM  '-'
#define SPACE_SYM  ' ' 


/*****************************************************************/
/*********************** Border Design ***************************/
/*****************************************************************/
#define X_TAB '~'
#define Y_TAB '|'



/*************************************************************************/
/*********************** Functions Prototyping ***************************/
/*************************************************************************/
void ShowMap(void) ;
u8 ShowLadder(u8 x,u8 y) ;
u8 ShowSnake(u8 row,u8 col);









/*

void main (void)
{
	
	ShowMap() ;

}

*/





/****************************************************************************/
/*********************** Show the Ladder Game Map ***************************/
/****************************************************************************/
void ShowMap(void) 
{
	system("cls") ;
	u8 R_N='9';
	u8 C_N='0';
	u8 mode='+' ;
	u8 ladder ;u8 snake ;

	for (u8 Rows=0;Rows<10;Rows++)
	{	
		for (u8 i=0;i<5;i++) 
		{
			C_N='0';
			for (u8 Columns=0;Columns<10;Columns++) 
			{
				ladder=ShowLadder(R_N,C_N) ;
				snake=ShowSnake(R_N,C_N) ;
				if (ladder==LADDER_SYM) 
				{ 
					mode=ladder ; 
				}
				else 
				{
					if (snake==SNAKE_SYM)
					{
						mode=snake ;
					}
					else 
					{
						mode=SPACE_SYM ;
					}
				}
			
				u8 pattern[5][10]={	{Y_TAB ,X_TAB, X_TAB,X_TAB, X_TAB, X_TAB,  X_TAB,  X_TAB,  X_TAB ,  Y_TAB},
									{Y_TAB ,R_N	 , C_N	,' '  , ' '  , ' '  ,  ' '  ,  mode  ,  ' '  ,  Y_TAB},
									{Y_TAB ,' '	 , ' '	,' '  , ' '  , ' '  ,  ' '  ,  ' '  ,  ' '   ,  Y_TAB},
									{Y_TAB ,' '	 , ' '	,' '  , ' '  , ' '  ,  ' '  ,  ' '  ,  ' '   ,  Y_TAB},
									{Y_TAB ,X_TAB, X_TAB,X_TAB, X_TAB, X_TAB , X_TAB , X_TAB , X_TAB ,  Y_TAB}} ;
							 
				for (u8 j=0;j<10;j++)
				{	
					printf("%c",pattern[i][j]) ;
				} 
				if (i==1)
				{
					C_N+=1;	
				}
			}
			printf("\n") ;
		}	

		R_N-=1;
	}
	
	
}




/*******************************************************************/
/*********************** Show the Ladder ***************************/
/*******************************************************************/
u8 ShowLadder(u8 row,u8 col) {
	if (row=='0'&&col=='6'){ return LADDER_SYM ;}
	else if (row=='2'&&col=='2'){ return LADDER_SYM ;}
	else if (row=='4'&&col=='8'){ return LADDER_SYM ;}
	else if (row=='6'&&col=='5'){ return LADDER_SYM ;}
	else if (row=='7'&&col=='9'){ return LADDER_SYM ;}

	else {return SPACE_SYM;}
	
}


/*******************************************************************/
/************************ Show the Snake ***************************/
/*******************************************************************/
u8 ShowSnake(u8 row,u8 col) {
	if (row=='2'&&col=='3'){ return SNAKE_SYM ;}
	else if (row=='4'&&col=='4'){ return SNAKE_SYM ;}
	else if (row=='5'&&col=='5'){ return SNAKE_SYM ;}
	else if (row=='7'&&col=='7'){ return SNAKE_SYM ;}
	else if (row=='9'&&col=='9'){ return SNAKE_SYM ;}

	else {return SPACE_SYM;}
	
}