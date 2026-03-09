#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	//同一个"{}"内部不允许定义同名局部变量。
	// 不建议，整一些同名的局部变量，及其容易翻车。 

	int num = 1234;
	//int num = 6543; // error

	printf("1-----%d\n", num);

	if (1 == 1) {
		int num = 987654;
		printf("2-----%d\n", num);
	}

	printf("3-----%d\n", num);
	return 0;
}