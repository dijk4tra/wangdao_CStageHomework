#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)/sizeof(arr[0])))

/*
编写函数，查找一个int数组中的最大元素和第二大元素，并将它们分别存放在由 largest 和 second_largest 指向的变量中。
按照下面的函数声明来实现这个函数：
    void find_two_largest(int arr[], int n, int* largest, int* second_largest);
注意：为了简化实现，数组不存在重复元素，请不要考虑存在重复元素的情况。
*/

void find_two_largest(int arr[], int n, int *largest, int *second_largest) {
    // 初始化
    if (arr[0] > arr[1]) {
        *largest = arr[0];
        *second_largest = arr[1];
    }
    else {
        *largest = arr[1];
        *second_largest = arr[0];
    }
    // 从下标2开始遍历剩余元素
    for (int i = 2; i < n; i++) {
        if (arr[i] > *largest) {
            // 当前元素的值比最大值还大，原最大值变为第二大值，更新最大值
            *second_largest = *largest;
            *largest = arr[i];
        }
        else if (arr[i] > *second_largest) {
            // 当前元素的值介于最大值和第二大值之间，仅更新第二大值
            *second_largest = arr[i];
        }
    }
    printf("该数组的最大元素为：%d，第二大元素为：%d\n", *largest, *second_largest);
}


int main(void) {

    int largest = 0;
    int second_largest = 0;

    int arr[20] = { -82, 45, -12, 78, -55, 14, -91, 0, 33, -28, 93, -33, 57, -66, 81,-7, 62, -49, 19, -100 };

    find_two_largest(arr, ARR_LEN(arr), &largest, &second_largest);

    return 0;
}