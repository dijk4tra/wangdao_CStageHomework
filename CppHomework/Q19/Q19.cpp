#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

long sum(int n) {
	if (n <= 0) return 0; // 处理非正整数的情况
	if (n == 1) return 1; 
	return n * n + sum(n - 1); // 递归调用
}

int main() {
	int n;
	printf("请输入一个正整数n：");
	scanf("%d", &n);
	printf("1到%d的平方和为: %ld\n", n, sum(n));
	return 0;
}