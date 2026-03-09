#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	char *p = "abcdef";

	// p指向只读数据段。 

	while (*p != '\0') {
		//printf("--------%c\n", *p++);
		// 现在假设，要判断一下，如果是 a字符，打印a两下。 其他情况打印一下。 
		//if (*p++ == 'a') {
		//	printf("--------%c----%c\n", *p++, *p++);
		//}

		char ch = *p++;
		if (ch == 'a') {
			printf("--------%c----%c\n", ch, ch);
		}

	}

}


int main(void) {

	test1();

	return 0;
}