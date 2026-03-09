#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // 什么是 \0

    // ch1里面存的是字符 0 的ASCII码值 48
    char ch1 = '0';

    // ch2里面存的 0 是数字 0
    char ch1 = 0;

    // ch3里面存的是 0 ，\0 就表示ASCII是 0 值
    char ch3 = '\0';
}

void test2() {
    char str1[5] = { 'h','e','l','l','0' };
    // str1不是字符串，它只是字符数组

    char str2[5] = { 'h','e','l','l','\0' };

    char str3[5] = { 'h','e','l','l',0 };

    char str4[6] = { 'h','e','l','l','0' };
}


int main(void) {
    //test1();
    test2();
    return 0;
}