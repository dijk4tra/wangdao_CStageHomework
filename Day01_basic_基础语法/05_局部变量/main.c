#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num666 = 789;

int main(void) {

	//在C语言中，函数内部定义的变量就是局部变量。
	//在C语言中，局部变量仅在定义它的"{}"内部生效。
	//同一个"{}"内部不允许定义同名局部变量。

	// 这个就是局部变量。 变量在 {} 内部定义的变量叫做局部变量。 
	int num = 123;

	printf("num = %d\n", num);

	if (num = 999) {
		int num987 = 987987;

		printf("num987 = %d\n", num987);
		printf("num in if = %d\n", num);
	}

	//printf("num987 = %d\n", num987);

	return 0;
}