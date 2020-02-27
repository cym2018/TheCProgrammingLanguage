#include<stdio.h>
#define WORD 0
#define BLANK 1
#define MAXSIZE 1000
int main();
int main() {
	// Exercise 1-12
	// Write a program that prints its input one word per line.
	int c, state, i;
	i = 0;
	char output[MAXSIZE];
	state = BLANK;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state != BLANK) {
				output[i] = '\n';
				++i;
			}
			state = BLANK;
		}
		else {
			output[i] = c;
			++i;
			state = WORD;
		}
	}
	output[i] = '\0';
	printf("%s", output);
}