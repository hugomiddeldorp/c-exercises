#include <stdio.h>

int main() {
	int c, blank;
	blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n') {
			if (blank == 0){
				putchar('\n');
			}
			++blank;
		}
		else {
			putchar('#');
			blank = 0;
		}
	}
	return 0;
}

