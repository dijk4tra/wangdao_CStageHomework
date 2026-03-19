#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 数组初始化的方式
    // 1. 完整初始化
    // 2. 部分初始化
    // 3. 全部初始化为0

    int arr[8] = { 1,2,3,4,5,6,7,8 };
    char str1[5] = { 'a','b','c','d','e' };

    int arr2[] = { 1,2,3,4,5 }; // 数组长度自动设置为5

    int arr3[5] = { 1,2,3 }; // 部分初始化，其余元素的值会被设置为0
}

void test2() {
    int arr[10] = { 0 }; // 全部元素为0的初始化

    //int arr2[10] = {}; // 初始化时，{}内不能不给出任何元素
}

void test3() {
    //int arr[5] = { 1,2,3,4,5,6 }; // 初始化包含了比数组长度更多的元素

    //int arr2[8];

    // 在C语言中，不允许数组长度是0或负数
    //char str1[0];
    //char str2[-5];
    //char str3[] = {};
}

void test4() {
    // 数组元素的读和修改
    int arr[10] = { 10,20,30,40,50,60,70,80,90,100 };

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[9]);

    arr[0] = 777;
    arr[1] = 888;
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);

}



int main(void) {
    
    test4();

    return 0;
}