#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 转换等级了解一下，基本就是根据这个类型能表示的范围，能表示的数的范围越大，等级越高
	// 整数，基本就是按照字节数，short < int < long < long long
	// float虽然是4字节，但是是科学计数法，所以范围要比整数大
	// 整数 < float < double
	// 每个类型就相当于一个水桶，转换等级就是比较哪个桶更大，更能装
	// 了解转换等级，可以知道数据转换时的风险：数据会不会溢出？

	// 转换等级，就是一个类型，能装多少东西。 
	// short  int  long    long long 
}

void test2() {
	// 转换等级，有什么用？
	// 就是可以判断多种类型在进行计算的时候，结果是什么类型

	// int + long ，结果的类型为long
	// int + long long ，结果的类型为long long

	int int1 = 10;
	long long1 = 20L;
	long long longlong1 = 30LL;

	float f1 = 30.14f;
	double d1 = 3.333;

	printf("%d\n", sizeof(int1 + long1));        // 结果的类型为long，4 Byte
	printf("%d\n", sizeof(long1 + long1));		 // 结果的类型为long，4 Byte
	printf("%d\n", sizeof(long1 + longlong1));   // 结果的类型为long long，8 Byte
	printf("%d\n", sizeof(f1 + longlong1));		 // 结果的类型为float，4 Byte
	printf("%d\n", sizeof(f1 + d1));			 // 结果的类型为double，8 Byte
	printf("%d\n", sizeof(d1 + longlong1));		 // 结果的类型为double，8 Byte
}


void test3() {
	// char + char   ==> int
	// char + short  ==> int
	// short + short ==> int

	// 因为它们的表示范围有限，非常容易越界。所以C做了特殊处理。 
}

int main(void) {

	int a = 10.1;       // 隐式类型转换，数据截断
	char b = 97.9f;     // 隐式类型转换，数据截断
	double c = 0.1;
	float d = c;        // 隐式类型转换，数据精度丢失

	test2();

	return 0;
}