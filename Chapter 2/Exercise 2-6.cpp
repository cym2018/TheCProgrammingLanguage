#include <stdio.h>
int setbits(int, int, int, int);
void showInBinary(int);
int main()
{
	/*Exercise 2-6
	写一个函数setbits(x,p,n,y),将x最右侧的n位替换为y右侧的n位,不改变其他位
	Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position
	p set to the rightmost n bits of y, leaving the other bits unchanged.
	*/
	printf("\n%10.d:", 682);
	showInBinary(682);
	printf("\n%10.d:", 85);
	showInBinary(85);
	printf("\n%10.d:", setbits(682, 2, 5, 85));
	showInBinary(setbits(682, 2, 5, 85));
}
int setbits(int x, int p, int n, int y) {
	int  block = (~(~0u << n)<<p);
	x &= ~block;
	y = (y<<p)&block;
	return x|y;
}
void showInBinary(int num) {
	int result[32], i = 0;
	for (i = i; i <32; i++) result[i] = 0;
	i = 0;
	while (num != 0) {
		result[i++] = num % 2;
		num /= 2;
	}
	for (i = 0; i < 32; i++) {
		printf("%d", result[32 - i - 1]);
	}
}