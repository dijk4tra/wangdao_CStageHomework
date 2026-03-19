#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
	FILE *fp = fopen("1.txt", "w");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}

	fputc('a', fp);
	fputc('b', fp);
	fputc('c', fp);
	fputc('d', fp);
	fputc('\n', fp);
	fputc('e', fp);
	fputc('f', fp);
	fputc('g', fp);

	fclose(fp);
}


int main(void) {
	test1();

	return 0;
}