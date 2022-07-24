/************************************************
* 
* Uncomment: A program that removes all comments
* from C code.
* 
* Author: Hugo Middeldorp
* 
************************************************/

#include <stdio.h>
#define MAXLENGTH 1000
#define TRUE 1
#define FALSE 0

/* Uncomment function takes an array with C code and its length
 * removes all the comments and affects the uncomment array globally */

int uncomment(char code_array[], int length, char no_comment[]) {
    /* i will be used to count through the length of the code array
     * j will be used to count through the length of the uncomment array
     * inside_comment will specify if we are inside or outside a comment */
    int i, j, inside_comment;
    j = 0;
    inside_comment = FALSE;

    for (i = 0; i < (length - 1); ++i) {
        /* We need to first check there's more than 1 character left */
        if (i <= (length - 2) && code_array[i] == '/' && code_array[i+1] == '*') {
            inside_comment = TRUE;
        }
        else if (code_array[i] == '/' && code_array[i-1] == '*') {
            inside_comment = FALSE;
        }
        else if (! inside_comment){
            no_comment[j] = code_array[i];
            ++j;
        }
    }

    no_comment[j+1] = '\0';
    return 0;
}


/* Get user input function takes the max length and the code array,
 * records the user input in the array, and returns the length */

int get_input(char code_array[], int maxl) {
    int c, i;

    for (i = 0; (c = getchar()) != EOF && i < (maxl - 1); ++i) {
        code_array[i] = c;
    }

    code_array[i+1] = '\0';
    return i;
}


int main() {
    char code_array[MAXLENGTH];
    char no_comment[MAXLENGTH];
    int length;
    
    length = get_input(code_array, MAXLENGTH);
    uncomment(code_array, length, no_comment);

    printf("\nUncommented code:\n%s\n", no_comment);
	return 0;
}

