#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	char str[20] = { 0 };

	//scanf("%s", str);
	scanf("%19s", str);
	// 程序员，需要关心，内存能不能用，够不够用，可不可用。 

	// 如果想控制scanf输入的长度，可以写
	// 数组长度 - 1 
}

void test2() {
	// \0  '0'   0
	char str1[5] = { '0', '1', '2', '3', '4' };

	//scanf("%s", str1);
	scanf("%4s", str1);
	//scanf("%5s", str1);
	// abcd  ===》 97 98 99 100 00
	// abcdefg    97 98 99 100 101 102 103 00
}


void test3() {
	// 内存显示问题。  
	char str1[50] = "123456789";

	str1[0] = 'a';
	str1[1] = 'b';
	str1[2] = 'c';

	str1[10] = '\0';
	str1[11] = '0';
	str1[12] = 0;
}


int main(void) {

	//test2();
	test3();

	return 0;
}