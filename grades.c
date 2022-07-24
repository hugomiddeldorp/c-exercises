# include <stdio.h>

int main() {
	int average;
	int grades[3];

	grades[0] = 80;
	grades[1] = 90;
	grades[2] = 85;

	average = (grades[0] + grades[1] + grades[2]) / 3;

	printf("The average of the three grades is %d.\n", average);
}
