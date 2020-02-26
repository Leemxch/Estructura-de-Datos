#include <stdio.h>

void main() {
	int input;
	while ((input = getchar()) != EOF) {
		if (input == ' ') {
			printf("\n");
		}
		else {
			printf("%c", input);
		}
	}
}
