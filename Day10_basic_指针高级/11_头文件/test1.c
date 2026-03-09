#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "test1.h"

// <> 表示从系统的头文件目录中找。 
// "" 表示从当前项目中找。 

// 想在test1.c 中定义一个函数。 一个
// 两个入参 int。 返回一个int
// 三个入参 int。 返回void 

int test1(int num1, int num2) {
	return num1 + num2 + 100;
}

void test2(int num1, int num2, int num3) {
	printf("test2====%d, %d, %d\n", num1, num2, num3);
}