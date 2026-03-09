#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// 字符串库函数： 是C提供的一套函数，用于方便的操作字符串。 
	char *p = "hello world.....";

	// 现在，想算p的字符串长度。 
	// 怎么做？  strlen 

	// 比如，现在，想将一个字符串复制到另外一个字符串。 
	// strcpy    string copy
	char str1[50] = { 0 };
	//str1 = p;

	// 比如，现在想完成两个字符串的拼接。 
	// strcat

	// 想完成两个字符串内容的比较。 
	// strcmp  
	char str2[] = "hello";
	char str3[] = "hello";

	str2 == str3;

	// 讲解方式： 
	// 1.怎么用。 
	// 2.怎么实现的，自己实现怎么完成。 因为后期字符串比较多，所以前期先练手
	// 不然到了后期，直接开始写难得字符串处理，会bug很多。 
}

int main(void) {

	return 0;
}