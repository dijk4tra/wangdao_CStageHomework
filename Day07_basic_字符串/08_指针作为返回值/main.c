#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1(int *p) {

}

int *test2() {
	// 指针作为返回值的注意事项。 
	// 永远不要返回当前栈区的数据指针。 

	//int num = 10010;
	// return &num;

	// static int arr[] = { 10,20,30,40,50,60 };
	int arr[] = { 10,20,30,40,50,60 };
	return arr;
}

//int[] test2333() {
//	static int arr[] = { 10,20,30,40,50,60 };
//	return arr;
//}

void test3() {
	int *p = test2();

	// test2 在函数调用在的时候，它的栈帧上的数据是在的。 
	// 但是一旦test2函数调用结束，栈帧会被销毁。 
	printf("%d\n", *p);
	printf("%d\n", *(p + 1));
	printf("%d\n", *(p + 2));
	printf("%d\n", *(p + 3));
	printf("%d\n", *(p + 4));
}


void test4() {
	int arr[] = { 10,20,30,40,50,60 };

	// 函数调用(arr);

}

int main(void) {

	test3();

	return 0;
}