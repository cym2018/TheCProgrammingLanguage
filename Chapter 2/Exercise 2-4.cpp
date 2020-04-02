#include <stdio.h>
void squeeze(char[], char[]);
int main()
{
	/*Exercise 2-4
	写另一个版本的squeeze(s1,s2),删除s2中的每个s1
	Write an alternate version of squeeze(s1,s2) that deletes each character in s1
	that matches any character in the string s2.
	*/
	char s1[100], s2[100];
	int i = 0;
	while ((s1[i] = getchar()) != EOF)
		i++;
	s1[i] = '\0';
	i = 0;
	while ((s2[i] = getchar()) != EOF)
		i++;
	s2[i] = '\0';
	printf("\n%s\n", s1);
	printf("\n%s\n", s2);
	squeeze(s1, s2);
	printf("%s", s1);
}

void squeeze(char s1[], char s2[])
{
	enum isExist { YES, NO };
	int read = 0, write = 0, state = NO;
	while (s1[read] != '\0') {
		for (int i = 0; s2[i] != '\0'; i++)
			if (s1[read] == s2[i])
				state = YES;
		if (state == NO)
			s1[write++] = s1[read];
		read++;
		state = NO;
	}
	s1[write] = '\0';
}
