#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test1() {

    int len;

    len = strlen("abc");    /* len is now 3 */
    len = strlen("");       /* len is now 0 */

    char str[] = "abcd";
    char str2[10] = "12345";
    char str3[5] = { 'a','\0','c' };
    len = strlen(str);      /* len is now 4 */
    len = strlen(str2);     /* len is now 5 */
    len = strlen(str3);     /* len is now 1 */
}

void test2() {
    char str4[4] = "1234";   // str4实际只能存储1234这四个字符,无法表示一个字符串
    int len = strlen(str4);     // str4并不能表示一个字符串,该函数调用会引发未定义行为
}

void test3() {
    // 字符数组和字符串有什么区别

    char str1[] = "abcd";
    char str2[10] = "12345";
    char str3[5] = { 'a','\0','c' };

    // sizeof和strlen的区别(重点)

    printf("%d\n", sizeof(str1)); // 5
    printf("%d\n", strlen(str1)); // 4

    printf("%d\n", sizeof(str2)); // 10
    printf("%d\n", strlen(str2)); // 5

    printf("%d\n", sizeof(str3)); // 5
    printf("%d\n", strlen(str3)); // 1


    char *p = "1234567890";
    printf("%d\n", sizeof(p)); // 4
    printf("%d\n", strlen(p)); // 10

}

size_t my_strlen(const char *src) {
    size_t count = 0; 
    // 遍历直到遇到空字符
    while (*src != '\0') {
        count++;
        src++;
    }
    return count;
}

int main(void) {
    
    //test1();
    //test2();
    test3();

    return 0;
}