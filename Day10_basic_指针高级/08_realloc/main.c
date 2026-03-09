#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
    // realloc 用于将已经得到的空间，变大或缩小
    // 扩容有两种情况：原地扩容，在新空间扩容
    // 新空间扩容时，realloc 会将数据复制过去
}

void test2() {
    char *p = malloc(40);

    // if

    // ……

    p = realloc(p, 60);
    // 这样有问题，申请内存，有可能会失败
    // 失败的时候，会返回NULL，而且并不会直接free掉原本申请的内存空间
}

void test3() {
    char *p = malloc(40);

    // if

    // ……

    char * new_p = realloc(p, 60);
    if (new_p == NULL) {
        // 说明失败了
        printf("realloc failed.\n");
        free(p);
        return;
    }
    p = new_p;
}

int main(void) {
    
    return 0;
}