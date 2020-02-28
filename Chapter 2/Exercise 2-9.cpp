#include <stdio.h>
int bitcount(int);
int main()
{
	/*Exercise 2-9
	In a two’s complement number system, x &= (x−1) deletes the
	rightmost 1-bit in x. Explain why. Use this observation to write a
	faster version of bitcount.
	*/
	return bitcount(1023);

}
int bitcount(int i) {
	int result = 0;
	while (i != 0) {
		result++;
		i &= (i - 1);
	}
	return result;
}