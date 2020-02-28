#include <stdio.h>
int any(char[], char[]);
int main()
{
	/*Exercise 2-5
	Write the function any(s1,s2), which returns the first location in the string s1 where
	any character from the string s2 occurs, or −1 if s1 contains no characters from s2.
	(The standard library function strpbrk does the same job but returns a pointer to the location.)
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
	printf("\n%d\n", any(s1, s2));
}
int any(char s1[], char s2[]) {
	int i = 0;
	for (int i = 0; s1[i] != '\0'; i++)
		for (int j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j])
				return i;
		}
}