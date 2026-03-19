#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // C语言中，没有一种专门的类型叫字符串
    // C采取的是，使用字符数组来存储。这个字符数组的特殊点在于以‘\0’结尾
    char str1[50] = "hello world";

}

void test2() {
    // str1 是一个字符数组，以 \0 结尾，所以它是字符串
    //char str1[6] = { 'h','e','l','l','o','\0' };

    // 在传递的时候，就直接给首地址
    //printf("%s", str1);

    // str2不能被称之为字符串，因为不是以 \0 结尾的
    char str2[5] = { 'h','e','l','l','o' };
    printf("%s\n", str2);


}

void test3() {
    // 因为C中字符串以 \0结尾。 所以如果字符串确实想存 \0 存不了。

    char str1[10] = { 'h', 'e', 'l', 'L', 'o', '\0', 'a', 'a', 'b', '\0' };

    printf("%s\n", str1);

}

int main(void) {
    
    test1();

    return 0;
}