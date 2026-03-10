#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 被调用的函数，应该尽量往上放，如果无法通过位置挪动实现，可以在上面使用一个函数声明
// 先写函数声明

//void test1(int num1);
//void test2(int num1);
//void test3(int num1);

void test3(int num) {
	printf("test3-----.\n");
	if (num < 0) {
		return;
	}
	test1(num);
}

void test2(int num) {
	printf("test2-----.\n");
	test3(num - 1);
}
void test1(int num) {
	test2(num - 1);
}

int main(void) {

	test1(2);

	return 0;
}