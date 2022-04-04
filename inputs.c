# include <stdio.h>
# define LIMIT 50

int main() {
	int age;
	printf("How old are you? ");
	scanf("%d", &age);

	if(age < LIMIT) {
		printf("So you are %d years old?\nYou're quite young!\n", age);
	}
	else if(age == LIMIT) {
		printf("You're %d, almost there!\n", age);
	}
	else {
		printf("I don't want to be ageist but %d years old is quite old...\n", age);
	}

	return 0;
}
