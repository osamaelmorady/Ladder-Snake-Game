#include<stdio.h>
#include<stdlib.h>
#include "STD_TYPES.h"
#include "Map.c"
#include "Screen.c"
#include "Dice.c"


/*****************************************************************/
/****************** Player1 and Player2 Shape ********************/
/*****************************************************************/
#define PLAYER1 '$'
#define PLAYER2 '&'

void Player1_fun(void) ;
void Player2_fun(void) ;
void PressAnyKey(void) ;
void Set_Position(u8 player_sympol,u8 position) ;


u8 CHK_KEY;
u8 Dice_Num ;

u8 Player1_Pos=0 ;
u8 Player2_Pos=0 ;


void main(void)
{
	ShowMap() ;
	
	
	// Loop for players turns
	while (1)
	{
		Player1_fun();
		if  ( (Player1_Pos>100) || (Player2_Pos>100) ) {   break ;}
		Player2_fun();
		if  ( (Player1_Pos>100) || (Player2_Pos>100) ) {  break ;}
	}
	
	
	// Announce the player1 as winner
	if ( Player1_Pos>Player2_Pos )
	{
		Screen_GotoXY(115,20) ;
		printf("Player 1 ($) Wins !!! ") ;
		Screen_GotoXY(110,25) ;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") ;
		
	}
	// Announce the player2 as winner
	else if ( Player1_Pos<Player2_Pos )
	{
		Screen_GotoXY(115,20) ;
		printf("Player 2 (&) Wins !!! ") ;
		Screen_GotoXY(110,25) ;
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~") ;
		
	}
	
	
	// End the game
	Screen_GotoXY(110,26) ;
	printf("Game Over !!!  Press Any Key to Continue... ") ;
	PressAnyKey() ;
	system("cls") ;
}



void PressAnyKey(void)
{
	// Scan any key to wait for a garbage command 
	scanf("%c",&CHK_KEY) ;
	fflush(stdin) ;	
}



void Player1_fun(void) 
{
	
	/********************************************************/
	/*** Throw the Dice and Generate the Number on Screen ***/
	/********************************************************/
	Screen_GotoXY(108,1) ;
	printf("Player 1 Turn : ");
	Screen_GotoXY(108,2) ;
	printf("~~~~~~~~~~~~~~~~");
	
	// clear the previous dice value
	Screen_GotoXY(110,3) ;
	printf("                                         ") ;
	// set the new dice value
	Screen_GotoXY(110,3) ;
	printf("Throw the Dice : ") ;
	PressAnyKey() ;
	
	//calculate the New dice value
	Dice_Num=ThrowDice();
	Screen_GotoXY(130,3) ;
	printf("%d ",Dice_Num) ;
	
	
	/********************************************************/
	/*** Player1 ( $ ) Number ***/
	/********************************************************/
	
	// clear the previous Player position on map
	Set_Position(' ',Player1_Pos) ;
	//calculate the New position
	Player1_Pos=Player1_Pos+Dice_Num ;
	// set the new Player position on map
	Set_Position(PLAYER1,Player1_Pos) ;
	
	// Clear Player1 previous value
	Screen_GotoXY(119,5) ;
	printf("                 ") ;
	// set player 1 Value on table
	Screen_GotoXY(110,5) ;
	printf("Player1 : %d ",Player1_Pos) ;
	// Clear Player2 previous value
	Screen_GotoXY(119,7) ;
	printf("                 ") ;
	// set player 2 Value on table
	Screen_GotoXY(110,7) ;
	printf("Player2 : %d ",Player2_Pos) ;
	
	
	Screen_GotoXY(110,9) ;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	Screen_GotoXY(110,10) ;
	printf(" The Next Player Turn -> ") ;
	Screen_GotoXY(110,11) ;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	Screen_GotoXY(135,10) ;
	
	PressAnyKey() ;
	
}

void Player2_fun(void) 
{
	
	/********************************************************/
	/*** Throw the Dice and Generate the Number on Screen ***/
	/********************************************************/
	Screen_GotoXY(108,1) ;
	printf("Player 2 Turn : ");
	Screen_GotoXY(108,2) ;
	printf("~~~~~~~~~~~~~~~~");
	
	// clear the previous dice value
	Screen_GotoXY(110,3) ;
	printf("                                         ") ;
	// set the new dice value
	Screen_GotoXY(110,3) ;
	printf("Throw the Dice : ") ;
	PressAnyKey() ;
	
	//calculate the New dice value
	Dice_Num=ThrowDice();
	Screen_GotoXY(130,3) ;
	printf("%d ",Dice_Num) ;
	
	
	/********************************************************/
	/*** Player2 ( $ ) Number ***/
	/********************************************************/
	
	// clear the previous Player position on map
	Set_Position(' ',Player2_Pos) ;
	//calculate the New position
	Player2_Pos=Player2_Pos+Dice_Num ;
	// set the new Player position on map
	Set_Position(PLAYER2,Player2_Pos) ;
	
	// Clear Player1 previous value
	Screen_GotoXY(119,5) ;
	printf("                 ") ;
	// set player 1 Value on table
	Screen_GotoXY(110,5) ;
	printf("Player1 : %d ",Player1_Pos) ;
	// Clear Player 2 previous value
	Screen_GotoXY(119,7) ;
	printf("                 ") ;
	// set player 2 Value on table
	Screen_GotoXY(110,7) ;
	printf("Player2 : %d ",Player2_Pos) ;
	
	
	Screen_GotoXY(110,9) ;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	Screen_GotoXY(110,10) ;
	printf(" The Next Player Turn -> ") ;
	Screen_GotoXY(110,11) ;
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	Screen_GotoXY(135,10) ;
	
	PressAnyKey() ;
}




void Set_Position(u8 player_sympol,u8 position)
{
	/* Divide the num to get the first digit that represent n of columns
				and to get the second digit that represent n of rows		    ( EX : 17 =  1(rows) - 7(columns)  )*/
	u8 row=position/10 ;
	u8 col=position%10 ;
	
	// Maping of num on the map patterns
	u8 map_x=col * 10 + 5 ;
	u8 map_y=(50 - 2)-row*5 ;
	
	// Set the cursor at that position on the consule
	Screen_GotoXY(map_x,map_y) ;
	printf("%c",player_sympol) ;
	
	
}