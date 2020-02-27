#include<stdio.h>
#define MAXSIZE 1000
#define BLANK 0
#define NOTBLANK 1
int main();
int main() {
	// Exercise 1-9
	// Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
	char input[MAXSIZE], c;
	int i, state;
	i = 0; state = BLANK;
	while ((c = getchar()) != EOF) {
		if (c == ' ' && state == BLANK) {
			continue;
		}
		if (c == ' ') state = BLANK;
		else state = NOTBLANK;
		input[i] = c;
		++i;
	}
	input[i] = '\0';
	printf("%s", input);
}
