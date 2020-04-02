#include<stdio.h>
int main();
int main() {
	// Exercise 1-8
	// 写一个程序统计tab 空格 换行符的个数
	// Write a program to count blanks, tabs, and newlines.
	int input;
	int blanksNumber, tabsNumber, newlinesNumber;
	blanksNumber = tabsNumber = newlinesNumber = 0;
	while ((input = getchar()) != EOF) {
		if (input == ' ') ++blanksNumber;
		if (input == '\t')++tabsNumber;
		if (input == '\n')++newlinesNumber;
	}
	printf("blanks:%10.d\ntabs:%10.d\nnewlines:%10.d", blanksNumber, tabsNumber, newlinesNumber);
}
