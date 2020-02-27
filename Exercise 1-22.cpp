#include <stdio.h>
#define MAXSIZE 1000
#define TABLEN 8
#define LINELEN 8
int main();
void reverse(char[]);
int getLen(char[]);
void getInput(char[]);
void detab(char[]);
void entab(char[]);
void fold(char[]);
int main()
{
	/*Exercise 1-23
	Write a program to remove all comments from a C program. Don’t forget to handle
	quoted strings and character constants properly. C comments do not nest.*/
	char data[MAXSIZE];
	getInput(data);
	fold(data);
	printf("%s", data);
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
// replace \t by blank
void detab(char data[]) {
	char result[MAXSIZE];
	int i = 0, textLen = 0, resultLen = 0;
	while (data[i] != '\0') {
		if (data[i] == '\t') {
			for (textLen = TABLEN - (textLen % TABLEN); textLen > 0; textLen--) {
				result[resultLen] = ' ';
				resultLen++;
			}
		}
		else if (data[i] == '\n') {
			textLen = 0;
			result[resultLen] = data[i];
			resultLen++;
		}
		else if (data[i] > 32 && data[i] < 127) {
			textLen++;
			result[resultLen] = data[i];
			resultLen++;
		}
		++i;
	}
	result[resultLen] = '\0';
	i = 0;
	while ((data[i] = result[i]) != '\0')
		i++;
}
// replace blank by \t
void entab(char data[]) {
	char result[MAXSIZE];
	int i = 0, textLen = 0, blankLen = 0, blockLen = 0, resultLen = 0;
	while (data[i] != '\0') {
		if (data[i] == '\n') {
			for (; blankLen > 0; blankLen--) {
				result[resultLen] = ' ';
				resultLen++;
			}
			result[resultLen] = data[i];
			resultLen++;
			blankLen = blockLen = 0;
		}
		if (data[i] == '\t') {
			result[resultLen] = data[i];
			resultLen++;
			blankLen = blockLen = 0;
		}
		if (blockLen < TABLEN - 1) {
			if (data[i] >= 33 && data[i] <= 126) {
				for (; blankLen > 0; blankLen--) {
					result[resultLen] = ' ';
					resultLen++;
				}
				result[resultLen] = data[i];
				resultLen++;
			}
			if (data[i] == ' ') {
				blankLen++;
			}
			blockLen++;
		}
		else {
			if (data[i] >= 33 && data[i] <= 126) {
				for (; blankLen > 0; blankLen--) {
					result[resultLen] = ' ';
					resultLen++;
				}
				result[resultLen] = data[i];
				resultLen++;
			}
			if (data[i] == ' ') {
				result[resultLen] = '\t';
				resultLen++;
				blankLen = 0;
			}
			blockLen = 0;
		}
		++i;
	}

}
// division a long line into two or more line
void fold(char data[]) {
	int i = 0, lastBlank = 0, lastNewline = 0;
	while (data[i] != '\0') {
		if (i - lastNewline <= LINELEN) {
			if (data[i] == ' ' || data[i] == '\t')
				lastBlank = i;
			if (data[i] == '\n')
				lastNewline = i + 1;
			i++;
		}
		if (i - lastNewline > LINELEN) {
			if (lastBlank > lastNewline) {
				data[lastBlank] = '\n';
				lastNewline = lastBlank + 1;
			}
			else {
				while (data[i] != '\t' && data[i] != ' ' && data[i] != '\n' && data[i] != '\0')
					i++;
				if (data[i] == '\0')break;
				else {
					data[i] = '\n';
					lastNewline = i + 1;
				}
				i++;
			}
		}
	}
}