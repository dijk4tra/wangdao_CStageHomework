#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// 可以使用(n & (n - 1))判断正整数n是否为2的正整数幂
// 若(n & (n - 1)) == 0，则n是2的正整数幂
bool is_power_2(int n) {
	/*
		减法"-"的优先级高于"&",所以内层的()可以省略
		"=="优先级高于"&",所以外层()必须加,不能省略
	*/
	return (n & (n - 1)) == 0;
}

void test1() {
	// 2^0  2^1  2^2  2^3 2^4 ....
	// 1   2   4   8   16   32   64

	int num1 = 32;
	// 一种方式： 1 *2 *2 *2 *2

	printf("is_pow2(16) = %d\n", is_power_2(16));
	printf("is_pow2(18) = %d\n", is_power_2(18));
	printf("is_pow2(32) = %d\n", is_power_2(32));
	printf("is_pow2(64) = %d\n", is_power_2(64));

}


void test2() {
	// 1   2   4   8   16   32   64

	// 00000000001
	// 00000000010
	// 00000000100
	// 00000001000
	// 00000010000

	// 0000100000000000000000   n
	// 0000011111111111111111  n-1

	// 101000
	// 100111

}


int main(void) {


	test1();

	return 0;
}