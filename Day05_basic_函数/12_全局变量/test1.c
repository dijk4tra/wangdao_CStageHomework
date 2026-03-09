#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 全局变量不能同名
//int global_num666 = 1008611;

// 这个就是，直接在全局找一个叫 global_num666 的全局变量
// 一定要使用 extern 这个语法
extern int global_num666;

void test1111() {
	printf("66666 in test1111() in test1.c\n");

	printf("global num666 = %d in test1.c\n", global_num666);

	global_num666 = 123456;
	// 使用 extern 后，即可在test1.c内访问并修改在main.c中定义的全局变量global_num666

}