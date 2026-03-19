#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h> // 补充：用于初始化随机数种子

// 宏定义：自动计算数组元素个数
#define ARR_LEN(arr) (sizeof(arr) / sizeof(arr[0]))

// 宏定义：交换两个元素
// 注意：原代码使用 {} 可能在某些特定语法下报错，建议使用 do...while(0) 封装
#define SWAP(arr, i, j) do { \
    int tmp = arr[i]; \
    arr[i] = arr[j]; \
    arr[j] = tmp; \
} while(0)

/**
 * 打印数组
 */
void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

/**
 * 分区函数 (Partition) - 快速排序的核心
 * 该函数通过“挖坑填补法”将数组分为左右两部分
 * * @param arr   待排序数组
 * @param left  当前处理范围的左边界
 * @param right 当前处理范围的右边界
 */
void pivot(int arr[], int left, int right) {
    // 递归终止条件：当区间只剩一个元素或为空时，停止分区
    if (left >= right) {
        return;
    }

    // --- 性能优化：随机选择枢纽 ---
    // 默认选 left 在处理“近乎有序”的数组时效率会极低。
    // 随机选一个位置与 left 交换，可以保证平均 O(n log n) 的复杂度。
    int rand_idx = left + rand() % (right - left + 1);
    SWAP(arr, left, rand_idx);

    // 确定枢纽值 (Pivot)
    // 此时 arr[left] 的值已被备份到 pivot_value 中，arr[left] 形成第一个“坑”
    int pivot_value = arr[left];
    int cur_l = left;  // 左指针（低位）
    int cur_r = right; // 右指针（高位）

    // 只要左右指针没碰头，就继续移动
    while (cur_l < cur_r) {

        // 1. 从右向左找：寻找第一个比枢纽值【小】的元素
        // 只要右边的数据 >= 枢纽值，就继续向左移动指针
        while (cur_l < cur_r && arr[cur_r] >= pivot_value) {
            cur_r--;
        }
        // 找到后，把这个较小值填入左边的“坑”中
        if (cur_l < cur_r) {
            arr[cur_l] = arr[cur_r];
            // 此时 arr[cur_r] 变成了新的“坑”
        }

        // 2. 从左向右找：寻找第一个比枢纽值【大】的元素
        // 只要左边的数据 <= 枢纽值，就继续向右移动指针
        while (cur_l < cur_r && arr[cur_l] <= pivot_value) {
            cur_l++;
        }
        // 找到后，把这个较大值填入右边的“坑”中
        if (cur_l < cur_r) {
            arr[cur_r] = arr[cur_l];
            // 此时 arr[cur_l] 变成了新的“坑”
        }
    }

    // 3. 填坑归位
    // 当 cur_l == cur_r 时，指针重合的位置就是枢纽值的最终正确位置
    arr[cur_l] = pivot_value;

    // --- 递归分治 ---
    // [left, cur_l - 1]：递归处理枢纽左侧的小元素区
    pivot(arr, left, cur_l - 1);
    // [cur_l + 1, right]：递归处理枢纽右侧的大元素区
    pivot(arr, cur_l + 1, right);
}

/**
 * 快速排序入口
 */
void quick_sort(int arr[], int len) {
    if (len <= 1) return;
    // 初始化随机数种子（仅需初始化一次）
    srand((unsigned int)time(NULL));
    // 开始递归分区
    pivot(arr, 0, len - 1);
}

int main(void) {
    // 原始数据
    int arr[] = { 16, 1, 45, 23, 99, 2, 18, 67, 42, 10 };
    int n = ARR_LEN(arr);

    printf("排序前:\n");
    print_arr(arr, n);
    printf("--------------------------------------------------\n");

    quick_sort(arr, n);

    printf("--------------------------------------------------\n");
    printf("排序后:\n");
    print_arr(arr, n);

    return 0;
}