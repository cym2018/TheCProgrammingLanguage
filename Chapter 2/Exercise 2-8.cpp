#include <stdio.h>
unsigned setbits(unsigned, unsigned, unsigned, unsigned);
unsigned invert(unsigned, unsigned, unsigned);
unsigned rightrot(unsigned, unsigned);
void showInBinary(unsigned);
int main()
{
	/*Exercise 2-8
	Write a function rightrot(x,n) that returns the value of the integer x
	rotated to the right by n bit positions.
	*/
	unsigned result = rightrot(3, 1);
	printf("\n%u:", 3);
	showInBinary(3);
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
unsigned rightrot(unsigned x, unsigned n){
	unsigned block = ~(~0u << n);
	block &= x;
	x >>= n;
	block <<= (32 - n);
	return block|x;
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