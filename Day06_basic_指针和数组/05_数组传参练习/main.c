#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find_max_and_min(int arr[], int len, int *p_max, int *p_min) {
	int max_value = arr[0];
	int min_value = arr[0];

	for (int i = 0; i < len; i++) {
		if (arr[i] > max_value) {
			max_value = arr[i];
		}

		if (arr[i] < min_value) {
			min_value = arr[i];
		}
	}
	// 在C语言中，指针，有两个功能。 
	// 第一个功能，就是将数据传入某个函数。 这个叫做传入参数。 
	// 第二个功能，可以将数据带出。 
	*p_max = max_value;
	*p_min = min_value;
}

void test1() {
	// 现在，有一个数组，数组里面有一些数据，你需要找到最大值，最小值。 

	int arr[] = { 10,20,60,200,300,50,40,90,33,88,70,1000,3000,2,5,33 };

	// 现在，需要你使用函数来完成，怎样完成？
	ARR_LEN(arr);

	// 思路1： 使用两个函数。 
	// 思路2： 可以传指针进去，将数据带回来。 

	// change_int_by_int
	// change_int_by_pointer
}

void test2() {
	int arr[] = { 10,20,60,200,300,50,40,90,33,88,70,1000,3000,2,5,33 ,9000, -10 };

	// 可以使用指针，将数据带回来。 

	//int max = 0;
	//int min = 0;
	//find_max_and_min(arr, ARR_LEN(arr), max, min);

	// change_int_by_int
	// change_int_by_pointer
	int max = 0;
	int min = 0;

	int *p_max = &max;
	int *p_min = &min;
	find_max_and_min(arr, ARR_LEN(arr), p_max, p_min);

	printf("test2=========max=%d\n", max);
	printf("test2=========min=%d\n", min);
}

int main(void) {
    
	test2();

    return 0;
}