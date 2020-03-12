#include<stdio.h>
#include<ctype.h>
void itoa(__int8, char[]);
void reverse(char[]);
int getLen(char[]);
int main() {
    /*Exercise 3-4
    In a two’s complement number representation, our version of itoa does not handle the largest negative number,
     that is, the value of n equal to −(2wordsize−1). Explain why not. Modify it to print that value correctly,
      regardless of the machine on which it runs.
    */
	__int8 n;
	char a[8];
	n = 0; itoa(n, a); printf("%s\n", a);
	n = 1; itoa(n, a); printf("%s\n", a);
	n = -1; itoa(n, a); printf("%s\n", a);
	n = 10; itoa(n, a); printf("%s\n", a);
	n = -10; itoa(n, a); printf("%s\n", a);
	n = 100; itoa(n, a); printf("%s\n", a);
	n = -100; itoa(n, a); printf("%s\n", a);
	n = 127; itoa(n, a); printf("%s\n", a);
	n = -128; itoa(n, a); printf("%s\n", a);
}
void itoa(__int8 n, char a[]) {
	__int8 sign = n, i = 0;
	a[i++] = '0' + (sign < 0 ? -n % 10 : n % 10);
	n = sign < 0 ? -n / 10 : n / 10;
	while (n != 0) {
		a[i++] = (n % 10) + '0';
		n /= 10;
	}
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