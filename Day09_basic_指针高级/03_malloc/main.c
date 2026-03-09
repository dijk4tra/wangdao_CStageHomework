#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void test1() {
    void *p = malloc(10 * sizeof(int));

    // 这个就代表从堆区中申请了 40 个字节
    // 返回值表明，申请到的地址是什么
    // 这块空间是连续的，所以它只告诉了你首地址

    // 返回值有两种情况
    // 1.得到一个地址（非NULL），表明申请成功
    // 2.得到一个NULL，表明申请失败

}

void test2() {
    // 动态内存申请的标准步骤

    // 1.申请空间
    void *p = malloc(10 * sizeof(int));
    // 2.判断是否申请成功
    if (p == NULL) {
        printf("malloc failed.\n");
        return;
    }
    // 3.使用
    // 直接当数组使用
    // p[0] = 0; // 不能直接使用
    int *p_int = (int *)p;
    for (int i = 0; i < 10; i++) {
        p_int[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("-------%d\n", p_int[i]);
    }
    
    // 4.释放
    free(p);
}

void test3() {
    // 现在，要申请20个char，怎么写？
    // void *p = malloc(20 * sizeof(char));
    // 这里可以直接这样写，就省下了后续再对指针进行类型转换的步骤
    char *p = malloc(20 * sizeof(char));
    // C语言有隐式类型转换，会将void * 转换为char *

    if (p == NULL) {
        printf("malloc failed.");
        return;
    }

    for (int i = 0; i < 20; i++) {
        p[i] = 'a' + i;
    }

    for (int i = 0; i < 20; i++) {
        printf("%c-------\n", p[i]);
    }
    // 内存是连续的
    // char *p = malloc(20 * sizeof(char));
    // 该代码在内存中做了什么？
}

void test4() {
    // malloc 怎么找到，你申请的是int，是char，还是double？
    
    // float *p = malloc(40);
    int *p = malloc(40);

    // malloc 怎么找到你申请的是int？
    // malloc 不知道，也不关心。程序员需要知道和关心
    // 程序员通过指针告诉它，需要怎样对待这块申请到的内存

    if (p == NULL) {
        printf("malloc failed.");
        return;
    }

    for (int i = 0; i < 10; i++) {
        p[i] = i + 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("-------%d\n", p[i]);
    }

}

int main(void) {
    
    //test2();
    //test3();
    test4();

    return 0;
}