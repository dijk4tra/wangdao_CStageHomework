#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	// 如果在代码中，写一个 \n

	char ch = '\n';

	// Windows中的换行符：\r\n 
	// C中的换行符：\n


	// 在代码中，fputc('\n') 最终存储到文件(Windows)中，会存储 \r\n
	// 如果读的时候， 会将 \r\n----> \n

	FILE *fp = fopen("1.txt", "w");

	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc('\n', fp);
	fputc('d', fp);
	fputc('d', fp);

	fclose(fp);
}

void test2() {
	FILE *fp = fopen("1.txt", "r");

	int ch;
	while ((ch = fgetc(fp)) != -1) {
		printf("========%d========%c\n", ch, ch);
	}

	fclose(fp);
}

int main(void) {
	
	//test1();
	test2();

    return 0;
}