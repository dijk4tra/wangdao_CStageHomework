#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)) / sizeof(arr[0]))

void test1() {
    // 现在，想要将数组中的元素全部取出，怎么做？
	int arr[] = { 10,20,33,44,555,666,777,88 ,99,100,110 };

	for (int i = 0; i < 8; i++) {
		printf("%d--------%d\n", i, arr[i]);

		// 将数据修改掉。  
		//  0   10   20   30   40   50   60  
		arr[i] = i * 10;
	}

	for (int i = 0; i < 8; i++) {
		printf("%d==========%d\n", i, arr[i]);
	}

}

void test2() {
	int arr[] = { 10,20,33,44,555,666,777,88,99,100,110,1111,2222,3333 };
	// 数组长度的获取
	// sizeof(arr)：计算数组arr占据的空间大小，单位是字节

	printf("%d\n", sizeof(arr));

	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
		printf("%d==========%d\n", i, arr[i]);

		// 将数据修改掉。  
		//  0   10   20   30   40   50   60  
		arr[i] = i * 10;
	}

	//for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) 
	for (int i = 0; i < ARR_LEN(arr); i++) {
		printf("%d==========%d\n", i, arr[i]);
	}
}

int main(void) {
	//test1();
	test2();
    return 0;
}