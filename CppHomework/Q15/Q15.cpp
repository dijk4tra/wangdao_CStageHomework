#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

void CheckChar(char c) {
	if (c >= 'A' && c <= 'Z') {
		printf("该字符是大写字母\n");
	}
	else if (c >= 'a' && c <= 'z') {
		printf("该字符是小写字母\n");
	}
	else {
		printf("该字符不是英文字母\n");
	}
}

int main() {
	char ch;
	printf("请输入一个字符：");
	scanf("%c", &ch);
	CheckChar(ch);
	return 0;
}