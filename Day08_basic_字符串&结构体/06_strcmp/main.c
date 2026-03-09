#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test1() {
    char str1[10] = "hello";
    char str2[20] = "hello";

    //字符串比较大小，其实就是比较字符串的内容，而不是地址

    if (str1 == str2) {
        // 不能使用 == 来比较
    }

    // 字符串，什么叫大，什么叫小？遵循字典序
    // abc
    // abc

}

void test2() {
    char str[] = "abc";
    char str2[] = "123";
    char str3[] = "bbb";
    char str4[] = "aaa";
    char str5[] = "abcd";
    char str6[] = "abc";

    printf("%d\n", strcmp(str, str2));
    printf("%d\n", strcmp(str, str3));
    printf("%d\n", strcmp(str, str4));
    printf("%d\n", strcmp(str, str5));
    printf("%d\n", strcmp(str, str6));
}

void test3() {
    // strcmp 用于比较两个字符串内容是否相同
    // 如果相同，返回0. 

    //if (strcmp(str1, str2) == 0) {
        // 如果相同做这个逻辑。 
    //}

}

int main(void) {

    test2();
    return 0;
}