#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
    // 什么叫double free
    // 同一份内存空间，释放了两次

    int *p = malloc(40);

    free(p);
    free(p);
}

void test2() {
    
    int *p = malloc(40);

    test3(p);

    //test4(p);  // 已经在test4函数内部中就free了

    free(p);  //这里又free，出现了double free

}

int main(void) {
    printf("hello world!\n");
    return 0;
}