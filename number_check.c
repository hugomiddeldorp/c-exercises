#include <stdio.h>

int main() {
	int x;
	char usr_input;

	printf("Please enter a number above 0. ");
	scanf("%d", &x);

	while(x > 0) {
		printf("%d\n", x);
		x--;
	}

	printf("What have you done... My day is ruined.\n");

	while(getchar() != '\n');
	getchar();

	return 0;
}

