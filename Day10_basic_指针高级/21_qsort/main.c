#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    // qsort就是一个排序，它是C标准库提供的排序
    // 它希望自己，能排序int，能排序double，能排序结构体

    // 排序：关键点在于两个数据如何比较大小
    // qsort中，是怎样知道两个数据，怎样比较大小的？
    // 函数指针
    // int (*compare)(const void *,const void *)
    // 你只要告诉 qsort 两个数据该怎么比

    // 比较两个数据，然后返回正负0，就可以表明两个数据的大小

    // 这个指针是什么东西？它是数据的指针
    // 数组：int arr[] ， 数据：int类型
    // 指针数组：char *argv[]  ， 数据：char * ===> char **
}

int main(void) {
    
    return 0;
}