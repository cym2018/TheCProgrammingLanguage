#include <stdio.h>
void expand(char[], char[]);
int main()
{
	/*Exercise 3-3
	写一个函数解释字符串s1 将a-z转换成abc...xyz保存在s2中,允许字母和数字,允许处理类似于a-b-c和a-z0-9和-a-z,将开头或结尾的- 原样输出
	Write a function expand(s1,s2) that expands shorthand notations like a-z in
	the string s1 into the equivalent complete list abc...xyz in s2. Allow for
	letters of either case and digits, and be prepared to handle cases like a-b-c
	and a-z0−9 and -a-z. Arrange that a leading or trailing - is taken literally.
	*/
	char a[1000] = "-A-z-y-cd--", b[1000];
	expand(a, b);
	printf("%s", b);
}

void expand(char s1[], char s2[]) {
	enum STATE { START, HEAD, TAIL };
	enum TYPE { NUMBER, UPPER, LOWER, LINE, OTHER };
	int read = 0, write = 0, state = START, last, lastType, type;
	while (s1[read] != '\0') {
		if (s1[read] >= 'a' && s1[read] <= 'z')
			type = LOWER;
		if (s1[read] >= 'A' && s1[read] >= 'Z')
			type = UPPER;
		else if (s1[read] >= '0' && s1[read] <= '9')
			type = NUMBER;
		else if (s1[read] == '-')
			type = LINE;
		else
			type = OTHER;
		switch (state)
		{
		case START:
		{
			last = s1[read];
			if (type == UPPER||type==LOWER || type == NUMBER) {
				state = HEAD;
				lastType = type;
			}
			else
				s2[write++] = s1[read];
			read++;
		}
		break;
		case HEAD:
		{
			if (type == LINE)
				state = TAIL;
			else if (type == UPPER||type==LOWER || type == NUMBER) {
				s2[write++] = last;
				last = s1[read];
				state = HEAD;
				lastType = type;
			}
			else
				type = START;
			read++;
		}
		break;
		case TAIL:
		{
			if (lastType == type) {
				for (int i = last; i < s1[read]; i++)
					s2[write++] = i;
				for (int i = last; i > s1[read]; i--)
					s2[write++] = i;
				last = s1[read];
				lastType = type;
				state = HEAD;
			}
			else if (type == UPPER||type==LOWER || type == NUMBER) {
				s2[write++] = last;
				s2[write++] = '-';
				last = s1[read];
				lastType = type;
				state = HEAD;
			}
			else {
				s2[write++] = last;
				s2[write++] = '-';
				s2[write++] = s1[read];
				state = START;
			}
			read++;
		}
		break;
		}
	}
	if (state == TAIL)
		s2[write++] = '-';
	if (state == HEAD)
		s2[write++] = last;
	s2[write] = '\0';
}
