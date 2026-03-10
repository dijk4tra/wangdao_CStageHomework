#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 宏定义：计算数组长度
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换两个元素的值（虽然归并排序主要使用覆盖而非交换，但在某些场景下很有用）
#define SWAP(arr, i, j) { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
}

/**
 * 打印数组内容
 * @param arr 目标数组
 * @param len 数组长度
 */
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/**
 * 合并两个已排序的子区间
 * 逻辑：将 arr[left...mid] 和 arr[mid+1...right] 合并并存入 tmp，最后写回 arr
 */
void merge_left_and_right(int arr[], int left, int mid, int right, int tmp[]) {
    int cur_l = left;      // 左侧子序列的起始游标
    int cur_r = mid + 1;   // 右侧子序列的起始游标
    int total_index = left; // 临时数组 tmp 的写入游标，这里选择与原数组下标同步

    /* * 步骤 1: 比较左右两个子序列，按升序择优放入 tmp
     * 只要其中一个序列跑完了，循环就停止
     */
    while (cur_l <= mid && cur_r <= right) {
        if (arr[cur_l] <= arr[cur_r]) { // 使用 <= 保证排序的稳定性
            tmp[total_index++] = arr[cur_l++];
        }
        else {
            tmp[total_index++] = arr[cur_r++];
        }
    }

    /* * 步骤 2: 将剩余未放完的元素直接追加到 tmp 尾部
     * 以下两个 while 只会执行其中一个
     */
    while (cur_l <= mid) { // 处理左序列剩余部分
        tmp[total_index++] = arr[cur_l++];
    }
    while (cur_r <= right) { // 处理右序列剩余部分
        tmp[total_index++] = arr[cur_r++];
    }

    /* * 步骤 3: 将合并后的有序结果从临时数组 tmp 拷贝回原数组 arr
     * 范围是 [left, right]
     */
    for (int i = left; i <= right; i++) {
        arr[i] = tmp[i];
    }
}

/**
 * 递归拆分并触发合并
 * @param arr 待排序数组
 * @param left 当前区间的左边界
 * @param right 当前区间的右边界
 * @param tmp 辅助空间（由外部一次性申请，避免递归内频繁申请内存）
 */
void divide_and_merge(int arr[], int left, int right, int *tmp) {
    // 递归终止条件：当区间只有一个元素或为空时，无需再拆分
    if (left >= right) {
        return;
    }

    // 计算中间位置，防止溢出的写法：int mid = left + (right - left) / 2;
    int mid = (left + right) / 2;

    /* 分：向左递归拆分，向右递归拆分 */
    divide_and_merge(arr, left, mid, tmp);      // 排序左半部分
    divide_and_merge(arr, mid + 1, right, tmp); // 排序右半部分

    /* 治：将两个有序的子部分合并 */
    merge_left_and_right(arr, left, mid, right, tmp);
}

/**
 * 归并排序入口函数
 */
void merge_sort(int arr[], int len) {
    if (arr == NULL || len <= 1) return;

    // 1. 申请一个与原数组等大的辅助空间，用于合并过程中的数据暂存
    // 使用 calloc 会自动初始化为0，也可使用 malloc
    int *tmp = (int *)calloc(len, sizeof(int));
    if (tmp == NULL) {
        perror("内存分配失败");
        return;
    }

    // 2. 进入递归拆分与合并流程
    divide_and_merge(arr, 0, len - 1, tmp);

    // 3. 释放辅助空间，防止内存泄漏
    free(tmp);
}

int main(void) {
    // 初始化测试数据
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int len = ARR_LEN(arr);

    printf("--- 排序前 ---\n");
    print_arr(arr, len);

    // 执行归并排序
    merge_sort(arr, len);

    printf("\n--- 排序后 ---\n");
    print_arr(arr, len);

    return 0;
}