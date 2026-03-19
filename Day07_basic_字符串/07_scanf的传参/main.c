#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {

	int num = 10;
	// 为什么这里，要写 &num 
	//scanf("%d", num);
	//scanf("%d", &num);

	// change_int_by_int   不对
	// change_int_by_pointer  对的 

	return 0;
}