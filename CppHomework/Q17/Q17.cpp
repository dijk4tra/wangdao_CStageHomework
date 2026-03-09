#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	char c;
	int letter_count = 0;
	int space_count = 0;
	int number_count = 0;
	int other_count = 0;

	printf("请输入一行字符：\n");
	while (1) {
		c = getchar(); //依次读取字符
		if (c == '\n') {
			break; // 遇到换行符结束输入
		}
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
			letter_count++; // 英文字母
		}
		else if (c == ' ') {
			space_count++; // 空格
		}
		else if (c >= '0' && c <= '9') {
			number_count++; // 数字
		}
		else {
			other_count++; // 其他字符
		}
	}

	printf("英文字母个数: %d\n", letter_count);
	printf("空格个数: %d\n", space_count);
	printf("数字个数: %d\n", number_count);
	printf("其他字符个数: %d\n", other_count);
	
	return 0;
}