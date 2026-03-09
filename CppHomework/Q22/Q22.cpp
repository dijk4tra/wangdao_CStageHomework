#include <stdio.h>

int main() {
	int a = 1001, b = 20020;
	
	printf("交换前: a = %d, b = %d\n", a, b);
	
	//方法一：加减法
	a = a + b; // a现在是两个数的和
	b = a - b; // b现在是原来的a
	a = a - b; // a现在是原来的b

	//方法二：异或法
	//a = a ^ b; // a现在是a和b的异或结果
	//b = a ^ b; // 用b去“解出”a，b现在是原来的a
	//a = a ^ b; // 用a去“解出”b

	printf("交换后: a = %d, b = %d\n", a, b);
	return 0;
}