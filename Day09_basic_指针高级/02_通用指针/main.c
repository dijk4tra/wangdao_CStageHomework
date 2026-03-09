#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    int arr[] = { 10,20,30,40 };
    int *p = arr;
    // p 是一个int *；解引用后为一个int 变量
    int val = *p + 100;

    char *p2 = arr;
    // p p2 中存储的值，没有任何区别
    // p p2 偏移量不同，对这块空间的理解不同

    int *p1;
    float *p2;
    double *p3;
    long *p4;

    // 指针其实有两个功能
    // 1.存地址
    // 2.存类型

}

void test2() {
    // 通用指针：即这个指针，可以存任意类型的地址
    // void *p
    // void * 只用来存地址。如果涉及到使用，需要强制转回具体的类型

    int arr[5] = { 10,20,30,40,50 };
    
    void *p = arr;

    //int val = *p + 100;   // 回报错

    int *p_int = (int *)p;
    int val = *p_int + 100;

    // p + 1;
}

void test3() {
    // 通用指针，只用来存地址，无法直接使用它
    // 不可解引用*，不可偏移+1
    // 动态内存分配函数中，大量使用了通用指针

    // malloc(2)
    // calloc()
    // free()
}

int main(void) {
    

    return 0;
}