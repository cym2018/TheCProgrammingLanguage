#include <stdio.h>
#define MAXSIZE 1000
#define CHARACTER 0
#define BLANK 1
#define NEWLINE 2
int main();
void reverse(char[]);
int getLen(char[]);
int main()
{
	// Exercise 1-19
	// 写一个reverse(s)函数反转输入的字符顺序
	// Write a function reverse(s) that reverses the character
	// string s. Use it to write a program that reverses its input a line at a time.
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
	for (int i = 0; i < dataLen; ++i) {
		if (data[i] == '\n')data[i] = '|';
	}
	reverse(data);
	printf("%s", data);
}
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
int getLen(char data[]) {
	int len = 0;
	while (data[len] != '\0')
		++len;
	return len;
}