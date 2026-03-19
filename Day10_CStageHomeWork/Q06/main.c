#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
在main函数中定义两个局部变量：

int a = 10;
int b = 20;
请实现以下两个函数，用于完成局部变量a和b的交换：

void swap(int *pa, int *pb);
void swap2(int **pa, int **pb);
这两个函数都应该可以实现交换a和b的值。
*/

void swap(int *pa, int *pb) {
    int temp;       // 用于暂存数据的临时变量
    temp = *pa;     // 把 pa 指向的内容（即变量a的值）赋给 temp
    *pa = *pb;      // 把 pb 指向的内容（即变量b的值）赋给 pa 指向的空间
    *pb = temp;     // 把 temp 的值赋给 pb 指向的空间
}

void swap2(int **pa, int **pb) {
    int temp;
    temp = **pa;
    **pa = **pb;
    **pb = temp;
}


int main(void) {
    int a = 10;
    int b = 20;

    printf("初始状态：a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("通过swap交换后：a = %d, b = %d\n", a, b);

    int *p1 = &a;
    int *p2 = &b;

    swap2(&p1, &p2);
    printf("再通过swap2交换后：a = %d, b = %d\n", a, b);


    return 0;
}