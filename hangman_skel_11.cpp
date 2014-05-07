// hangman.cpp : main project file.

/*
 *
 *  File   : hangman_skel.c
 *  Program: The hangman game 2011 
 *  Authors:
 *
 */
 
//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
#include<string.h>
#include<time.h>

#define MAX_WORD_LEN 20

const int MAX_GUESS = 6;

const char ABORT_CH = '0';

const int LOOSE = 0;
const int WIN = 1;
const int ABORTED = 2;

/*
 *  Picture of hangman 
 *
 *         ---        1st try
 *           |        2nd
 *           O        3rd
 *         //|\\       4th
 *           |         5th
 *         // \\       6th
 *                    ....hang (loose)
 *
 */

/* -------------- Funktionsdeklarationer -----------------*/
/* IO */
char get_user_input(char *str);

/* Logic */


/* File IO */


/* Utilities */
void clear_stdin();

/************************************************************
 *
 *                       MAIN
 *
 *
 ************************************************************/

int main()
{
  char word[MAX_WORD_LEN];	/* Word to guess (from file) */
  char mask[MAX_WORD_LEN];	/* Masked word (shown on screen) */
  int ch;			/* User selection */
  int count;			/* Number of guesses */
  int result;			/* Winner */
  int len;

  /*   -------------------- Programstart  -----------------*/

  srand( time(0) );
 
  while( true ){
   
    /*
     *  Init section
     */

    

    printf( "Valkommen till HANG MAN 2011\n");
    printf( "Du har %d gissningar på dig (avbryt med 0)\n", MAX_GUESS );
 
    printf( "Datorn har nu valt ett ord på %d bokstaver\n", len );
   
    while( true ){
  
      /*  GAME MAIN LOOP   */

    }

    if( result == WIN ){
      printf("Grattis du vann!\n");
    }else if( result == LOOSE ){
      printf("Tyvarr du forlorade ordet var: %s\n", word);
    }else{
      printf("Avbrutet\n");
    }

    ch = get_user_input("Vill du spelas igen (j/n)?): ");   
    if( ch == 'n' || ch == 'N' ){
      break;
    }  
  }

  return 0;
}

/***********************************************************
 *
 *  ---------        Funktionsdefinitioner ----------------
 *
 ***********************************************************/

char get_user_input(char *str){
	char tkn= '0';
	
	return tkn;
}



