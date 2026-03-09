#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	printf("test1 before.\n");

	for (int i = 0; i < 10; i++) {
		printf("test1=======%d\n", i);
	}

	printf("test1 after.\n");
}


int main(void) {

	// 调试，其实就是在做信息的比对。 
	// 对代码运行的预期 vs 实际的运行结果

	// 如果直接运行，代码会从上到下执行。 
	// 并不会等待，或者给你中间的过程。 需要调试，才有机会看到。 

	// 调试的第一步： 就是在合适的地方打断点。 
	// 断点，就是你和系统约定的一个信号，一个位置。 

	// 调试的第二步： 就是让代码一步一步往下走，或者说快速往下走直到断点。 

	int sum = 0;

	for (int i = 0; i <= 10; i++) {
		sum += i;
	}

	// 0+1+2+3+4+..+9 = 45
	printf("sum = %d\n", sum);

	test1();



	return 0;
}