#include <stdio.h>

int main() {
	int factors = 0;
	int usr_number;
	int i;

	printf("Enter a number to factorise: ");
	scanf("%d", &usr_number);

	for(i = 1; i <= usr_number; i++) {
		if(!(usr_number % i)) {
			factors++;
		}
	}
	printf("%d has %d factors.\n", usr_number, factors);
	if(factors == 2) {
		printf("This number is prime!\n");
	}
	return 0;
}

