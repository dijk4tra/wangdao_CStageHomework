#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1(double *p) {
	// 在test1当中，拿到的p。 
	// 关键点，是p自己，还是什么？
	// 我们关心，p要指向一块内存，而且一定要是有效的内存。 double内存
	double val = *p + 10;
	printf("test1------%lf\n", val);
}

int main(void) {
	// test1中，需要double类型指针。 怎样构造这个参数。 
	//double d1 = 3.14;
	//double *pd1 = &d1;
	//test1(pd1);
	//test1(&d1);

	//double *pd2 = NULL;
	//test1(pd2);

	double arr[5] = { 3.11,3.12,3.13,3.14,3.15 };
	test1(arr);


	return 0;
}