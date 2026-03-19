#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 数组名，在两种情况下，不能当作首指针看
    // sizeof的时候
    char str1[5] = {'a','a','c','d','e'};

    sizeof(str1); // 得到的是数组占据空间的大小
    // 如果str1这时候当作首指针，得到的应该是指针的大小
    printf("%d\n", sizeof(str1));

    char *p = str1;
    printf("%d\n", sizeof(p)); // 这时候打印出的是指针p的大小
    // 指针p的大小和程序的位数有关，x86则为32位，x64则为64位

}

void test2() {
    char str1[5] = { 'a','a','c','d','e' };

    //int *p1 = str1; // str1当成指针时，是首元素的指针

    int *p1 = &str1; // str1取地址的类型是整个数组的指针
    
}

int main(void) {
    test2();
    return 0;
}