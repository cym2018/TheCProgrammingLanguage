#include <stdio.h>
#define MAXSIZE 1000
#define TABLEN 8
int main();
void reverse(char[]);
int getLen(char[]);
void getInput(char[]);
void detab(char[]);
void entab(char[]);
int main()
{
	// Exercise 1-21
	// Write a program entab that replaces strings of blanks by the minimum number of
	// tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
	// When either a tab or a single blank would suffice to reach a tab stop, which should
	// be given preference?
	//	block	current	output			operate
	//	<8		text	blank&text		block add 1
	//	<8		blank					block&blank add 1
	//	=8		text	blank&text		block to zero
	//	=8		blank	tab				block&blank to zero
	//	all		newline	blank&newline	block to zero
	//	all		tab		tab				block&blank to zero
	
	char data[MAXSIZE];
	getInput(data);
	entab(data);
}
// get input
void getInput(char data[]) {
	int input, i;
	i = 0;
	while ((input = getchar()) != EOF) {
		data[i] = input;
		i++;
	}
	data[i] = '\0';
}
// reverse string
void reverse(char data[])
{
	int len, temp;
	len = getLen(data);
	for (int i = 0; i < len / 2; i++) {
		temp = data[i];
		data[i] = data[len - i - 1];
		data[len - i - 1] = temp;
	}
}
// get string's length
int getLen(char data[]) {
	int len = 0;
	while (data[len] != '\0')
		++len;
	return len;
}
void detab(char data[]) {
	int i, textLen;
	i = 0;
	textLen = 0;
	while (data[i] != '\0') {
		if (data[i] == '\t') {
			for (textLen = TABLEN - (textLen % TABLEN); textLen > 0; textLen--)
				printf(" ");
		}
		else if (data[i] == '\n') {
			textLen = 0;
			printf("%c", data[i]);
		}
		else if (data[i] > 32 && data[i] < 127) {
			textLen++;
			printf("%c", data[i]);
		}
		++i;
	}
}
void entab(char data[]) {
	int i = 0, textLen = 0, blankLen = 0,blockLen=0;
	while (data[i] != '\0') {
		if (data[i] == '\n') {
			for (; blankLen > 0; blankLen--)
				printf(" ");
			printf("%c", data[i]);
			blankLen = blockLen=0;
		}
		if (data[i] == '\t') {
			printf("%c", data[i]);
			blankLen = blockLen = 0;
		}
		if (blockLen < TABLEN-1) {
			if (data[i] >= 33 && data[i] <= 126) {
				for (; blankLen > 0; blankLen--)
					printf(" ");
				printf("%c", data[i]);
			}
			if (data[i] == ' ') {
				blankLen++;
			}
			blockLen++;
		}
		else {
			if (data[i] >= 33 && data[i] <= 126) {
				for (; blankLen > 0; blankLen--)
					printf(" ");
				printf("%c", data[i]);
			}
			if (data[i] == ' ') {
				printf("\t");
				blankLen = 0;
			}
			blockLen = 0;
		}
		++i;
	}

}