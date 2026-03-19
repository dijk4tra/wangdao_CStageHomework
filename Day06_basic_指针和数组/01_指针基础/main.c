#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 数组名到底是什么？

    int arr[10] = { 10,11,12,13,13,13,14,15,16,17 };

    // 数组名，从功能看，就是一个指向数组首元素的指针。 

    // 相当于，声明p指针，并且它初始化的时候，和arr指向一个地方。 
    int *p = arr;

    printf("%d\n", *p);

    *p = 666;
    printf("%d\n", *p);
    printf("%d\n", arr[0]);
}

void test2() {
    int a = 10;    // 值:10  地址:0xaaa
    int b = 20;    // 值:20  地址:0xabb

    // p1是一个指针
    int *p1 = &a;  // 值:0xaaa  地址:0xbbb

    // p2是一个指针
    int *p2 = a;   // 值:10     地址:0xbcc

    // p3是一个指针
    int *p3 = p1;  // 值:0xaaa  地址:0xbdd

    // p4是一个指针
    int *p4 = *p1; // 值:10     地址:0xccc

    // p5是一个指针
    int *p5 = &p1; // 值:0xbbb  地址:0xcdd

    // *p1相当于要去p1这个指针指向的地方去处理数据
    // 就是要去 *p1======0xaaa 
    *p1 = 999;
    p1 = p2;

}

void test3() {
    // 一定要注意：值是什么，地址是什么
    // *p1 = 999;
    // p1 = 987; 二者有什么区别
}

void test4() {
    //数组名可以看做是一个指向数组连续空间的首地址
    // 固定指向首元素地址的，不可改变指向的指针
    // 大多数情况下，数组名都可以看作是首指针使用

    char str1[5] = { 'a','a','b','c','c' };
    // 数组，其长度为5

    char *p = str1;

    // 数组名这个指针，不可改变自己的指向
    //str1 = { 'a','a','a' };
    //str1 = NULL;

    p = NULL;
}

int main(void) {
    //test1();
    //test2();

    test4();
    
    return 0;
}