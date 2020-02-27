#include <stdio.h>
#include<float.h>
#include<limits.h>
int main();
int main()
{
	/*Exercise 2-1
	Write a program to determine the ranges of char, short, int, and long variables,
	both signed and unsigned, by printing appropriate values from standard headers
	and by direct computation. Harder if you compute them: determine the ranges
	of the various floating-point types.
	*/
	printf("UsignMaxChar:%u\n", UCHAR_MAX);
	printf("MaxChar:%d\n", CHAR_MAX);
	printf("MinChar:%d\n", CHAR_MIN);
	printf("UsignMaxShort:%u\n", USHRT_MAX);
	printf("MaxShort:%d\n", SHRT_MAX);
	printf("MinShort:%d\n", SHRT_MIN);
	printf("UsignMaxInt:%u\n", UINT_MAX);
	printf("MaxInt:%d\n", INT_MAX);
	printf("MinInt:%d\n", INT_MIN);
	printf("UsignMaxLong:%u\n", ULONG_MAX);
	printf("MaxLong:%d\n", LONG_MAX);
	printf("MinLong:%d\n", LONG_MIN);
	printf("MaxFloat:%f\n", FLT_MAX);
	printf("MinFloat:%f\n", FLT_MIN);
	printf("MaxDouble:%f\n", DBL_MAX);
	printf("MinDouble:%f\n", DBL_MIN);
}