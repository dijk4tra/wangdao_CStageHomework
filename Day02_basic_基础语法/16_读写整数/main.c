#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int num = 17;
	int num2 = 017;  // 7 + 1*8^1 = 15（八进制）


	printf("%d\n", num);
	printf("%d\n", num2);

	printf("%o\n", num); // 17   =====   21(8)
	printf("%o\n", num2);


	return 0;
}