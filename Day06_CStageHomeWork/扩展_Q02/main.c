#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

/*
给定一个整数数组，请将所有非正数(包含负数和0)全部移到数组开头，正数则全部移到数组末尾，要求原地完成，不使用额外内存空间。
比如：
    数组[1, -2, 3, 0, -9, 0, 10, 3]
    最终分组完成后的效果应该是[非正数（包含0）, 正数]（稳定性不做要求）
提示：仍然可以基于双指针单向分区或夹逼法求解。
*/



int main(void) {
    
    int arr[] = { 1, -2, 3, 0, -9, 0, 10, 3 };
    int len = ARR_LEN(arr);

    int left = 0;
    int right = len - 1;

    
    while (left < right) {
        // left指针从左向右寻找正数
        while (left < right && arr[left] <= 0) {
            left++;
        }
        // right 指针从右向左寻找负数和0
        while (left < right && arr[right] > 0) {
            right--;
        }
        // 如果left仍在right左侧，说明找到了需要交换的两个元素
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++;
            right--;
        }
    }
    printf("分组后的数组: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}