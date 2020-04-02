#include<stdio.h>
#define MAXSIZE 1000
#define BLANK 0
#define NOTBLANK 1
int main();
int main() {
	// Exercise 1-9
	// 写一个程序,将输入复制到输出,将多个连续的空格转换为单个空格
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
