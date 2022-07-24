#include <stdio.h>

int main() {
	int c;
	int blank = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (blank == 0) {
				putchar('\n');
			}

			++blank;
		}
		else {
			putchar(c);
			blank = 0;
		}
	}
	return 0;
}

