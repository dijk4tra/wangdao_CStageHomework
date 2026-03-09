#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 一定要使用完毕这块空间之后，再free
    // 不要free了之后，再去这块空间取数据

    int *p = malloc(40);

    p[2] = 10;
    p[3] = 11;

    int tmp = p[2];
    free(p);

    p[2]; // 不能捞回来数据。 如果你在free之后，继续拿数据，说明你free早了

    // 如果free没问题，可以在free之前将数据存下来，最后直接用存下来的数据
 
}

void test2() {
    // 关于指针指向的问题
    int *p = malloc(40);
    int *q = malloc(36);

    p = q;
    // 发生了什么？p指向的地址没了。
    // 这样指，p原本的指向就丢掉了，这时候也发生了内存泄漏
    
}

int main(void) {
    
    return 0;
}