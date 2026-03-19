#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void test1() {
    // strcat：拼接

    char str1[50] = "hello";
    char str2[50] = "world";

    // strcpy(str1, str2);

    printf("%s\n", str1);

    strcat(str1, str2);

    printf("%s\n", str1);

}

void test2() {
    // strcat：就是首先找到dest的'\0'
    // 然后将 src 里面的数据，一个一个拷贝到 dest 里面去（从'\0'位置开始覆盖）

    char str1[20] = "12\0 345678901234567";

    //char str2[5] = "abcd";
    char str2[21] = "abcdabcdabcdabcdabcd";

    strcat(str1, str2);
}

void test3() {
    char src[] = "world";
    char dest[10] = "hello, ";

    //dest[7] = '1';   // 7一定 \0
    dest[8] = '2';
    dest[9] = '3';

    //char *ret = strncat(dest, src, 2);
    //char *ret = strncat(dest, src, 1);
    char *ret = strncat(dest, src, 3);

}

void test4() {
    char src[] = "world";
    char dest[20] = "hello, ";

    dest[8] = '2';
    dest[9] = '3';
    dest[10] = '4';
    dest[11] = '5';
    dest[12] = '6';
    dest[13] = '7';
    dest[14] = '8';

    //char *ret = strncat(dest, src, 3);
    //char *ret = strncat(dest, src, 5);
    //char *ret = strncat(dest, src, 6);
    char *ret = strncat(dest, src, 8);

}

int main(void) {
    //test1();
    //test2();
    //test3();
    test4();

    return 0;
}