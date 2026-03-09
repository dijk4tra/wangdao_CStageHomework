#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_LEN(arr) ((sizeof(arr)) / (sizeof(arr[0])))

/*
给定两个有序的整数子数组，然后将它们合并到一个足够长的新数组中，合并后的结果数组也应当是有序的。比如：
    数组1：[1, 3, 5, 6, 7]
    数组2：[2, 3, 4, 8]
    合并后的结果数组3：[1, 2, 3, 3, 4, 5, 6, 7, 8]
提示：
    整个合并的过程类似"穿针引线"，利用两个索引逐一比较两个数组的元素大小，然后把较小元素放入数组3中。"穿针引线"结束，最终：
    一定会有一个数组元素被全部被赋值到数组3当中了。
    另一个数组元素一定还有剩余。
    那就把剩余数组的元素全部复制到数组3的后面即可。
*/

void merge(int arr1[], int arr2[], int arr3[], int len1, int len2) {
    int i = 0; // 用于遍历arr1
    int j = 0; // 用于遍历arr2
    int k = 0; // 用于记录arr3的写入位置

    // 两个数组都有剩余元素时，比较大小并将较小的元素填入新数组
    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            arr3[k] = arr1[i];
            i++;
        }
        else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    // 如果arr2先遍历完，接着处理arr1的剩余元素
    while (i < len1) {
        arr3[k] = arr1[i];
        i++;
        k++;
    }

    // 如果arr1先遍历完，接着处理arr2的剩余元素
    while (j < len2) {
        arr3[k] = arr2[j];
        j++;
        k++;
    }


}

int main(void) {

    int arr1[] = {1,3,5,6,7};
    int arr2[] = { 2,3,4,8 };
    int arr3[20] = { 0 };
    
    merge(arr1, arr2, arr3, ARR_LEN(arr1), ARR_LEN(arr2));

    printf("合并后的结果数组3为: ");
    for (int i = 0; i < ARR_LEN(arr1) + ARR_LEN(arr2); i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}