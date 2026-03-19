#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// 关键字不能作为标识符。
	// 首字符：标识符的第一个字符必须是一个字母（大小写都可以）或下划线（_）。
	// 组成：标识符可以由字母、数字或下划线组成。
	// C语言对大小写敏感。num和Num是两个完全不同的标识符。

	//int if = 987;
	//int $abc = 666;

	// 非常不建议使用中文来做标识符。 
	// 建议全部使用英文    
	int 我 = 100;
	printf("%d", 我);

	// 文件夹建议组织好
	// 建议软件安装路径不要带中文
	// D:/develop
	// D:/软件/学习

	return 0;
}