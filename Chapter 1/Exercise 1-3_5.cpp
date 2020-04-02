#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
int main();
int main() {
	// Exercise 1-3
	// 将摄氏度转换为华氏度
	// Modify the temperature conversion program to print a heading above the table.
	// Exercise 1-4
	// Write a program to print the corresponding Celsius to Fahrenheit table.
	printf("%12s%12s\n", "fahrenheit", "celsius");
	for (double fah = LOWER; fah <= UPPER; fah += STEP) {
		printf("%12.0f%12.1f\n", fah, (fah - 32) * 5 / 9);
	}
	printf("%12s%12s\n", "celsius", "fahrenheit");
	for (double cel = LOWER; cel <= UPPER; cel += STEP) {
		printf("%12.0f%12.1f\n", cel, cel / 5 * 9 + 32);
	}
	// Exercise 1-5
	// Modify the temperature conversion program to print the
	// table in reverse order, that is, from 300 degrees to 0.
	printf("%12s%12s\n", "fahrenheit", "celsius");
	for (double fah = UPPER; fah >= LOWER; fah -= STEP) {
		printf("%12.0f%12.1f\n", fah, (fah - 32) * 5 / 9);
	}
	return 0;
}