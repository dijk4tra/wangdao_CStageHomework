#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // zhangsan 可以使用字符数组存储，也可以用指针指向只读数据段
    // lisi
    // wangwu

    // 单个字符串，是字符数组
    // 多个字符串，是字符数组的数组，即二维数组
}

void test2() {
    // 列数不能省略，存储的问题
    // 二维数组是一维数组的数组

    char week_days[][10] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

    // week_days[1];
}

void test3() {
    // 字符指针数组

    // 字符串：字符数组。字符指针

    // 字符串数组：字符指针数组

    // 指针数组
    char *week_days[] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

}

int main(void) {
    
    return 0;
}