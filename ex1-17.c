/*****************************************
 *
 * Exercise 1.17 of The C Programming Language
 * Print all lines that have over 80 characters
 *
 * Author: Hugo Middeldorp
 *
******************************************/

#include <stdio.h>
#define MAXLINE 1000 /* maximum length of the line array */

/* getline: read a line and return its length
 * the line array gets affected globally;
 * while it returns its length, it also fills in the line
 */

int get_line (char line[], int maxline) {
    int i, c;

    /* Loop with conditions:
     *      - line can only reach the maximum length
     *      - c needs to not be EOF and blank line
    */
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    
    /* Now that the loop is broken, we need to add a new line
     * (those are to be counted)
     * We add to i to add to the length
     */
    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    /* We indicate the end of the line with this character */
    line[i] = '\0';
    return i;
}

int main() {
    char line[MAXLINE];
    int length;
    int threshold = 80;

    while ((length = get_line(line, MAXLINE)) > 0) {
        if (length > threshold) {
            printf("%s", line);
        }
    }
	return 0;
}


