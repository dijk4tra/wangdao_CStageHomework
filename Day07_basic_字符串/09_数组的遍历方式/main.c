#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

void test1() {
	// char数组。 怎么遍历。 
	char str1[] = { 'a', 'z', 'b', 'c', 'f', 'h' };

	// 方式1： 使用for循环。 
	int str_len = ARR_LEN(str1);

	for (int i = 0; i < str_len; i++) {
		printf("%c\n", str1[i]);

		if (str1[i] == 'a' || str1[i] == 'e' || str1[i] == 'i') {
			// 元音 
		}
	}

}

void test2() {
	// char数组。 怎么遍历。 
	char str1[] = { 'a', 'z', 'b', 'c', 'f', 'h' };

	// 方式2： 使用for循环。  可以使用 *(str1+i)
	int str_len = ARR_LEN(str1);

	for (int i = 0; i < str_len; i++) {
		printf("%c\n", *(str1 + i)); // str1[i]
	}
}

void test31(int arr[]) {
	// *arr++;// 这个没问题。 
	// *arr++;
	// *arr++;
}

void test3() {
	// char数组。 怎么遍历。 
	char str1[] = { 'a', 'z', 'b', 'c', 'f', 'h' };
	char *p = str1; // 

	// 方式2： 使用for循环。  可以使用 *(str1+i)
	int str_len = ARR_LEN(str1);

	for (int i = 0; i < str_len; i++) {
		//printf("%c\n", *(p+i)); // str1[i]
		//printf("%c\n", p[i]); // str1[i]
		printf("%c\n", *p++); // str1[i]

		// printf("%c\n", *str1++); // error
	}
}

void test4() {
	// 如果大家使用指针的时候。 要么 下标偏移； 要么指针偏移。 
	// 不要下标和指针都偏移。 

		// char数组。 怎么遍历。 
	char str1[] = { 'a', 'z', 'b', 'c', 'f', 'h' };
	char *p = str1; // 

	// 方式2： 使用for循环。  可以使用 *(str1+i)
	int str_len = ARR_LEN(str1);

	printf("%c\n", *p++);

	for (int i = 0; i < str_len; i++) {

		printf("%c\n", *p++);
		printf("%c\n", p[i]); // a   z

		// z c
	}
}

int main(void) {

	test1();

	return 0;
}