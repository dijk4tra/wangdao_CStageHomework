#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 路径分两种： 绝对路径，相对路径。 
	// windwos从盘符开始。 C:\cproject\1.txt 
	// Linux 从 /。 /home/zhou/2222.txt
	// 相对路径： 从某一个位置开始，也就是需要知道相对路径的起点，才能知道路径

	FILE *fp = fopen("C:\\Users\\liwenshuo\\source\\repos\\Day15_basic_文件流\\02_fopen\\1.txt", "r");

	// fp 为NULL。 表明打开失败； 不为NULL表明成功

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("fopen success.\n");
}

void test2() {
	// 在工作中，使用相对路径居多。 
	// 相对路径的起点是： 当前项目根目录。 
	//FILE *fp = fopen("777.txt", "r");
	//FILE *fp = fopen("888.txt", "r");
	FILE *fp = fopen("test1\\test2\\123123.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	printf("fopen success.\n");
}


int main(void) {

	//test1();
	test2();

	return 0;
}