#include <stdio.h>
#define MAXSIZE 1000
#define TABLEN 8
int main();
void reverse(char[]);
int getLen(char[]);
void getInput(char[]);
void detab(char[]);
int main()
{
	// Exercise 1-20
	// Write a program detab that replaces tabs in the input with the proper number of blanks to space
	// to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable
	// or a symbolic parameter?
	char data[MAXSIZE];
	getInput(data);
	detab(data);
}
// get input
void getInput(char data[]) {
	int input, i;
	i = 0;
	while ((input = getchar()) != EOF) {
		data[i] = input;
		i++;
	}
	data[i] = '\0';
}
// reverse string
void reverse(char data[])
{
	int len, temp;
	len = getLen(data);
	for (int i = 0; i < len / 2; i++) {
		temp = data[i];
		data[i] = data[len - i - 1];
		data[len - i - 1] = temp;
	}
}
// get string's length
int getLen(char data[]) {
	int len = 0;
	while (data[len] != '\0')
		++len;
	return len;
}
void detab(char data[]) {
	int i, textLen;
	i = 0;
	textLen = 0;
	while (data[i] != '\0') {
		if (data[i] == '\t') {
			for (textLen = TABLEN - (textLen % TABLEN); textLen > 0; textLen--)
				printf(" ");
		}
		else if (data[i] == '\n') {
			textLen = 0;
			printf("%c", data[i]);
		}
		else if (data[i] > 32 && data[i] < 127) {
			textLen++;
			printf("%c", data[i]);
		}
		++i;
	}
}