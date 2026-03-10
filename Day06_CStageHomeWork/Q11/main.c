#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)/sizeof(arr[0])))

/*
第一题：
查找数组的最大值和最小值，但要将最大值作为返回值返回，最小值则依靠传入的指针完成赋值。
要求不能使用"[]"运算符。
函数的声明如下：
    int max_min(int *arr, int len, int *pmin);

第二题：
求平均值，给定一个double数组，求平均值，并且返回。
要求使用while循环遍历数组，然后配合"*p++"的语法实现。
函数的声明如下：
    double get_ave(double *arr, int len);
*/

int max_min(int *arr, int len, int *pmin) {
    int max = *arr;
    int min = *arr;

    for (int i = 1; i < len; i++) {
        if (*arr + i > max) {
            max = *arr + i;
        }
        if (*arr + i < min) {
            min = *arr + i;
        }
    }

    printf("最小值为%d，最大值为%d\n", min, max);
    *pmin = min;
    return max;

}

double get_ave(double *arr, int len) {
    int i = 0;
    double sum = 0;
    double average = 0;

    while (i < len) {
        sum += *arr++;
        i++;
    }
    average = sum / len;
    printf("该数组中元素的平均值为：%lf\n", average);
    return average;
}


int main(void) {
    int arr1[5] = { 1,2,3,4,5 };
    int min = 0;
    int *p = &min;

    //max_min(arr1, ARR_LEN(arr1), p);

    double arr2[5] = { 1.1,2.2,3.3,4.4,5.5 };
    get_ave(arr2, ARR_LEN(arr2));

    
    return 0;
}