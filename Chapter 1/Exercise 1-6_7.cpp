#include<stdio.h>
int main() {
	// Exercise 1-6
	// 验证getchar()!=EOF的值,输出EOF的值
	// Verify that the expression getchar() != EOF is 0 or 1.
	// Exercise 1-7
	// Write a program to print the value of EOF.
	
	printf("%d\n", EOF);
	// Press Ctrl+C to exit the program
	while(true){
		printf("%d", getchar() != EOF);
	}
	return 0;
}