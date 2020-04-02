#include <stdio.h>
#define MAXLINE 1000
int main();
int getline(char[], int);
int main()
{
	// Exercise 1-17
	// 写一个程序输出输入中所有长度大于80的行
	// Write a program to print all input lines that are longer than 80 characters.
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > 80)
			printf("%s", line);
	}
}
int getline(char s[], int lim)
{
	int c = 0, i;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		s[i % (lim - 1)] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	if (i < lim)
		s[i] = '\0';
	else
		s[lim - 1] = '\0';
	return i;
}