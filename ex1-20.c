/************************************************
* 
* Detab: Replaces tabstops with spaces.
*
* Could do all in the same function,
* ie. replace \t with 4 spaces as user inputs --
* but I've decided to do it in two separate step.
* Less efficient but more robust.
* 
* Author: Hugo Middeldorp
* 
************************************************/

#include <stdio.h>
#define TAB 4
#define MAXLENGTH 1000
#define MAXTAB 4000 /* Will need to be at most 4 times the size of maxinput_array */

/* usr_input takes the input_array array and the maximum length of the user input,
 * returns the length of the input_array and affects the input_array array globally */
int usr_input(char input_array[], int maxl) {
    /* c represents the character being typed
     * i represents the length of the user_input */
    int c, i;

    /* loop until EOF or we reach the max length */
    for (i = 0; i < maxl - 1 && (c = getchar()) != EOF; ++i) {
        input_array[i] = c;
    }

    input_array[i+1] = '\0';
    return i; /* i represents the length of the usr_input */
}


int detab(char input_array[], char detab_array[], int input_length) {
    /* shift represents the shift in index caused by transforming 1 character
     * (ie. '\t') into 4 blank spaces
     *
     * i represents the position in the input_array array
     *
     * j will be used as an index to loop the space process */
    int shift, i, j;
    shift = 0;

    /* loop through the entire input */
    for (i = 0; i <= input_length; ++i) {
        if (input_array[i] == '\t') {
            detab_array[i+shift] = ' ';
            
            /* We only start shifting after the first because before was
             * just a case of replacing '\t' with ' ' */
            for (j = 0; j < (TAB - 1); j++) {
                ++shift;
                detab_array[i+shift] = ' ';
            }
        }
        else {
            detab_array[i+shift] = input_array[i];
        }
    }
    
    detab_array[i+shift+1] = '\0';

    return 0;
}

int main() {
    int length;
    char input_array[MAXLENGTH];
    char detab_array[MAXTAB];

    length = usr_input(input_array, MAXLENGTH);
    detab(input_array, detab_array, length);

    printf("\nEnd of program.\n");
    printf("%s\n", detab_array);

	return 0;
}

