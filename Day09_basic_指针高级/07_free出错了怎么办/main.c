#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test3(int *p) {
    // 现在，free的时候崩溃了，怎么查？
    free(p);
}

void test2(int *p) {
    test3(p + 1);
}

void test1() {
    int *p = malloc(40);

    test2(p);

    // 要顺着数据的链条来查，这个p从哪来，被谁改过，改的是什么？
}


int main(void) {
    
    return 0;
}