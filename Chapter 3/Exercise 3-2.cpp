#include <stdio.h>
void escape(char[], char[]);
void disescape(char[], char[]);
int main()
{
	/*Exercise 3-2
	写一个函数将\n或者\t转换为换行符和制表符
	Write a function escape(s,t) that converts characters like newline and tab
	into visible escape sequences like \n and \t as it copies the string t to s.
	Use a switch. Write a function for the other direction as well, converting
	escape sequences into the real characters.
	*/
	// test escape
	int i = 0;
	char s1[1000], s2[1000];
	while ((s1[i] = getchar()) != EOF)
		i++;
	s1[i] = '\0';
	escape(s1, s2);
	printf("\ns1:%s\ns2:%s\n", s1, s2);
	// test disescape
	i = 0;
	while ((s1[i] = getchar()) != EOF)
		i++;
	s1[i] = '\0';
	disescape(s1, s2);
	printf("\ns1:%s\ns2:%s\n", s1, s2);
	return 0;
}
void escape(char s1[], char s2[])
{
	int read = 0, write = 0;
	while (s1[read] != '\0') {
		switch (s1[read]) {
		case '\n':
			s2[write++] = '\\';
			s2[write++] = 'n';
			break;
		case '\t':
			s2[write++] = '\\';
			s2[write++] = 't';
			break;
		default:
			s2[write++] = s1[read];
		}
		read++;
	}
	s2[write] = '\0';
}
void disescape(char s1[], char s2[]) {
	int read = 0, write = 0;
	while (s1[read] != '\0')
	{
		switch (s1[read]){
		case '\\':
			read++;
			if (s1[read] == 't')
				s2[write++] = '\t';
			if (s1[read] == 'n')
				s2[write++] = '\n';
			break;
		default:
			s2[write++] = s1[read];
		}
		read++;
	}
	s2[write] = '\0';
}
