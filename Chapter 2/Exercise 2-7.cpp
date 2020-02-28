#include <stdio.h>
unsigned setbits(unsigned, unsigned, unsigned, unsigned);
unsigned invert(unsigned, unsigned, unsigned);
void showInBinary(unsigned);
int main()
{
	/*Exercise 2-7
	Write a function invert(x,p,n) that returns x with the n bits that begin
	at position p inverted (i.e., 1 changed into 0 and vice versa), leaving
	the others unchanged.
	*/
	unsigned result=invert(1007, 2u, 3u);
	printf("\n%u:", 1007);
	showInBinary(1007);
	printf("\n%u:", result);
	showInBinary(result);

}
unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
	unsigned  block = (~(~0u << n) << p);
	x &= ~block;
	y = (y << p) & block;
	return x | y;
}
unsigned invert(unsigned x, unsigned p, unsigned n) {
	unsigned  block = (~(~0u << n) << p);
	return x^block;
}
void showInBinary(unsigned num) {
	int result[32], i = 0;
	for (i = i; i < 32; i++) result[i] = 0;
	i = 0;
	while (num != 0) {
		result[i++] = num % 2;
		num /= 2;
	}
	for (i = 0; i < 32; i++) {
		printf("%d", result[32 - i - 1]);
	}
}