#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // printf：输出，屏幕输出
    // scanf：输入，从键盘输入

    // sprintf：输出，往字符串输出
    // sscanf：输入，往字符串输入

    // fprintf：输出，往文件中，以字符串形式输出
    // fscanf：输入，从文件中输入，按照某种方式解析

    FILE *fp = fopen("1.txt", "w");
    if (fp == NULL) {
        printf("fopen failed.");
        return;
    }

    fprintf(fp, "%d %d-------%lf", 10, 111, 3.666);

    fclose(fp);
}

int main(void) {
    test1();
    return 0;
}