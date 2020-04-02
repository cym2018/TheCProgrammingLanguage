#include <stdio.h>
#define MAXLINE 10
int main();
int getline(char[], int);
void copy(char[], char[]);
int main()
{
	// Exercise 1-16
	// 重写最长行函数,使他可以统计任意长度的行,并且输出尽可能多的内容
	// Revise the main routine of the longest-line program so it will
	// correctly print the length of arbitrarily long input lines, and as much as possible of the text.
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		printf("%d\n", len);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("%s", longest);
	return 0;
}
int getline(char s[], int lim)
{
	int c=0, i;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		s[i%(lim-1)] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	if(i<lim)
	s[i] = '\0';
	else
		s[lim-1] = '\0';
	return i;
}
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}