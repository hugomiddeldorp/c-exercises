#include <stdio.h>

int main() {
	int i;
	int total;

	for(i=1;i<1000;i++) {
		if(!(i % 3) || !(i % 5)) {
			total += i;
		}
	}
	printf("Total is %d.\n", total);
	return 0;
}

