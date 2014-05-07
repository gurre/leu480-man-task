/*
 Copyright (c) 2012 Gustav Svalander, Chalmers course LEU480, Lindholmen, Göteborg
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include "hangman.h"


int main(){
    char word[MAX_WORD_LEN];	/* Word to guess (from file) */
    char mask[MAX_WORD_LEN];	/* Masked word (shown on screen) */
    int ch;                     /* User selection */
    int guess_count;            /* Number of guesses */
    int result;                 /* Winner */
    int len;
    
    
    /*   -------------------- Programstart  -----------------*/
    
    srand( time(0) );
    
    // Main program loop
    while( 1 ){
        /*
         *  Init section
         */
        
        // Init and clear variables
        guess_count=0;
        result=LOOSE;
        memset(&word[0], 0, sizeof(word));
        memset(&mask[0], 0, sizeof(mask));
        
        // Open a file, read a random line and close file.
        FILE *fp = fopen("/Users/gustav/Dropbox/Gurre\ gits/leu480-man-task/xcode/hangman/hangman.dat", "r");
        if (fp == NULL){
            printf("Filen kunde ej läsas\n");
            return 0;
        }
        get_line_from_fp(one_of_n(10),word,fp);
        len = (int)strlen(word);
        for (int i = 0; i < len; i++){
            mask[i]='_';
        }
        fclose(fp);
        
        // Print welcome screen
        printf( "Välkommen till HANG MAN 2013\n");
        printf( "Du har %d gissningar pÂ dig (avbryt med 0)\n", MAX_GUESS );
        printf( "Datorn har nu valt ett ord på %d bokstaver\n", len );
        // Game loop
        while( 1 ){
            // hämta en bokstav från prompten
            char guess = get_user_input("Gissa på en bokstav(a-z)> ");
            if( guess == '0' ) break;
            
            char guess_result=check_guess( guess, word, mask );
            
            // If we are wrong we count as a guess
            if( guess_result==0 )
                guess_count++;
            
            print_result(guess_result,guess_count,mask);
            
            // Too many guesses?
            if( guess_count >= MAX_GUESS ){
                result=LOOSE;
                break;
            }
            // Check if the word is complete
            if ( strcmp(word, mask)==0 ){
                result=WIN;
                break;
            }
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

/*
 *  Print result screen using the number of guesses and the masked word
 */
void print_result(char result, int guess_count, char *mask){
    printf("\n\n");
    if( result>0 ){
        printf("Du svarade rätt på %u bokstäver\n",result);
    }else{
        printf("Du svarade tyvärr fel\n");
    }
    for (int i = 0; i<guess_count; i++) {
        printf("%s",hangman[i]);
    }
    printf("Ordet:  %s  \n",mask);
}

/*
 *  Randomly generate a number between 0 and n-1.
 */
int one_of_n(int n){
	return rand()%n;
}

/*
 *  Get a line from a file using a filepointer
 */
void get_line_from_fp(int line, char *buf, FILE *ifp){
    int i = 0;
    while (fgets(buf, MAX_WORD_LEN, ifp) != NULL) {
        buf[strcspn(buf, "\n")] = '\0';
        if (buf[0] == '\0')
            continue;
        if (i++ == line)
            break;
    }
}

/*
 *  Check if letter is in word and in that case unmask
 */
char check_guess( char guess, char *word, char *mask ){
    int len = (int)strlen(word);
    char changed = 0;
    for (int i = 0; i < len; i++){
        if( word[i] == guess ){
            mask[i] = guess;
            changed++;
        }
    }
    return changed;
}

/*
 *  Print *str and read a char from the promt
 */
char get_user_input(char *str){
    int reply;
    printf("%s",str);
    fflush(stdout);
    reply = getchar();
    do {
        int ch;
        while( (ch = getchar()) != '\n' && ch != EOF );
    } while(0);
    return reply;
}
