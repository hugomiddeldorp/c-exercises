/************************************************
* 
* CheckSyntax: Basic syntax checker for C
* Checks for unmatched parentheses, brackets, braces,
* quotes and comments.
* 
* Author: Hugo Middeldorp
* 
************************************************/

#include <stdio.h>
#define MAXLENGTH 1000
#define MAXLEVEL 100
#define TRUE 1
#define FALSE 0

/* findIndex function takes an array, its length and a character to find
 * in the array, returns its index */
int findIndex(char haystack[], int size, char needle) {
    int i, index = -1;

    for (i = 0; i < size; ++i) {
        if (haystack[i] == needle) {
            index = i;
        }
    }
    return index;
}


/* append takes the syntax_only, a char and the index
 * and appends the char to the array at index.
 * It returns the next index */
int append(char syntax_only[], char character, int index) {
    syntax_only[index] = character;
    return ++index;
}


/* isSyntax takes one char c and checks if it's syntax */
int isSyntax(char c) {
    int i, result = FALSE;
    char syntax[] = {'(', ')', '{', '}', '[', ']'};
    int syntax_length = 6;


    for (i=0; i < syntax_length; ++i) {
        if (c == syntax[i]) {
            result = TRUE;
        }
    }

    return result;
}


/* parse takes the user input and extracts only the syntax from it.
 * It puts the result in a new array. */
int parse(char code[], int size, char syntax_only[]) {
    int i, j; /* two counters for the code and the syntax arrays */
    /* Open variables for quotes, either positive or negative.
     * Makes it easy to go between the two. */
    int double_open = -1, single_open = -1;
    int in_comment = FALSE;
    j = 0;

    for (i = 0; i < size; ++i) {
        /* If we hit an escape char, skip the next one */
        if (code[i] == '\\') {
            i += 2;
        }

        /* Checking if we're inside a quote */
        if (code[i] == '"' && !in_comment && single_open == -1) {
            double_open *= -1;
            if (single_open != 1 && !in_comment) {
                j = append(syntax_only, '"', j);
            }
        }
        else if (code[i] == '\'' && !in_comment && double_open == -1) {
            single_open *= -1;
            if (double_open != 1 && !in_comment) {
                j = append(syntax_only, '\'', j);
            }
        }

        /* Checking if we're inside a comment */
        /* Using c to denote open comment and C to denote closed comment */
        else if (i < size-1 && code[i] == '/' && code[i+1] == '*'
                && double_open == -1 && single_open == -1) {
            in_comment = TRUE;
            j = append(syntax_only, 'c', j);
        }
        else if (i < size-1 && code[i] == '*' && code[i+1] == '/'
                && double_open == -1 && single_open == -1) {
            in_comment = FALSE;
            j = append(syntax_only, 'C', j);
        }

        /* Checking for other syntax */
        else if (isSyntax(code[i]) && single_open == -1 && double_open == -1 
                && !in_comment) {
            j = append(syntax_only, code[i], j);
        }

        /* Checking for new lines, for line counting later.
         * Using 'n' for debugging, so it doesn't actually print
         * line-breaks.*/
        else if (code[i] == '\n') {
            j = append(syntax_only, 'n', j);
        }
    }

    /* Remove trailing new lines */
    for (i = j-1; i >= 0 && syntax_only[i] == 'n'; --i){
        --j;
    }

    syntax_only[j+1] = '\0';
    return j;
}


/* getLine takes an array and a character position and returns 
 * how many line breaks have occurred */
int getLine(char input[], int position) {
    int lines = 1, i;

    for (i = 0; i <= position; ++i) {
        if (input[i] == 'n') {
            ++lines;
        }
    }

    return lines;
}


/* checkSyntax: for each item, goes through all the way and checks
 * for matching open/close char */
int checkSyntax(char syntax_only[], int length) {
    char open[] = {'(', '{', '[', 'c'};
    char closed[] = {')', '}', ']', 'C'};
    char hierarchy[2][MAXLEVEL]; /* Two-dim array for line number and char */
    int index, level, i, errors, quote;
    level = 0;
    errors = 0;
    quote = -1; /* negative when closed */

   for (i = 0; i < length; ++i) {
       if ((index = findIndex(open, 4, syntax_only[i])) != -1) {
           ++level;
           hierarchy[0][level] = open[index];
           hierarchy[1][level] = getLine(syntax_only, i);
       }
       else if ((index = findIndex(closed, 4, syntax_only[i])) != -1) {
           if (open[index] == hierarchy[0][level]) {
               --level;
           }
           else {
               ++errors;
               printf("\nError on line %d, non-matching character %c",
                       getLine(syntax_only, i), closed[index]);
           }
       }
       else if (syntax_only[i] == '\'' || syntax_only[i] == '"') {
           quote *= -1;
       }
   } 

   /* Raise error if any quote is still open. The error will always be at the
    * end of file because it stops recording after the quote opens. */
   if (quote == 1) {
       printf("\nError on line %d, non-matching character %c",
               getLine(syntax_only, length-1), syntax_only[length-1]);
       ++errors;
   }

   /* End of file, check levels. Should be 0 so if it isn't: loop through
    * each level, find the char in the hierarchy and print the line */
   for (i = 1; i <= level; ++i) {
       printf("\nError on line %d, character %c was never closed",
               hierarchy[1][i], hierarchy[0][i]);
       ++errors;
   }

   return errors;
}


/* getInput takes the input array and max length and records user input
 * into it. Returns the length of the input. */
int getInput(char code[], int maxl) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF && i < maxl-1; ++i) {
        code[i] = c;
    }

    code[i+1] = '\0';
    return i;
}

int main() {
    char code[MAXLENGTH], syntax_only[MAXLENGTH];
    int code_length, syntax_length, errors;

    code_length = getInput(code, MAXLENGTH);
    syntax_length = parse(code, code_length, syntax_only);
    errors = checkSyntax(syntax_only, syntax_length);

    if (errors == 0) {
        printf("\nNo errors found.\n");
    }

    printf("\n");

	return 0;
}

