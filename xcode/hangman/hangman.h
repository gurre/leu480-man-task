/*
Copyright (c) 2012 Gustav Svalander, Chalmers course LEU480, Lindholmen, Göteborg

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LEN 20

const int MAX_GUESS = 6;

const char ABORT_CH = '0';

const int LOOSE = 0;
const int WIN = 1;
const int ABORTED = 2;

const char *hangman[] = {
    "_ _ _ _ _\n",    // Rad ett vid 1:a felgissningen
    "    |    \n",    // Rad ett vid 2:a felgissningen
    "    0    \n",    // Rad ett vid 3:e felgissningen
    " // | \\ \n",    // Rad ett vid 4:e felgissningen
    "    |    \n",    // Rad ett vid 5:e felgissningen
    "   //\\  \n"     // Rad ett vid 6:e felgissningen
};

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
char check_guess( char guess, char *word, char *mask );
void print_result(char result, int guess_count, char *mask);

/* File IO */
void get_line_from_fp(int line, char *buf, FILE *ifp);

/* Utilities */
int one_of_n(int n);
void clear_stdin();