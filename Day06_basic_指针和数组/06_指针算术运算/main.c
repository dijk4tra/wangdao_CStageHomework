#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void test1() {
    int arr[] = { 10,20,30,40,50,60 };

    int *p = arr;

    //*p++
    // *p++：++优先级高，*优先级低
    // 先返回p的旧指向，再自增
    // ++ 自增，自增多少个字节，和其类型相关

    printf("%d\n", *p++);
    printf("%d\n", *p++);
    printf("%d\n", *p++);
    printf("%d\n", *p++);
    printf("%d\n", *p++);
    printf("%d\n", *p++);

}

void test2() {
    double arr[5] = { 3.14,3.15,3.15,3.16,3.17 };
    double *p1 = arr;

    printf("%lf\n", *p1++);
    printf("%lf\n", *p1++);
    printf("%lf\n", *p1++);
    printf("%lf\n", *p1++);
    printf("%lf\n", *p1++);
    printf("%lf\n", *p1++);

}

void test3() {
    char str1[8] = { 'a', 'b', 'b', 'c', 'd', 'e', 'f','g' };

    char *p1 = str1;

    printf("%d\n", str1[0]);
    printf("%d\n", str1[1]);
    printf("%d\n", str1[2]);

    printf("%d\n", p1[0]);
    printf("%d\n", p1[1]);
    printf("%d\n", p1[2]);

    // 对于，数组来说， 它的 [] 运算符。 其实是一个语法糖。 

    // str1[2] ========= *(str1 + 2)

    printf("--------%d\n", *(p1 + 0));
    printf("--------%d\n", *(p1 + 1));
    printf("--------%d\n", *(p1 + 2));

    printf("========%d\n", *(str1 + 0));
    printf("========%d\n", *(str1 + 1));
    printf("========%d\n", *(str1 + 2));

}

int main(void) {
    
    //test1();
    //test2();
    test3();

    return 0;
}