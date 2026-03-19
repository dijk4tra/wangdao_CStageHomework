#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
	// fgets ： 从文件中读取数据，将数据存储到指针指向的空间。 count用于标识最多存多少。
	FILE *fp = fopen("1.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}
	char buf[50] = { 0 };
	char *ret = fgets(buf, 5, fp);

	//fgets()  reads  in at most one less than size characters from stream and
	//stores them into the buffer pointed to by s.Reading stops after an EOF
	//or a  newline.If a newline is read, it is stored into the buffer.A
	//terminating null byte('\0') is stored after the last character  in  the
	//buffer.

	// RETURN VALUE
	// fgets() returns s on success, and NULL on error or when end of file  oc‐
	// curs while no characters have been read.

	printf("%s\n", buf);
}


void test2() {
	FILE *fp = fopen("1.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}
	char buf[5] = { 0 };
	char *ret1 = fgets(buf, 5, fp);
	char *ret2 = fgets(buf, 5, fp);
	char *ret3 = fgets(buf, 5, fp);
	char *ret4 = fgets(buf, 5, fp);
	char *ret5 = fgets(buf, 5, fp);
	char *ret6 = fgets(buf, 5, fp);

	// fgets 用buf装数据，最多装 count -1 个。 因为最后一个用于装 \0
	// 返回值。 如果读到了数据， 返回buf 这个指针。 
	// 如果没读到。 返回NULL。 
}

void test3() {
	FILE *fp = fopen("1.txt", "r");

	if (fp == NULL) {
		printf("fopen failed.\n");
		return;
	}
	char buf[5] = { 0 };

	char *ret = NULL;
	while ((ret = fgets(buf, sizeof(buf), fp)) != NULL) {
		printf("-----%s----\n", buf);
	}
	fclose(fp);
}

int main(void) {
	//test1();
	//test2();
	test3();
	return 0;
}