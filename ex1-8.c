#include <stdio.h>

int main() {
	int c, blank, tab, nl;
	blank = 0;
	tab = 0;
	nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++blank;
		}
		else if (c == '\t') {
			++tab;
		}
		else if (c == '\n') {
			++nl;
		}
	}
	printf("Blanks: %d, Tabs: %d, New lines: %d\n", blank, tab, nl);
	return 0;
}

