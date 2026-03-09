#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>
#include <string.h>

void ReverseString(char s[]) {
	int len = strlen(s);
	for (int i = 0; i < len / 2; i++) {
		// 交换s[i]和s[len - 1 - i]
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}

void itoa(int n, char s[]) {
	int i = 0, sign = n;
	if (sign < 0) n = -n; // 处理负数

	do {					// do-while循环(先做后问,直接用while无法处理n=0的情况)
		int digit = n % 10;	// 取最后一位数字(比如123的中3)
		s[i] = digit + '0'; // 将数字转换为字符并存进数组(数字3变成字符'3')
		i++;				// 数组下标后移
		n = n / 10;			// 去掉最后一位数字(比如123变成12)
	} while (n > 0);		// 只要n还大于0，就继续循环

	if (sign < 0) {
		s[i] = '-'; // 添加负号
		i++;
	}
	s[i] = '\0'; // 添加字符串结束符
	ReverseString(s); // 反转字符串
}

int main() {
	int n;
	char str[20]; // 假设转换后的字符串不会超过19个字符
	printf("请输入一个整数：");
	scanf("%d", &n);
	itoa(n, str);
	printf("转换后的字符串是: %s\n", str);
	return 0;
}