#include<stdio.h>
#include<ctype.h>
void itob(__int8, char[], __int8);
void itoa(__int8, char[]);
void reverse(char[]);
int getLen(char[]);
int toChar(int);
int main() {
	/*Exercise 3-5
	Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s.
	In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
	*/
	__int8 n;
	char a[8];
	n = 0; itob(n, a,16); printf("%s\n", a);
	n = 1; itob(n, a,16); printf("%s\n", a);
	n = -1; itob(n, a,16); printf("%s\n", a);
	n = 10; itob(n, a,16); printf("%s\n", a);
	n = -10; itob(n, a,16); printf("%s\n", a);
	n = 100; itob(n, a,16); printf("%s\n", a);
	n = -100; itob(n, a,16); printf("%s\n", a);
	n = 127; itob(n, a,16); printf("%s\n", a);
	n = -128; itob(n, a,16); printf("%s\n", a);
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
void itoa(__int8 n, char a[]) {
	const __int8  b = 10;
	__int8 sign = n, i = 0;
	do {
		a[i++] = toChar(n % b);
	} while ((n=n/b) != 0);
	if (sign < 0)
		a[i++] = '-';
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