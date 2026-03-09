#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1();

void test1() {
	printf("test1 1.\n");
	printf("test1 2.\n");
	return;
	printf("test1 3.\n");
	printf("test1 4.\n");
}

void test2(int num) {
	// for  while 
	for (int i = 0; i < num; i++) {
		printf("========%d\n", i);

		return;
	}

	// num1, num2
	// 10   8 ==> 1+2+3+...+10 + 1+2+3+...8
	// 1+2+3+4+....+num1
	// 1+2+3+4+....+num2 
}

int test3(int num1, int num2) {
	int sum = 0;
	for (int i = 1; i <= num1; i++) {
		// 1 2 ... num1
		sum += i;
	}

	for (int i = 1; i <= num2; i++) {
		sum += i;
	}
	printf("%d", sum);
	return sum;
}

int main(void) {

	// 无入参，无返回值
	test1();
	//test1();

	// 有一个参数，没有返回值
	test2(5);

	// 有两个参数，有返回值
	test3(3, 4);

	return 0;
}