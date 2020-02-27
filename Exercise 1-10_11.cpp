#include<stdio.h>
#define MAXSIZE 1000
int main();
int main() {
	// Exercise 1-10
	// Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. 
	// This makes tabs and backspaces visible in an unambiguous way.
	// Exercise 1-11
	// How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?
	char input[MAXSIZE], c;
	int i, state;
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			input[i] = '\\';
			++i;
			input[i] = 't';
			++i;
		}
		else if (c == '\b') {
			input[i] = '\\';
			++i;
			input[i] = 'b';
			++i;
		}
		else if (c == '\\') {
			input[i] = '\\';
			++i;
			input[i] = '\\';
			++i;
		}
		else {
			input[i] = c;
			++i;
		}
	}
	input[i] = '\0';
	printf("%s", input);
}