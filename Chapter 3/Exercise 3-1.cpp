#include <stdio.h>
int binsearch(int, int[], int);
int main()
{
	/*Exercise 3-1
	我们的二进制搜索使用了两个判断在循环体中,写一个只循环体中只有一个判断语句的版本
	Our binary search makes two tests inside the loop, when one would suffice
	(at the price of more tests outside). Write a version with only one test inside
	the loop and measure the difference in run-time.
	*/
	int data[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 11; i++)
		printf("%d %c", binsearch(i, data, 10), i % 5 == 0 ? '\n' : '\t');
	return 0;
}
int binsearch(int x, int v[], int n){
	int low = 0, high = n, mid;
	while (low != high) {
		mid = (low + high) / 2;
		if (v[mid] < x)
			low = mid + 1;
		else
			high = mid;
	}
	if (v[low] == x)
		return low;
	return -1;
}