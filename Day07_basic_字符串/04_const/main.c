#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 指针和const结合的时候，效果问题。 
	const int num = 10;
	//num = 999;
}

void test2() {
	int num1 = 123;
	int num2 = 456;

	// int const *p = &num1;
	//const int *p = &num1;

	int *const p = &num1;

	//*p = 999;
	//p = &num2;

	// 加了const。有什么效果。 

	// const 整体修饰的是谁，就是谁不能动。 
	// 看它的右边是谁。 
}

void test3() {
	// const整体修饰的右边是谁，谁就不能动。 

	// int const *p = &num1;
	// const整体修饰的是  *p
	// 
	//const int *p = &num1;
	// const整体修饰的是  *p

	// int *const p = &num1;
	// const整体修饰的是  p
	// constant pointer 

	// constant pointer    pointer to the constant 

	// 有啥用，后续我们再说。 
	// 传入参数 
	// 传入传出参数。 

	// 数组名是什么
	// 数组指针 + 1偏移多少个字节

}


int main(void) {

	return 0;
}