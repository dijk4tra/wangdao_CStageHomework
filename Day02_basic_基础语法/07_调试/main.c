#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int arr[] = { 10,20,30,40,50 };

	// 错误示例，运行时会出现数组越界（Buffer Overflow），这里应该是i<5
	for (int i = 0; i <= 5; i++) { 
		printf("%d\n", arr[i]);

		// 错误示例，将‘==’错写为‘=’，导致数组内所有元素的值都被改为10
		// 在C语言中，赋值表达式的值就是被赋的值。因为10是非零数，所以if条件永远被判定为真（True）
		if (arr[i] = 10) {
			printf("arr[i] == 10\n");
		}
	}

	return 0;
}