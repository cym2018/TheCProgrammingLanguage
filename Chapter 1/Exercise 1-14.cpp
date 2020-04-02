#include<stdio.h>
#define WORD 0
#define BLANK 1
#define MAXSIZE 256
int main();
void input(int[]);
void output(int[]);
int maxNumber(int[]);
int main() {
	// Exercise 1-14
	// 写一个函数输出不同字符的输入频率
	// Write a program to print a histogram of the frequencies of different characters in its input.
	int data[MAXSIZE];
	input(data);
	output(data);
}
void input(int data[]) {
	for (int i = 0; i < MAXSIZE; ++i)
		data[i] = 0;
	int input;
	while ((input = getchar()) != EOF) {
		if (input > 30)
			data[input]++;
	}
}
int maxNumber(int numbers[]) {
	int max = 0;
	for (int i = 0; i < MAXSIZE; ++i) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
	return max;
}
void output(int data[]) {
	int maxLen = maxNumber(data) + 2;
	while (maxLen--) {
		// output left head
		if (maxLen % 3 == 0)
			printf("%d\t", maxLen);
		else
			printf("\t");

		// output data
		for (int i = 0; i < MAXSIZE; ++i)
			if (maxLen < data[i] && data[i] != 0)
				printf("■\t");
			else if (data[i] != 0)
				printf("\t");
		printf("\n");
	}
	// output down head
	printf("\t");
	for (int i = 0; i < MAXSIZE; ++i)
		if (data[i] != 0)
			printf("%c\t", i);
}