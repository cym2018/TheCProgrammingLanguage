#include <stdio.h>
#include<ctype.h>
int htoi(char[]);
int main()
{
	/*Exercise 2-3
	写一个函数htoi(s),将string类型的数字转换成int值,允许输入0-9 a-f A-F
	Write the function htoi(s), which converts a string of hexadecimal digits
	(including an optional 0x or 0X) into its equivalent integer value. The
	allowable digits are 0 through 9, a through f, and A through F.
	*/
	char a[10] = "0xAAA";
	char b[10] = "bbb";
	printf("AAA:%d,BBB:%d\n", htoi(a), htoi(b));
}
int htoi(char a[]) {
	int i, result = 0;
	for (i = 0; a[i] != '\0'; i++)
		a[i] = tolower(a[i]);
	i = 0;
	if (a[0] == '0' && a[1] == 'x')
		i = 2;
	while (a[i] != '\0') {
		if (isdigit(a[i])) {
			result = result * 16 + a[i] - '0';
		}
		else {
			result = result * 16 + a[i] - 87;
		}
		i++;
	}
	return result;
}