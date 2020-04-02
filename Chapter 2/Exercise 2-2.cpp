#include <stdio.h>
#define MAXSIZE 1000
int main()
{
	/*Exercise 2-2
	写一个等价的循环不使用 && 或 ||
	Write a loop equivalent to the for loop above without using && or ||.
	*/
	int i = 0, c, lim = MAXSIZE;
	char s[MAXSIZE];
	while (c = getchar()) {
		if (c == '\n')break;
		if (c == EOF)break;
		if (i >= lim - 1)break;
		s[i] = c;
		i++;
	}
}