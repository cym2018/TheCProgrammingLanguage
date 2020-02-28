#include <stdio.h>
void lower(char[]);
int main()
{
	/*Exercise 2-10
	Rewrite the function lower, which converts upper case letters
	to lower case, with a conditional expression instead of if-else.
	*/
	char a[30]="123abcABC!@#";
	printf("before:%s", a);
	lower(a);
	printf("\nafter:%s", a);
}
void lower(char s[]) {
	for (int i = 0; s[i] != '\0'; i++) {
		s[i] = s[i] >= 'A' && s[i] <= 'Z' ? s[i] - 'A' + 'a' : s[i];
	}
}