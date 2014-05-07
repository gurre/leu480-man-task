/*
Copyright (c) 2012 Gustav Svalander, Chalmers course LEU480, Lindholmen, Göteborg

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "hangman.h"


int main2()
{
  char word[MAX_WORD_LEN];	/* Word to guess (from file) */
  char mask[MAX_WORD_LEN];	/* Masked word (shown on screen) */
  int ch;			/* User selection */
  int count;			/* Number of guesses */
  int result;			/* Winner */
  int len;
  char *hangman[] = {
    "_ _ _ _ _\n",    // Rad ett vid 1:a felgissningen
    "    |    \n",    // Rad ett vid 2:a felgissningen
    "    0    \n",    // Rad ett vid 3:e felgissningen
    " // | \\ \n",    // Rad ett vid 4:e felgissningen
    "    |    \n",    // Rad ett vid 5:e felgissningen
    "   //\\  \n"     // Rad ett vid 6:e felgissningen
  };

  /*   -------------------- Programstart  -----------------*/

  srand( time(0) );

  while( 1 ){

    /*
     *  Init section
     */

    // slumpa fram ett ord

    printf( "Välkommen till HANG MAN 2013\n");
    printf( "Du har %d gissningar pÂ dig (avbryt med 0)\n", MAX_GUESS );

    printf( "Datorn har nu valt ett ord pÂ %d bokstaver\n", len );



    while( 0 ){
      // spel-loop

      // hämta en bokstav

      // finns bokstaven i ordet?

      // visa

    }

    if( result == WIN ){
      printf("Grattis du vann!\n");
    }else if( result == LOOSE ){
      printf("Tyvarr du forlorade ordet var: %s\n", word);
    }else{
      printf("Avbrutet\n");
    }

    ch = get_user_input("Vill du spela igen (j/n)?)> ");
    if( ch == 'n' || ch == 'N' ){
      break;
    }
  }

  return 0;
}

int irand(int n){
	int r, randmax = RAND_MAX/n * n;
	while ((r = rand()) >= randmax);
	return r / (randmax / n);
}

int one_of_n(int n){
	int i, r = 0;
	for (i = 1; i < n; i++) if (!irand(i + 1)) r = i;
	return r;
}

string get_word_from_file(){
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("hangman.dat", "r");
  if (fp == NULL)
    return NULL;

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);
  }
  if (line)
    free(line);
  return line;
}

char get_user_input(char *str){
	printf("%s",str);
	char op= '0';
	op = getchar();
	//while( (op = getchar()) && ( (op>='A' && op<='Z') || (op>='a' && op<='z') ) );
	return op;
}
