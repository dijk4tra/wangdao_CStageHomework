#define _CRT_SECURE_NO_WARNINGS //防止编译报错
#include <stdio.h>

int main() {
	int x, y;
	printf("请输入x的值：");
	scanf("%d", &x);	//读取用户输入的整数值赋给变量x

	if (x < 5) {
		y = x;
	}
	else if (x >= 5 && x < 15) {
		y = x + 6;
	}
	else {
		y = x - 6;
	}

	printf("计算结果 y = %d\n", y); //输出结果
	return 0;
}

/*
#include <stdio.h>

int main() {
	int x, y;
	printf("请输入x的值：");
	scanf("%d", &x);

	if (x < 5) y = x;
	else if (x >= 5 && x < 15) y = x + 6;
	else if (x >= 15) y = x - 6;

	printf("计算结果y = %d", y);
	return 0;

}*/