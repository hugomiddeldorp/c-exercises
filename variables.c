# include <stdio.h>

int main() {
	int a = 2;
	float b = 5.5;
	double c = 6.25;
	float sum = a + b + c;
	
	int numbers[10];

	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;
	numbers[3] = 40;

	printf("The sum of a b and c is %f.\n", sum);
	printf("The second number in the list is %d.\n", numbers[1]);
	return 0;
}
