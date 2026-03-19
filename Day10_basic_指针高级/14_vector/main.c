#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    // Vector 是C++中提供的一种东西，专门用来存放数据
    
    // 我可以认为这是一个数组
    // 和我们平常的数组的主要的区别是：长度可变

    // 基本思路：使用堆空间，刚开始先申请一段空间，当空间不够用时，再继续申请

    // Vector要存什么信息
    // 1. 指针，用于存放地址，存放堆空间上的地址
    // 2. 容量
    // 3. 当前装了多少数据

    int arr[10];
    int *p = malloc(40);


    return 0;
}