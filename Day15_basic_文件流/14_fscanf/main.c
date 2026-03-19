#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // fscanf：输入，从文件中输入
    FILE *fp = fopen("1.txt", "r");
    if (fp == NULL) {
        printf("fopen failed.\n");
        return;
    }

    int num = 0;
    double d1 = 0.0;

    // scanf("%d %lf", &num, &d1);
    fscanf(fp, "%d %lf", &num, &d1);
    // 从文件中输入

    fclose(fp);

}

int main(void) {
    test1();
    return 0;
}