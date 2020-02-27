#include<stdio.h>
#define WORD 0
#define BLANK 1
#define MAXSIZE 1000
int main();
void input(int[]);
void output(int[]);
int maxNumber(int[]);
int main() {
	// Exercise 1-13
	// Write a program to print a histogram of the lengths of words in its input. 
	// It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
	int data[MAXSIZE];
	input(data);
	output(data);
}
int maxNumber(int numbers[]) {
	int max = 0;
	for (int i = 0; numbers[i] != -1; ++i) {
		if (numbers[i] > max) {
			max = numbers[i];
		}
	}
	return max;
}
void input(int data[]) {
	int state, c, i;
	state = BLANK;
	i = 0;
	data[i] = 0;
	// 输入处理
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (state != BLANK) {
				++i;
				data[i] = 0;
			}
			state = BLANK;
		}
		else {
			data[i]++;
			state = WORD;
		}
	}
	data[i] = -1;
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
		for (int i = 0; data[i] != -1; ++i)
			if (maxLen < data[i])
				printf("■\t");
			else
				printf("\t");
		printf("\n");
	}
	// output down head
	printf("\t");
	for (int i = 0; data[i] != -1; ++i)
		printf("%d\t", i + 1);
}