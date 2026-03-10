#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	int num1 = 10;

	//short s1 = num1;
	short s1 = (short)num1;

	// short s1 = num1;当这样写代码时，有的编译器会担心你是不是写错了 
	// 在后续，有可能编译器，会直接拒绝这个隐式转换，要求你使用强制类型转换
	// 强制类型转换，可以表明，程序员是知道这个转换的，程序员了解这种操作的风险 
}


int main(void) {

	test1();

	return 0;
}