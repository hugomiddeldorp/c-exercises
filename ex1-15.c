#include <stdio.h>

float f2c(float f) {
	float c;
	c = (f - 32) * 5/9;

	return c;
}

int main() {
	printf("%f\n", f2c(200));
	printf("%f\n", f2c(120));

	return 0;
}

