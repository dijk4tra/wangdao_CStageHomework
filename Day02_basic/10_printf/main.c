#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 输出的时候，使用什么输出即可。  
	// 对于后端程序员来说，基本不需要大家做各种各样奇奇怪怪的格式化。 
	printf("|%4f|\n", 3.14159f);
	printf("|%10f|\n", 3.14159f);
	printf("|%.4f|\n", 3.14159f);
	printf("|%4.1f|\n", 3.14159f);
	printf("|%04.1f|\n", 3.14159f);
	printf("|% 4.1f|\n", 3.14159f);
	printf("|%-4.1f|\n", 3.14159f);
	printf("|%+4.1f|\n", 3.14159f);

	// stdout;
	// stdin;

	return 0;
}