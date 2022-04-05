#include <stdio.h>

int main() {
	int c;
	int blank;

	while((c = getchar()) != EOF) {
		if(c == ' ') {
			if(blank == 0){
				putchar(c);
			}
			++blank;
		}
		else {
			blank = 0;
			putchar(c);
		}
	}
	return 0;
}

