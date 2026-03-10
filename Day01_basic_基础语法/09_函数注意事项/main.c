#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	printf("test1========\n");
}

//void test2();
//int test3();

int main(void) {
	// 尽量要将被调用的函数，放在上面。 
	// 有一种情况，无法放上去。 
	//test1();
	test2();
	//test3();

	return 0;
}

void test2() {
	printf("test2========\n");
}

int test3() {
	printf("test3========\n");
}