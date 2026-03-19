#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char *my_strncpy(char *dest, const char *src, int n);

void test1() {
    // strcpy 就是完成字符串的复制
    char str1[50] = { 0 };

    char str2[] = "123456";

    // str1 = str2;
    // str1 = "876554564";

    char *ret = strcpy(str1, str2);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("ret = %s\n", ret);
    printf("(ret == str1) = %d\n", (ret == str1));
    // ret 在正常情况下，返回的就是 dest
}

void test2() {

    char str1[10] = { 0 };

    char *p1 = "1234567";
    char *ret = strcpy(str1, p1);

    char *p2 = "987654321";
    char *ret2 = strcpy(str1, p2);

    char *p3 = "abcabcabcabcabc";
    char *ret3 = strcpy(str1, p3);

}

void test3() {
    // strcpy 会无脑复制，不会关心能不能装，够不够装
    // 如何不够装，就越界了
    // 所以在使用 strcpy 时，需要注意能不能装，够不够装

    char *p1 = "123456789";
    char *p2 = "000";

    // p1指向只读数据段，所以不要把数据写入到p1中，程序会直接报错
    strcpy(p1, p2);
}

void test4() {
    // strncpy：也是拷贝，但是这里加了一个n，就相当于可以控制复制的个数
    // n 的表现：
    char dest[10] = "1234567890";

    char src[5] = "abcd";

    //strncpy(dest, src, 2);
    //strncpy(dest, src, 4);
    //strncpy(dest, src, 5);
    //strncpy(dest, src, 8);

    my_strncpy(dest, src, 2);
    my_strncpy(dest, src, 4);
    my_strncpy(dest, src, 5);
    my_strncpy(dest, src, 8);

    // n=2 复制了2个字节
    // n=4 复制了4个字节
    // n=5 复制了5个字节
    // n=8 复制了8个字节（str的5个字节+额外写入3个'\0'）

    // n小于 strlen(src) + 1 ,会拷贝n个字节，不会额外补'\0'
    // n等于 strlen(src) + 1 ,会拷贝n个字节，顺便拷贝了'\0'
    // n大于 strlen(src) + 1 ,会拷贝前面的字节，后面的字节直接填充'\0'
}

char *my_strncpy(char *dest, char *src, int n) {
    // 返回值是dest的旧指针
    char *old_dest = dest;

    for (size_t i = 0; i < n; i++) {
        // 要判断当前的src够不够拷贝
        if (*src != '\0') {
            // 说明src还没有到‘\0’
            *dest = *src;
            dest++;
            src++;
        }
        else {
            *dest == '\0';
        }
    }
}


int main(void) {
    //test1();
    //test2();
    //test3();

    test4();

    return 0;
}