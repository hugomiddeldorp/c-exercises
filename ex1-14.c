#include <stdio.h>

int main() {
	int c, cwhite, cother, i, j;
	int ndigit[10];

	cwhite = cother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0'  && c <= '9') {
			++ndigit[c - '0'];
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			++cwhite;
		}
		else {
			++cother;
		}
	}

	printf("\n");
	for (i = 0; i < 10; i++){
		printf("           %d: ", i);
		for (j = 1; j <= ndigit[i]; j++) {
			printf("#");
		}
		printf("\n");
	}

	printf("White spaces: ");
	for (i = 0; i < cwhite; i++) {
		printf("#");
	}
	printf("\n");

	printf("Characters:   ");
	for (i = 0; i < cother; i++) {
		printf("#");
	}
	printf("\n");

	return 0;
}

