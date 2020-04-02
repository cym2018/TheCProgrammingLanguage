#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20
int main();
double celToFah(double);
double fahToCel(double);
int main() {
	// Exercise 1-15
	// 重写温度转换程序,使用函数转换温度
	// Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
	printf("%12s%12s\n", "fahrenheit", "celsius");
	for (double fah = LOWER; fah <= UPPER; fah += STEP) {
		printf("%12.0f%12.1f\n", fah, fahToCel(fah));
	}
	printf("%12s%12s\n", "celsius", "fahrenheit");
	for (double cel = LOWER; cel <= UPPER; cel += STEP) {
		printf("%12.0f%12.1f\n", cel, celToFah(cel));
	}
	return 0;
}

double celToFah(double cel)
{
	return cel / 5 * 9 + 32;
}

double fahToCel(double fah)
{
	return (fah - 32) * 5 / 9;
}
