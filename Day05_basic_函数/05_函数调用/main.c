#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test2() {
	printf("test2 before.\n");
	printf("test2 after.\n");
}
void test1() {
	printf("test1 before.\n");
	test2();
	printf("test1 after.\n");
}
int main(void) {
	printf("main before.\n");
	test1();
	printf("main after.\n");

	// 函数的进出顺序，和栈的进出顺序一模一样
	// 所以，才会使用栈来存储函数调用过程。
	return 0;
}