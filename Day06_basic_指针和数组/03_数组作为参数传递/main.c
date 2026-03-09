#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void test1() {
    //数组作为参数传递的时候，会退化成指向数组首元素的指针
    //也就是，虽然现在我们还是写数组的语法，但是它已经变成了一个指针
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2]);
    arr = NULL;
    //所以，数组传递的时候，已经退化成了指针
}

void test2() {
    // 因为数组在参数传递的过程中，已经退化成了指针
    // 所以，形参部分，有两种写法，都是对的
    // void test2（char str1[])
    // void test2（char *p1)

    // 数组的长度问题
    // sizeof(数组名)/sizeof(数组首元素)
    // 数组的长度，在参数传递过程中，已经被丢掉了
    // 所以，我们如果想在函数内部使用数组，普遍还需要额外传递数组长度

}

void test3() {
    printf("sizeof(str) = %d\n", sizeof(str));
    printf("sizeof(str[0]) = %d\n", sizeof(str[0]));
    printf("sizeof(str)/sizeof(str[0]) = %d\n", sizeof(str) / sizeof(str[0]));

    // 所以，参数部分，一定要带一个长度。 才能正常 完整的处理数组。 
}

void test4() {
    // 传数组的时候，要额外传递一个数组的长度len
}

int main(void) {
    
    int arr[5] = { 10,11,12,12,13 };

    //test1(arr);

    test3(arr);

    return 0;
}