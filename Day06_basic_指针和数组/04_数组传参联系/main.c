#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void point_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        // [0,len-1]
        printf("");
    }

    //for (int i = 0; i < ARR_LEN(arr); i++) {
    //	printf("============%d\n", arr[i]);
    //}

}

void test1() {
    // 有一个数组，需要你写一个函数。 打印它里面的内容。 
    int arr[10] = { 10,10,12,13,14,15,15,16,16,17 };

    //print_arr(arr, 10);
    print_arr(arr, ARR_LEN(arr));

    // ARR_LEN  如果和数组声明再一个函数内部。 是可以用的。 
}

void print_and_set(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("--------------%d\n", arr[i]);
        arr[i] = 100 + arr[i];
    }
}

void test2() {
    // 传递一个数组，打印这个数组中的值。 并且将数组中的数据修改位 +100

    // 10 20 30 30 40 50 60 
    // 110  120  130  130  140   150  160

    int arr[] = { 10,20,30,30,40,50,60 };
    print_and_set(arr, ARR_LEN(arr));

    print_arr(arr, ARR_LEN(arr));

    // 因为数组传递的时候，会退化成首指针。 
    // 首指针，其实是指向别处的， 所以，在函数内部访问/修改的数据，其实都是别处的数据
    // 函数内部，只是拿到了一块空间的地址。

}

int main(void) {
    //test1();
    test2();

    return 0;
}