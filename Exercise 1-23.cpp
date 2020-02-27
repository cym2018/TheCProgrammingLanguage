#include <stdio.h>
#define MAXSIZE 10000
int main();
void reverse(char[]);
int getLen(char[]);
void getInput(char[]);
void detab(char[]);
void entab(char[]);
void fold(char[]);
void removeComment(char[]);
int main()
{
	/*Exercise 1-23
	Write a program to remove all comments from a C program. Don’t forget to handle
	quoted strings and character constants properly. C comments do not nest.
	
	SIMPLE:
		//	->LINECOMMENT
		"	->QUOTES
		'	->QUOTE
		/*	->BLOCKCOMMENT
	QUOTES:QUOTE:
		isEscape?
			Y:isEscape=false
			N:input is ' / "
				Y:→SIMPLE
		output
	LINECOMMENT:
		\n		->SIMPLE
	BLOCKCOMMENT:
		* /		->SIMPLE
	*/
	char data[MAXSIZE];
	getInput(data);
	removeComment(data);
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
#define TABLEN 8
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
#undef TABLEN
#define LINELEN 8
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
#undef LINELEN
#define SIMPLE 0
#define QUOTE 1
#define QUOTES 2
#define LINECOMMENT 3
#define BLOCKCOMMENT 4
void removeComment(char data[]) {
	bool isEscape = false;
	int read = 0, write = 0, state = SIMPLE;
	while (data[read] != '\0') {
		switch (state)
		{
		case SIMPLE:
			if (data[read] == '/' && data[read + 1] == '/') {
				state = LINECOMMENT;
				break;
			}
			if (data[read] == '/' && data[read +1] == '*') {
				state = BLOCKCOMMENT;
				break;
			}
			if (data[read] == '\'')
				state = QUOTE;
			if (data[read] == '\"')
				state = QUOTES;
			data[write] = data[read]; write++;
			break;
		case QUOTE:
			if (isEscape)
				isEscape = false;
			else
				if (data[read] == '\'')
					state = SIMPLE;
				else if (data[read] == '\\')
					isEscape = true;
			data[write] = data[read]; write++;
			break;
		case QUOTES:
			if (isEscape)
				isEscape = false;
			else
				if (data[read] == '\"')
					state = SIMPLE;
				else if (data[read] == '\\')
					isEscape = true;
			data[write] = data[read]; write++;
			break;
		case LINECOMMENT:
			if (data[read] == '\n') {
				data[write] = data[read]; write++;
				state = SIMPLE;
			}
			break;
		case BLOCKCOMMENT:
			if (data[read] == '*' && data[read + 1] == '/') {
				read++;
				state = SIMPLE;
			}
			break;
		default:
			break;
		}
		read++;
	}
	data[write] = '\0';
}
#undef SIMPLE
#undef QUOTE
#undef QUOTES
#undef LINECOMMENT
#undef BLOCKCOMMENT