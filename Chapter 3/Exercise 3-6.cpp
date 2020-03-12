#include<stdio.h>
#include<ctype.h>
void itob(__int8, char[], __int8);
void itoa(__int8, char[], __int8);
void reverse(char[]);
int getLen(char[]);
int toChar(int);
int main() {
	/*Exercise 3-6
	Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width;
	the converted number must be padded with blanks on the left if necessary to make it wide enough.
	*/
	__int8 n;
	char a[9];
	n = 0; itoa(n, a,8); printf("%s\n", a);
	n = 1; itoa(n, a,8); printf("%s\n", a);
	n = -1; itoa(n, a,8); printf("%s\n", a);
	n = 10; itoa(n, a,8); printf("%s\n", a);
	n = -10; itoa(n, a,8); printf("%s\n", a);
	n = 100; itoa(n, a,8); printf("%s\n", a);
	n = -100; itoa(n, a,8); printf("%s\n", a);
	n = 127; itoa(n, a,8); printf("%s\n", a);
	n = -128; itoa(n, a,8); printf("%s\n", a);
}
void itob(__int8 n, char a[], __int8 b) {
	__int8 sign = n, i = 0;
	do {
		a[i++] = toChar(n % b);
	} while ((n = n / b) != 0);
	if (sign < 0)
		a[i++] = '-';
	a[i] = '\0';
	reverse(a);

}
void itoa(__int8 n, char a[],__int8 length) {
	const __int8  b = 10;
	__int8 sign = n, i = 0;
	do {
		a[i++] = toChar(n % b);
	} while ((n=n/b) != 0);
	if (sign < 0)
		a[i++] = '-';
	while (i < length) {
		a[i++] = ' ';
	}
	a[i] = '\0';
	reverse(a);
}
void reverse(char data[])
{
	int len = getLen(data), temp;
	for (int i = 0; i < len / 2; i++) {
		temp = data[i];
		data[i] = data[len - i - 1];
		data[len - i - 1] = temp;
	}
}
int getLen(char data[]) {
	int len = 0;
	while (data[len] != '\0')
		++len;
	return len;
}
int toChar(int i) {
	if (i < 0)i = -i;
	return i < 10 ?i + '0' :i - 10 + 'A';
}