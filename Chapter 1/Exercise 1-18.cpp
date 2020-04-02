#include <stdio.h>
#define MAXSIZE 1000
#define CHARACTER 0
#define BLANK 1
#define NEWLINE 2
int main();
int main()
{
	// Exercise 1-17
	// 写一个函数移除每一行末的空格或制表符,删除完全空白的行
	// Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
	char data[MAXSIZE], buffer[MAXSIZE];
	int input, dataLen, bufferLen, state;
	input = dataLen = bufferLen = 0;
	state = NEWLINE;
	while ((input = getchar()) != EOF) {
		if (input == '\t' || input == ' ') {
			buffer[bufferLen] = input;
			++bufferLen;
		}
		else if (input >= 33 && input <= 126) {
			for (int i = 0; i < bufferLen; i++) {
				data[dataLen] = buffer[i];
				++dataLen;
			}
			bufferLen = 0;
			data[dataLen] = input;
			dataLen++;
			state = CHARACTER;
		}
		else if (input == '\n') {
			bufferLen = 0;
			if (state != NEWLINE) {
				data[dataLen] = input;
				++dataLen;
				state = NEWLINE;
			}
		}
	}
	data[dataLen] = '\0';
	for (int i = 0; i < dataLen; i++) {
		if (data[i] == '\n')data[i] = '|';
	}
	printf("%s", data);
}